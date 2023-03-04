#include "scenes.h"

#include "main.h"
#include "ble_hidd.h"

static const char *TAG = "SIPI2_HIDSCENE";

lv_obj_t * HIDScene;

void HIDSceneInit(){
    ESP_LOGI(TAG, "HIDSceneInit");
    scene = SIPI_SCENE_HIDScene;
    HIDScene = lv_obj_create(lv_scr_act()); //创建scr;
    lv_obj_remove_style_all(HIDScene);
    lv_obj_set_size(HIDScene, 160, 128);

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