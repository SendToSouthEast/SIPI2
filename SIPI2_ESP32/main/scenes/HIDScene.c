#include "scenes.h"

#include "main.h"
#include "ble_hidd.h"

static const char *TAG = "SIPI2_HIDSCENE";

lv_obj_t * HIDScene;

void HIDSceneInit(){
    SIPI_LOGI(TAG, "HIDSceneInit");
    scene = SIPI_SCENE_HIDScene;
    HIDScene = lv_obj_create(lv_scr_act()); //创建scr;
    lv_obj_remove_style_all(HIDScene);
    lv_obj_set_size(HIDScene, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);

    // 添加一个文本框
    lv_obj_t *textArea = lv_ta_create(HIDScene, NULL);
    lv_obj_set_pos(textArea, 0, 0);
    lv_obj_set_size(textArea, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);
    lv_obj_set_style_text_font(textArea, &lv_font_montserrat_16, 0);
    lv_ta_set_text(textArea, "Bluetooth keyboard mode");

    blueHIDInit();
}

void HIDSceneQuitEvent(){
    lv_obj_del(HIDScene);
}

void HIDSceneYESEvent(){
}

void HIDSceneNOEvent(){
}

void HIDSceneInputEvent(char inputCharOrigin){
    blueHIDClickKey(inputCharOrigin);
}