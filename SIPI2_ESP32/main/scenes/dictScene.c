#include "scenes.h"

#include "main.h"

static const char *TAG = "SIPI2_DICTSCENE";

lv_obj_t * dictScene;
lv_obj_t * label;
lv_obj_t * dictInputArea;
char inputShort[20] = {0};
uint8_t inputShortCursor;


void dictSceneInit(){
    SIPI_LOGI(TAG, "dictSceneInit");
    scene = SIPI_SCENE_dictScene;
    for(int i = 0;i<21;i++){inputShort[i] = '\0';};
    inputShortCursor = 0;
    dictScene = lv_obj_create(NULL);
    lv_obj_remove_style_all(dictScene);
    lv_obj_set_size(dictScene, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);

    lv_obj_t *dictSceneTitleLable = lv_label_create(dictScene);
    lv_obj_set_style_text_font(dictSceneTitleLable, &lv_font_montserrat_16, 0);
    lv_obj_set_width(dictSceneTitleLable, SIPI_SCREEN_WIDTH);
    lv_obj_set_style_text_color(dictSceneTitleLable, lv_color_hex(0x990000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(dictSceneTitleLable, "ECDICTionary");
    lv_obj_set_pos(dictSceneTitleLable, 0, 0);

    lv_obj_t *dictSceneDetailLable = lv_label_create(dictScene);
    lv_obj_set_style_text_font(dictSceneDetailLable, &simhei, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_recolor(dictSceneDetailLable, 1);
    lv_obj_set_width(dictSceneDetailLable, SIPI_SCREEN_WIDTH);
    lv_label_set_text(dictSceneDetailLable, "Designed by SendToSouthEast\nBased on ESP_IDF & LVGL");
    lv_obj_set_pos(dictSceneDetailLable, 0, 20);

    dictInputArea = lv_textarea_create(dictScene);
    lv_obj_set_size(dictInputArea, SIPI_SCREEN_WIDTH, 20);
    lv_textarea_set_one_line(dictInputArea, true);
    lv_obj_set_pos(dictInputArea, 0, SIPI_SCREEN_HEIGHT - 44);
    lv_obj_set_style_text_font(dictInputArea, &lv_font_montserrat_16, 0);
    lv_textarea_add_text(dictInputArea, "");
    lv_obj_add_state(dictInputArea, LV_STATE_FOCUSED);

    lv_obj_t *hintBar = lv_label_create(dictScene);
    lv_obj_set_size(hintBar, SIPI_SCREEN_WIDTH, 12);
    lv_obj_set_pos(hintBar, 0, SIPI_SCREEN_HEIGHT - 12);
    lv_obj_set_style_bg_color(hintBar, lv_color_hex(0xC0C0C0), 0); // 设置深灰色背景
    lv_obj_set_style_bg_opa(hintBar, LV_OPA_50, LV_PART_MAIN | LV_STATE_DEFAULT); // 设置半透明
    lv_obj_set_style_text_font(hintBar, &lv_font_montserrat_12, 0);
    lv_label_set_text(hintBar, "LEFT: Search  RIGHT: Exit");


    lv_scr_load_anim(dictScene,LV_SCR_LOAD_ANIM_NONE,10,0,true);
}

void dictSceneQuitEvent(){

}

void dictSceneYESEvent(){
    dictSceneQuitEvent();
    wordSceneInit(inputShort);
}

void dictSceneNOEvent(){
    dictSceneQuitEvent();
    mainSceneInit();
}

void dictSceneInputEvent(char inputCharOrigin){
    if(inputCharOrigin == 0){ //删除键
        if(inputShortCursor > 0){
            inputShortCursor--;
            inputShort[inputShortCursor] = '\0';
            lv_textarea_del_char(dictInputArea);
        }
        return;
    }
    //SIPI_LOGI(TAG, "inputShortCursor%d",inputShortCursor);
    inputShort[inputShortCursor] = inputCharOrigin;
    inputShortCursor++;
    lv_textarea_add_char(dictInputArea, inputCharOrigin);
}