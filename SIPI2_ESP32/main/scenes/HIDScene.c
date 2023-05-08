#include "scenes.h"

#include "main.h"
#include "ble_hidd.h"

static const char *TAG = "SIPI2_HIDSCENE";

lv_obj_t * HIDScene;

void HIDSceneInit(){
    SIPI_LOGI(TAG, "HIDSceneInit");
    scene = SIPI_SCENE_HIDScene;
    HIDScene = lv_obj_create(NULL); //创建scr;
    lv_obj_remove_style_all(HIDScene);
    lv_obj_set_size(HIDScene, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);

    // 添加一个文本框
    lv_obj_t *textArea = lv_textarea_create(HIDScene);
    lv_obj_set_pos(textArea, 0, 0);
    lv_obj_set_size(textArea, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);
    lv_obj_set_style_text_font(textArea, &lv_font_montserrat_16, 0);
    lv_textarea_set_text(textArea, "Bluetooth keyboard mode");

    blueHIDInit();

    lv_scr_load_anim(HIDScene,LV_SCR_LOAD_ANIM_NONE,10,0,true);
}

void HIDSceneQuitEvent(){

}

void HIDSceneYESEvent(){
}

void HIDSceneNOEvent(){
}

void HIDSceneInputEvent(char inputCharOrigin){
    blueHIDClickKey(inputCharOrigin);
}