#include "scenes.h"

#include "main.h"

static const char *TAG = "SIPI2_MAINSCENE";

lv_obj_t *mainScene;
lv_group_t *group;

void ecdictButtonClickEvent(lv_obj_t *obj, lv_event_t event){
    mainSceneQuitEvent();
    dictSceneInit();
}
void oald10DictButtonClickEvent(lv_obj_t *obj, lv_event_t event){
    mainSceneQuitEvent();
    oald10DictSceneInit();
}

void bluetoothButtonClickEvent(lv_obj_t *obj, lv_event_t event){
    mainSceneQuitEvent();
    HIDSceneInit();
}
void calcSceneButtonClickEvent(lv_obj_t *obj, lv_event_t event){
    mainSceneQuitEvent();
    calcSceneInit();
}

void mainSceneInit(){
    SIPI_LOGI(TAG, "dictSceneInit");
    scene = SIPI_SCENE_mainScene;

    mainScene = lv_obj_create(NULL);
    lv_obj_remove_style_all(mainScene);
    lv_obj_set_size(mainScene, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);
    lv_obj_set_flex_flow(mainScene, LV_FLEX_FLOW_COLUMN);

    lv_obj_t *titleLable = lv_label_create(mainScene);
    lv_obj_set_style_text_font(titleLable, &lv_font_montserrat_16, 0);
    lv_obj_set_width(titleLable, SIPI_SCREEN_WIDTH);
    lv_obj_set_style_text_color(titleLable, lv_color_hex(0x990000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(titleLable, "SIPI2");



    lv_obj_t *ecdictButton = lv_btn_create(mainScene);
    lv_obj_set_size(ecdictButton, SIPI_SCREEN_WIDTH-10, 20);
    lv_obj_set_x(ecdictButton, 5);
    lv_obj_set_style_radius(ecdictButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ecdictButton, lv_palette_main(LV_PALETTE_ORANGE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_t *ecdictLabel = lv_label_create(ecdictButton);
    lv_label_set_text(ecdictLabel, "ECDICT");
    lv_obj_center(ecdictLabel);
    lv_obj_add_event_cb(ecdictButton, ecdictButtonClickEvent ,LV_EVENT_CLICKED,NULL);


    lv_obj_t *oald10DictButton = lv_btn_create(mainScene);
    lv_obj_set_size(oald10DictButton, SIPI_SCREEN_WIDTH-10, 20);
    lv_obj_set_x(oald10DictButton, 5);
    lv_obj_set_style_radius(oald10DictButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(oald10DictButton, lv_palette_main(LV_PALETTE_ORANGE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_t *oald10DictLabel = lv_label_create(oald10DictButton);
    lv_label_set_text(oald10DictLabel, "Oxford Dict 10th");
    lv_obj_center(oald10DictLabel);
    lv_obj_add_event_cb(oald10DictButton, oald10DictButtonClickEvent ,LV_EVENT_CLICKED,NULL);



    lv_obj_t *bluetoothButton = lv_btn_create(mainScene);
    lv_obj_set_size(bluetoothButton, SIPI_SCREEN_WIDTH-10, 20);
    lv_obj_set_x(bluetoothButton, 5);
    lv_obj_set_style_radius(bluetoothButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(bluetoothButton, lv_palette_main(LV_PALETTE_ORANGE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_t *bluetoothLabel = lv_label_create(bluetoothButton);
    lv_label_set_text(bluetoothLabel, "Bluetooth Keyboard");
    lv_obj_center(bluetoothLabel);
    lv_obj_add_event_cb(bluetoothButton, bluetoothButtonClickEvent ,LV_EVENT_CLICKED,NULL);


    lv_obj_t *calcSceneButton = lv_btn_create(mainScene);
    lv_obj_set_size(calcSceneButton, SIPI_SCREEN_WIDTH-10, 20);
    lv_obj_set_x(calcSceneButton, 5);
    lv_obj_set_style_radius(calcSceneButton, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(calcSceneButton, lv_palette_main(LV_PALETTE_ORANGE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_t *calcSceneLabel = lv_label_create(calcSceneButton);
    lv_label_set_text(calcSceneLabel, "calculate");
    lv_obj_center(calcSceneLabel);
    lv_obj_add_event_cb(calcSceneButton, calcSceneButtonClickEvent ,LV_EVENT_CLICKED,NULL);


    group = lv_group_create();


    lv_group_t * mainSceneGroup = lv_group_create();
#ifdef USEWINDOWS
    lv_indev_set_group(lv_win32_keypad_device_object, mainSceneGroup);
#endif // WINDOWS
#ifdef USEESP32
    lv_indev_set_group(indev_keypad, mainSceneGroup);
#endif // USEESP32
    lv_group_add_obj(mainSceneGroup, ecdictButton);
    lv_group_add_obj(mainSceneGroup, oald10DictButton);
    lv_group_add_obj(mainSceneGroup, bluetoothButton);
    lv_group_add_obj(mainSceneGroup, calcSceneButton);
    lv_obj_add_state(ecdictButton, LV_STATE_FOCUSED);


    lv_scr_load_anim(mainScene,LV_SCR_LOAD_ANIM_FADE_IN,10,0,true);
}



void mainSceneQuitEvent(){
    lv_group_del(group);
}



