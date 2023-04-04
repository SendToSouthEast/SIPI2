#include "scenes.h"

#include "main.h"

static const char *TAG = "SIPI2_DICTSCENE";

lv_obj_t * dictScene;
lv_obj_t * label;
lv_obj_t * dictInputArea;
char inputShort[20] = {0};
uint8_t inputShortCursor;


void dictSceneInit(){
    ESP_LOGI(TAG, "dictSceneInit");
    scene = SIPI_SCENE_dictScene;
    for(int i = 0;i<21;i++){inputShort[i] = '\0';};
    inputShortCursor = 0;
    dictScene = lv_obj_create(lv_scr_act()); 
    lv_obj_remove_style_all(dictScene);
    lv_obj_set_size(dictScene, 160, 128);


    lv_obj_t *dictSceneTitleLable = lv_label_create(dictScene);
    lv_obj_set_style_text_font(dictSceneTitleLable, &lv_font_montserrat_16, 0);
    lv_obj_set_width(dictSceneTitleLable, 160);
    lv_obj_set_style_text_color(dictSceneTitleLable, lv_color_hex(0x990000),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(dictSceneTitleLable, "ECDICTionary");
    lv_obj_set_pos(dictSceneTitleLable,0,0);



    lv_obj_t *dictSceneDetailLable = lv_label_create(dictScene);
    lv_obj_set_style_text_font(dictSceneDetailLable, &simhei, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_recolor(dictSceneDetailLable,1);
    lv_obj_set_width(dictSceneDetailLable, 160);

    lv_label_set_text(dictSceneDetailLable, "Designed by SendToSouthEast\nBased on ESP_IDF & LVGL");
    lv_obj_set_pos(dictSceneDetailLable,0, 20);
    //lv_label_set_long_mode(dictSceneDetailLable, LV_LABEL_LONG_WRAP);


    dictInputArea = lv_textarea_create(dictScene);
    lv_obj_set_size(dictInputArea, 160,20);
    lv_textarea_set_one_line(dictInputArea, true);//单行模式
    lv_obj_set_pos(dictInputArea,0,90);
    lv_obj_set_style_text_font(dictInputArea, &lv_font_montserrat_16, 0);

    lv_textarea_add_text(dictInputArea, "");
    lv_obj_add_state(dictInputArea, LV_STATE_FOCUSED);
}
void dictSceneQuitEvent(){
    lv_obj_del(dictScene);
}

void dictSceneYESEvent(){
    dictSceneQuitEvent();
    wordSceneInit(inputShort);
}

void dictSceneNOEvent(){
    dictSceneQuitEvent();
    HIDSceneInit();
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
    //ESP_LOGI(TAG, "inputShortCursor%d",inputShortCursor);
    inputShort[inputShortCursor] = inputCharOrigin;
    inputShortCursor++;
    lv_textarea_add_char(dictInputArea, inputCharOrigin);
}