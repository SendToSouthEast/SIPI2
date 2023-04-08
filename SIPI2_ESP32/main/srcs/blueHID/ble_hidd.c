/* This example code is in the Public Domain (or CC0 licensed, at your option.)
   Unless required by applicable law or agreed to in writing, this software is
   distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_bt.h"

#include "esp_hidd_prf_api.h"
#include "esp_bt_defs.h"
#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_gatt_defs.h"
#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "driver/gpio.h"
#include "hid_dev.h"


#include "sdkconfig.h"
/**
 * Brief:
 * This example Implemented BLE HID device profile related functions, in which the HID device
 * has 4 Reports (1 is mouse, 2 is keyboard and LED, 3 is Consumer Devices, 4 is Vendor devices).
 * Users can choose different reports according to their own application scenarios.
 * BLE HID profile inheritance and USB HID class.
 */

/**
 * Note:
 * 1. Win10 does not support vendor report , So SUPPORT_REPORT_VENDOR is always set to FALSE, it defines in hidd_le_prf_int.h
 * 2. Update connection parameters are not allowed during iPhone HID encryption, slave turns
 * off the ability to automatically update connection parameters during encryption.
 * 3. After our HID device is connected, the iPhones write 1 to the Report Characteristic Configuration Descriptor,
 * even if the HID encryption is not completed. This should actually be written 1 after the HID encryption is completed.
 * we modify the permissions of the Report Characteristic Configuration Descriptor to `ESP_GATT_PERM_READ | ESP_GATT_PERM_WRITE_ENCRYPTED`.
 * if you got `GATT_INSUF_ENCRYPTION` error, please ignore.
 */

#define BLUE_HID_TAG "SIPI2_BLE"


static uint16_t hid_conn_id = 0;
static bool sec_conn = false;
#define CHAR_DECLARATION_SIZE   (sizeof(uint8_t))

static void hidd_event_callback(esp_hidd_cb_event_t event, esp_hidd_cb_param_t *param);

static uint8_t hidd_service_uuid128[] = {
    /* LSB <--------------------------------------------------------------------------------> MSB */
    //first uuid, 16bit, [12],[13] is the value
    0xfb, 0x34, 0x9b, 0x5f, 0x80, 0x00, 0x00, 0x80, 0x00, 0x10, 0x00, 0x00, 0x12, 0x18, 0x00, 0x00,
};

static esp_ble_adv_data_t hidd_adv_data = {
    .set_scan_rsp = false,
    .include_name = true,
    .include_txpower = true,
    .min_interval = 0x0006, //slave connection min interval, Time = min_interval * 1.25 msec
    .max_interval = 0x0010, //slave connection max interval, Time = max_interval * 1.25 msec
    .appearance = 0x03c0,       //HID Generic,
    .manufacturer_len = 0,
    .p_manufacturer_data =  NULL,
    .service_data_len = 0,
    .p_service_data = NULL,
    .service_uuid_len = sizeof(hidd_service_uuid128),
    .p_service_uuid = hidd_service_uuid128,
    .flag = 0x6,
};

static esp_ble_adv_params_t hidd_adv_params = {
    .adv_int_min        = 0x20,
    .adv_int_max        = 0x30,
    .adv_type           = ADV_TYPE_IND,
    .own_addr_type      = BLE_ADDR_TYPE_PUBLIC,
    //.peer_addr            =
    //.peer_addr_type       =
    .channel_map        = ADV_CHNL_ALL,
    .adv_filter_policy = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};


static void hidd_event_callback(esp_hidd_cb_event_t event, esp_hidd_cb_param_t *param)
{
    switch(event) {
        case ESP_HIDD_EVENT_REG_FINISH: {
            if (param->init_finish.state == ESP_HIDD_INIT_OK) {
                //esp_bd_addr_t rand_addr = {0x04,0x11,0x11,0x11,0x11,0x05};
                esp_ble_gap_set_device_name(CONFIG_BLUE_HID_DEVICE_NAME);
                esp_ble_gap_config_adv_data(&hidd_adv_data);

            }
            break;
        }
        case ESP_BAT_EVENT_REG: {
            break;
        }
        case ESP_HIDD_EVENT_DEINIT_FINISH:
	     break;
		case ESP_HIDD_EVENT_BLE_CONNECT: {
            ESP_LOGI(BLUE_HID_TAG, "ESP_HIDD_EVENT_BLE_CONNECT");
            hid_conn_id = param->connect.conn_id;
            break;
        }
        case ESP_HIDD_EVENT_BLE_DISCONNECT: {
            sec_conn = false;
            ESP_LOGI(BLUE_HID_TAG, "ESP_HIDD_EVENT_BLE_DISCONNECT");
            esp_ble_gap_start_advertising(&hidd_adv_params);
            break;
        }
        case ESP_HIDD_EVENT_BLE_VENDOR_REPORT_WRITE_EVT: {
            ESP_LOGI(BLUE_HID_TAG, "%s, ESP_HIDD_EVENT_BLE_VENDOR_REPORT_WRITE_EVT", __func__);
            ESP_LOG_BUFFER_HEX(BLUE_HID_TAG, param->vendor_write.data, param->vendor_write.length);
        }
        default:
            break;
    }
    return;
}

static void gap_event_handler(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param)
{
    switch (event) {
    case ESP_GAP_BLE_ADV_DATA_SET_COMPLETE_EVT:
        esp_ble_gap_start_advertising(&hidd_adv_params);
        break;
     case ESP_GAP_BLE_SEC_REQ_EVT:
        for(int i = 0; i < ESP_BD_ADDR_LEN; i++) {
             ESP_LOGD(BLUE_HID_TAG, "%x:",param->ble_security.ble_req.bd_addr[i]);
        }
        esp_ble_gap_security_rsp(param->ble_security.ble_req.bd_addr, true);
	 break;
     case ESP_GAP_BLE_AUTH_CMPL_EVT:
        sec_conn = true;
        esp_bd_addr_t bd_addr;
        memcpy(bd_addr, param->ble_security.auth_cmpl.bd_addr, sizeof(esp_bd_addr_t));
        ESP_LOGI(BLUE_HID_TAG, "remote BD_ADDR: %08x%04x",\
                (bd_addr[0] << 24) + (bd_addr[1] << 16) + (bd_addr[2] << 8) + bd_addr[3],
                (bd_addr[4] << 8) + bd_addr[5]);
        ESP_LOGI(BLUE_HID_TAG, "address type = %d", param->ble_security.auth_cmpl.addr_type);
        ESP_LOGI(BLUE_HID_TAG, "pair status = %s",param->ble_security.auth_cmpl.success ? "success" : "fail");
        if(!param->ble_security.auth_cmpl.success) {
            ESP_LOGE(BLUE_HID_TAG, "fail reason = 0x%x",param->ble_security.auth_cmpl.fail_reason);
        }
        break;
    default:
        break;
    }
}

uint8_t blueHIDKeyChange(char inputCharOrigin,bool * shiftFlag){
    uint8_t key_vaule;
    *shiftFlag = 0;
    if(inputCharOrigin == '0') key_vaule = HID_KEY_0;
    else if(inputCharOrigin == '1') key_vaule = HID_KEY_1;
    else if(inputCharOrigin == '2') key_vaule = HID_KEY_2;
    else if(inputCharOrigin == '3') key_vaule = HID_KEY_3;
    else if(inputCharOrigin == '4') key_vaule = HID_KEY_4;
    else if(inputCharOrigin == '5') key_vaule = HID_KEY_5;
    else if(inputCharOrigin == '6') key_vaule = HID_KEY_6;
    else if(inputCharOrigin == '7') key_vaule = HID_KEY_7;
    else if(inputCharOrigin == '8') key_vaule = HID_KEY_8;
    else if(inputCharOrigin == '9') key_vaule = HID_KEY_9;
    else if(inputCharOrigin == 'A') key_vaule = HID_KEY_A;
    else if(inputCharOrigin == 'B') key_vaule = HID_KEY_B;
    else if(inputCharOrigin == 'C') key_vaule = HID_KEY_C;
    else if(inputCharOrigin == 'D') key_vaule = HID_KEY_D;
    else if(inputCharOrigin == 'E') key_vaule = HID_KEY_E;
    else if(inputCharOrigin == 'F') key_vaule = HID_KEY_F;
    else if(inputCharOrigin == 'G') key_vaule = HID_KEY_G;
    else if(inputCharOrigin == 'H') key_vaule = HID_KEY_H;
    else if(inputCharOrigin == 'I') key_vaule = HID_KEY_I;
    else if(inputCharOrigin == 'J') key_vaule = HID_KEY_J;
    else if(inputCharOrigin == 'K') key_vaule = HID_KEY_K;
    else if(inputCharOrigin == 'L') key_vaule = HID_KEY_L;
    else if(inputCharOrigin == 'M') key_vaule = HID_KEY_M;
    else if(inputCharOrigin == 'N') key_vaule = HID_KEY_N;
    else if(inputCharOrigin == 'O') key_vaule = HID_KEY_O;
    else if(inputCharOrigin == 'P') key_vaule = HID_KEY_P;
    else if(inputCharOrigin == 'Q') key_vaule = HID_KEY_Q;
    else if(inputCharOrigin == 'R') key_vaule = HID_KEY_R;
    else if(inputCharOrigin == 'S') key_vaule = HID_KEY_S;
    else if(inputCharOrigin == 'T') key_vaule = HID_KEY_T;
    else if(inputCharOrigin == 'U') key_vaule = HID_KEY_U;
    else if(inputCharOrigin == 'V') key_vaule = HID_KEY_V;
    else if(inputCharOrigin == 'W') key_vaule = HID_KEY_W;
    else if(inputCharOrigin == 'X') key_vaule = HID_KEY_X;
    else if(inputCharOrigin == 'Y') key_vaule = HID_KEY_Y;
    else if(inputCharOrigin == 'Z') key_vaule = HID_KEY_Z;

    else if(inputCharOrigin == 'a') key_vaule = HID_KEY_A;
    else if(inputCharOrigin == 'b') key_vaule = HID_KEY_B;
    else if(inputCharOrigin == 'c') key_vaule = HID_KEY_C;
    else if(inputCharOrigin == 'd') key_vaule = HID_KEY_D;
    else if(inputCharOrigin == 'e') key_vaule = HID_KEY_E;
    else if(inputCharOrigin == 'f') key_vaule = HID_KEY_F;
    else if(inputCharOrigin == 'g') key_vaule = HID_KEY_G;
    else if(inputCharOrigin == 'h') key_vaule = HID_KEY_H;
    else if(inputCharOrigin == 'i') key_vaule = HID_KEY_I;
    else if(inputCharOrigin == 'j') key_vaule = HID_KEY_J;
    else if(inputCharOrigin == 'k') key_vaule = HID_KEY_K;
    else if(inputCharOrigin == 'l') key_vaule = HID_KEY_L;
    else if(inputCharOrigin == 'm') key_vaule = HID_KEY_M;
    else if(inputCharOrigin == 'n') key_vaule = HID_KEY_N;
    else if(inputCharOrigin == 'o') key_vaule = HID_KEY_O;
    else if(inputCharOrigin == 'p') key_vaule = HID_KEY_P;
    else if(inputCharOrigin == 'q') key_vaule = HID_KEY_Q;
    else if(inputCharOrigin == 'r') key_vaule = HID_KEY_R;
    else if(inputCharOrigin == 's') key_vaule = HID_KEY_S;
    else if(inputCharOrigin == 't') key_vaule = HID_KEY_T;
    else if(inputCharOrigin == 'u') key_vaule = HID_KEY_U;
    else if(inputCharOrigin == 'v') key_vaule = HID_KEY_V;
    else if(inputCharOrigin == 'w') key_vaule = HID_KEY_W;
    else if(inputCharOrigin == 'x') key_vaule = HID_KEY_X;
    else if(inputCharOrigin == 'y') key_vaule = HID_KEY_Y;
    else if(inputCharOrigin == 'z') key_vaule = HID_KEY_Z;

    //0x01 NONE
    //0x02 NUM
    //0x03 ALT
    //0x04 UPPER
    //0x05 CTRL
    //0x06 SHIFT
    //0x07 ENTER
    //0x08 DELETE
    //0x09 YES
    //0x10 No
    else if(inputCharOrigin == '#') key_vaule = HID_KEY_3;
    else if(inputCharOrigin == '(') { key_vaule = HID_KEY_9; *shiftFlag = 1; }
    else if(inputCharOrigin == ')') { key_vaule = HID_KEY_0; *shiftFlag = 1; }
    else if(inputCharOrigin == '_') { key_vaule = HID_KEY_MINUS; *shiftFlag = 1; }
    else if(inputCharOrigin == '-') key_vaule = HID_KEY_MINUS;
    else if(inputCharOrigin == '+') { key_vaule = HID_KEY_EQUAL; *shiftFlag = 1; }
    else if(inputCharOrigin == '@') { key_vaule = HID_KEY_2; *shiftFlag = 1; }
    else if(inputCharOrigin == '*') { key_vaule = HID_KEY_8; *shiftFlag = 1; }
    else if(inputCharOrigin == '/') key_vaule = HID_KEY_FWD_SLASH;
    else if(inputCharOrigin == ':') { key_vaule = HID_KEY_SEMI_COLON; *shiftFlag = 1; }
    else if(inputCharOrigin == ';') key_vaule = HID_KEY_SEMI_COLON;
    else if(inputCharOrigin == '\'') key_vaule = HID_KEY_SGL_QUOTE;
    else if(inputCharOrigin == '\"') { key_vaule = HID_KEY_GRV_ACCENT; *shiftFlag = 1; }
    else if(inputCharOrigin == '?') { key_vaule = HID_KEY_FWD_SLASH; *shiftFlag = 1; }
    else if(inputCharOrigin == '!') { key_vaule = HID_KEY_1; *shiftFlag = 1; }
    else if(inputCharOrigin == ',') key_vaule = HID_KEY_COMMA;
    else if(inputCharOrigin == '.') key_vaule = HID_KEY_DOT;
    else if(inputCharOrigin == '\\') key_vaule = HID_KEY_BACK_SLASH;
    else if(inputCharOrigin == '~') { key_vaule = HID_KEY_GRV_ACCENT; *shiftFlag = 1; }



    else if(inputCharOrigin == 0x00) key_vaule = HID_KEY_DELETE;
    //else if(inputCharOrigin == 0x05) key_vaule = HID_KEY_LEFT_CTRL;
    else if(inputCharOrigin == 0x05) key_vaule = HID_KEY_PRNT_SCREEN;
    else if(inputCharOrigin == 0x06) key_vaule = HID_KEY_LEFT_SHIFT;
    else if(inputCharOrigin == '\n') key_vaule = HID_KEY_ENTER;
    return key_vaule;
}
void blueHIDClickKey(char inputCharOrigin){
    bool shiftFlag = 0;
    uint8_t key_vaule = blueHIDKeyChange(inputCharOrigin, &shiftFlag);
    ESP_LOGI(BLUE_HID_TAG, "sended，%c,%d",inputCharOrigin,key_vaule);
     uint8_t key_vaule2 = {HID_KEY_RESERVED};
    if(shiftFlag){
        uint8_t key_vaule_shift = HID_KEY_LEFT_SHIFT;
        esp_hidd_send_keyboard_value(hid_conn_id, 0, &key_vaule_shift, 1);
        vTaskDelay(20 / portTICK_PERIOD_MS);
        esp_hidd_send_keyboard_value(hid_conn_id, 0, &key_vaule, 1);
        vTaskDelay(20 / portTICK_PERIOD_MS);
        esp_hidd_send_keyboard_value(hid_conn_id, 0, &key_vaule2, 1);
    }
    else{
        esp_hidd_send_keyboard_value(hid_conn_id, 0, &key_vaule, 1);
        vTaskDelay(20 / portTICK_PERIOD_MS);
        esp_hidd_send_keyboard_value(hid_conn_id, 0, &key_vaule2, 1);
    }
}




void blueHIDInit(void)
{
    esp_err_t ret;

    // Initialize NVS.
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );

    ESP_ERROR_CHECK(esp_bt_controller_mem_release(ESP_BT_MODE_CLASSIC_BT));

    esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
    ret = esp_bt_controller_init(&bt_cfg);
    if (ret) {
        ESP_LOGE(BLUE_HID_TAG, "%s initialize controller failed\n", __func__);
        return;
    }

    ret = esp_bt_controller_enable(ESP_BT_MODE_BLE);
    if (ret) {
        ESP_LOGE(BLUE_HID_TAG, "%s enable controller failed\n", __func__);
        return;
    }

    ret = esp_bluedroid_init();
    if (ret) {
        ESP_LOGE(BLUE_HID_TAG, "%s init bluedroid failed\n", __func__);
        return;
    }

    ret = esp_bluedroid_enable();
    if (ret) {
        ESP_LOGE(BLUE_HID_TAG, "%s init bluedroid failed\n", __func__);
        return;
    }

    if((ret = esp_hidd_profile_init()) != ESP_OK) {
        ESP_LOGE(BLUE_HID_TAG, "%s init bluedroid failed\n", __func__);
    }

    ///register the callback function to the gap module
    esp_ble_gap_register_callback(gap_event_handler);
    esp_hidd_register_callbacks(hidd_event_callback);

    /* set the security iocap & auth_req & key size & init key response key parameters to the stack*/
    esp_ble_auth_req_t auth_req = ESP_LE_AUTH_BOND;     //bonding with peer device after authentication
    esp_ble_io_cap_t iocap = ESP_IO_CAP_NONE;           //set the IO capability to No output No input
    uint8_t key_size = 16;      //the key size should be 7~16 bytes
    uint8_t init_key = ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK;
    uint8_t rsp_key = ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK;
    esp_ble_gap_set_security_param(ESP_BLE_SM_AUTHEN_REQ_MODE, &auth_req, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_IOCAP_MODE, &iocap, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_MAX_KEY_SIZE, &key_size, sizeof(uint8_t));
    /* If your BLE device act as a Slave, the init_key means you hope which types of key of the master should distribute to you,
    and the response key means which key you can distribute to the Master;
    If your BLE device act as a master, the response key means you hope which types of key of the slave should distribute to you,
    and the init key means which key you can distribute to the slave. */
    esp_ble_gap_set_security_param(ESP_BLE_SM_SET_INIT_KEY, &init_key, sizeof(uint8_t));
    esp_ble_gap_set_security_param(ESP_BLE_SM_SET_RSP_KEY, &rsp_key, sizeof(uint8_t));

}
