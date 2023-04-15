#include "scenes.h"

#include "main.h"

static const char *TAG = "SIPI2_MAINSCENE";

lv_obj_t *mainScene;
lv_obj_t *ecdictButton;
lv_obj_t *bluetoothButton;

void ecdictButtonClickEvent(lv_obj_t *obj, lv_event_t event){
    mainSceneQuitEvent();
    dictSceneInit();
}

void bluetoothButtonClickEvent(lv_obj_t *obj, lv_event_t event){
    mainSceneQuitEvent();
    HIDSceneInit();
}

void mainSceneInit(){
    SIPI_LOGI(TAG, "dictSceneInit");
    scene = SIPI_SCENE_mainScene;

    mainScene = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(mainScene);
    lv_obj_set_size(mainScene, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);

    lv_obj_t *titleLable = lv_label_create(mainScene);
    lv_obj_set_style_text_font(titleLable, &lv_font_montserrat_16, 0);
    lv_obj_set_width(titleLable, SIPI_SCREEN_WIDTH);
    lv_obj_set_style_text_color(titleLable, lv_color_hex(0x990000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(titleLable, "SIPI2");
    lv_obj_align(titleLable, LV_ALIGN_TOP_LEFT, 0, 0);



    ecdictButton = lv_btn_create(mainScene);
    lv_obj_set_size(ecdictButton, SIPI_SCREEN_WIDTH-10, 20);
    lv_obj_set_pos(ecdictButton, 5,30);
    lv_obj_set_style_radius(ecdictButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ecdictButton, lv_palette_main(LV_PALETTE_ORANGE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_t *ecdictLabel = lv_label_create(ecdictButton);
    lv_label_set_text(ecdictLabel, "ECDICT");
    lv_obj_center(ecdictLabel);
    lv_obj_add_event_cb(ecdictButton, ecdictButtonClickEvent ,LV_EVENT_CLICKED,NULL);



    bluetoothButton = lv_btn_create(mainScene);
    lv_obj_set_size(bluetoothButton, SIPI_SCREEN_WIDTH-10, 20);
    lv_obj_set_pos(bluetoothButton, 5,55);
    lv_obj_set_style_radius(bluetoothButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bluetoothButton, lv_palette_main(LV_PALETTE_ORANGE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_t *bluetoothLabel = lv_label_create(bluetoothButton);
    lv_label_set_text(bluetoothLabel, "Bluetooth Keyboard");
    lv_obj_center(bluetoothLabel);
    lv_obj_add_event_cb(bluetoothButton, bluetoothButtonClickEvent ,LV_EVENT_CLICKED,NULL);

    lv_group_t *group = lv_group_create();




    lv_group_t * mainSceneGroup = lv_group_create();
#ifdef USEWINDOWS
    lv_indev_set_group(lv_win32_keypad_device_object, mainSceneGroup);
#endif // WINDOWS
#ifdef USEESP32
    lv_indev_set_group(indev_keypad, mainSceneGroup);
#endif // USEESP32
    lv_group_add_obj(mainSceneGroup, ecdictButton);
    lv_group_add_obj(mainSceneGroup, bluetoothButton);
    lv_obj_add_state(ecdictButton, LV_STATE_FOCUSED);
}



void mainSceneQuitEvent(){
    lv_obj_del(mainScene);
}