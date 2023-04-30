#include "main.h"


#include "simhei.c"
#include "scenes.h"

static const char *TAG = "SIPI2_MAIN";

void keyCheakTask();

uint8_t LVKeyYBuff = 0;

bool keyYesFlag = 0;
bool keyNOFlag = 0;
bool inputFlag = 0;
char InputBuffer = 0;



// 初始化UI
void UIInit()
{
    oald10WordSceneInit(1);
    //mainSceneInit();
}


void lv_tick_task(void *arg)
{
    lv_tick_inc(1);
}

// LVGL初始化和任务
void guiTask(void *p){
    SIPI_LOGI(TAG, "Initializing LVGL");
    lv_init();
    lvgl_driver_init();
    lv_color_t *buf1 = heap_caps_malloc(DISP_BUF_SIZE * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1 != NULL);
    static lv_color_t *buf2 = NULL;

    static lv_disp_draw_buf_t disp_buf;

    uint32_t size_in_px = DISP_BUF_SIZE;
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, size_in_px);
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LV_HOR_RES_MAX; //横向分辨率
    disp_drv.ver_res = LV_VER_RES_MAX; //纵向分辨率
    disp_drv.flush_cb = disp_driver_flush; //设置显示刷新函数
    disp_drv.draw_buf = &disp_buf;
    disp_drv.sw_rotate = 0; //逆时针旋转角度（90，180，270）
    lv_disp_drv_register(&disp_drv); //向LVGL注册驱动

    const esp_timer_create_args_t periodic_timer_args = {
        .callback = &lv_tick_task,
        .name = "periodic_gui"};
    esp_timer_handle_t periodic_timer;
    ESP_ERROR_CHECK(esp_timer_create(&periodic_timer_args, &periodic_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(periodic_timer, 1 * 1000));

    lv_disp_set_rotation(NULL, LV_DISP_ROT_180);

    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);      /*Basic initialization*/
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;                 /*See below.*/
    indev_drv.read_cb = key_read;            /*See below.*/
    /*Register the driver in LVGL and save the created input device object*/
    indev_keypad = lv_indev_drv_register(&indev_drv);

    LV_FONT_DECLARE(simhei);//声明字体simhei

    lv_fs_if_init();

    SIPI_LOGI(TAG, "Initialized LVGL");
    UIInit();
    while (1)
    {
        /* Delay 1 tick (assumes FreeRTOS tick is 10ms */
        vTaskDelay(pdMS_TO_TICKS(10));
        keyCheakTask();
        lv_task_handler();
    }

}
void keyCheakTask(){
    if(keyYesFlag == 1){
        keyYesFlag = 0;
        switch (scene){
        case SIPI_SCENE_dictScene:
            dictSceneYESEvent();
            break; 
        case SIPI_SCENE_wordScene:
            wordSceneYESEvent();
            break;
         case SIPI_SCENE_calcScene:
            calcSceneYESEvent();
            break;
        default:
                break;
        }
    }
    if(keyNOFlag == 1){
        keyNOFlag = 0;
        switch (scene){
        case SIPI_SCENE_dictScene:
            dictSceneNOEvent();
            break; 
        case SIPI_SCENE_wordScene:
            wordSceneNOEvent();
            break;
        case SIPI_SCENE_calcScene:
            calcSceneNOEvent();
            break;
        default:
                break;
        }
    }
    if(inputFlag != 0){
        inputFlag = 0;
        switch (scene){
        case SIPI_SCENE_dictScene:
            dictSceneInputEvent(InputBuffer);
            break;    
        case SIPI_SCENE_HIDScene:
            HIDSceneInputEvent(InputBuffer);
            break;  
        case SIPI_SCENE_calcScene:
            calcSceneInputEvent(InputBuffer);
            break;  
        default:
                break;
        }
    }

}
void keyBoardReadTask(void *p)
{
    while(1)
    {
        //串口键盘
        vTaskDelay(pdMS_TO_TICKS(10));
        char uartCharBuf = cheakUartKeyboard();
        if(uartCharBuf){
            bool addChar = SIPI_YES;
            bool LVKeys = SIPI_NO;
            char inputCharOrigin = uartCharBuf;
            //SIPI_LOGI(TAG, "%c",inputCharOrigin);

            //0x01 NONE
            //0x02 NUM  -
            //0x03 ALT  -
            //0x04 UPPER -
            //0x05 CTRL
            //0x06 SHIFT
            //0x07 ENTER
            //0x08 DELETE
            //0x09 YES
            //0x10 No
            switch (inputCharOrigin){
                case 0x09:addChar = SIPI_NO;keyYesFlag = 1;break;
                case 0x10:addChar = SIPI_NO;keyNOFlag = 1;break;
                case 0x07:inputCharOrigin='\n';break;//enter
                case 0x08:inputCharOrigin= 0x00;break;//delete



                case 0x0A:addChar = SIPI_NO;LVKeys = SIPI_YES;LVKeyYBuff = LV_KEY_LEFT;break;
                case 0x0B:addChar = SIPI_NO;LVKeys = SIPI_YES;LVKeyYBuff = LV_KEY_ENTER;break;
                case 0x0C:addChar = SIPI_NO;LVKeys = SIPI_YES;LVKeyYBuff = LV_KEY_DOWN;break;
                case 0x0D:addChar = SIPI_NO;LVKeys = SIPI_YES;LVKeyYBuff = LV_KEY_RIGHT;break;
                case 0x0E:addChar = SIPI_NO;LVKeys = SIPI_YES;LVKeyYBuff = LV_KEY_UP;break;
            }


            if(addChar){
                //SIPI_LOGI(TAG, "addChar%c",inputCharOrigin);
                InputBuffer = inputCharOrigin;
                inputFlag = 1;
            }
        }
        vTaskDelay(10 / portTICK_RATE_MS );
    }

}

uint8_t cheakLVKey(){
    if(LVKeyYBuff){
        uint8_t LVKeyYBuff_ = LVKeyYBuff;
        LVKeyYBuff = 0;
        return LVKeyYBuff_;
    }
    else{
        return 0;
    }
}


void app_main(void)
{
    UART2_INIT();
    //GPIO_INIT();
    xTaskCreate(guiTask,"gui",1024*8,NULL,1,NULL);
    xTaskCreate(keyBoardReadTask,"keyboard",1024*2,NULL,1,NULL);

}

