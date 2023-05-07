#include "scenes.h"

#include "main.h"
#include "cJSON.h"

static const char *TAG = "SIPI2_oald10DictScene";

lv_obj_t * oald10DictScene;
lv_obj_t * label;
lv_obj_t * dictInputArea;
char oald10DictInputShort[20] = {0};
uint8_t oald10DictInputShortCursor;


void oald10DictSceneInit(){
    SIPI_LOGI(TAG, "oald10DictSceneInit");
    scene = SIPI_SCENE_oald10DictScene;
    for(int i = 0;i<21;i++){oald10DictInputShort[i] = '\0';};
    oald10DictInputShortCursor = 0;
    oald10DictScene = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(oald10DictScene);
    lv_obj_set_size(oald10DictScene, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);

    lv_obj_t *oald10DictSceneTitleLable = lv_label_create(oald10DictScene);
    lv_obj_set_style_text_font(oald10DictSceneTitleLable, &lv_font_montserrat_16, 0);
    lv_obj_set_width(oald10DictSceneTitleLable, SIPI_SCREEN_WIDTH);
    lv_obj_set_style_text_color(oald10DictSceneTitleLable, lv_color_hex(0x990000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(oald10DictSceneTitleLable, "Oxford");
    lv_obj_set_pos(oald10DictSceneTitleLable, 0, 0);

    lv_obj_t *oald10DictSceneDetailLable = lv_label_create(oald10DictScene);
    lv_obj_set_style_text_font(oald10DictSceneDetailLable, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_label_set_recolor(oald10DictSceneDetailLable, 1);
    lv_obj_set_width(oald10DictSceneDetailLable, SIPI_SCREEN_WIDTH);
    lv_label_set_text(oald10DictSceneDetailLable, "Advanced Learner\'s Dictionary\nBeta version \nby YXY");
    lv_obj_set_style_text_color(oald10DictSceneTitleLable, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(oald10DictSceneDetailLable, 0, 20);

    dictInputArea = lv_textarea_create(oald10DictScene);
    lv_obj_set_size(dictInputArea, SIPI_SCREEN_WIDTH, 20);
    lv_textarea_set_one_line(dictInputArea, true);
    lv_obj_set_pos(dictInputArea, 0, SIPI_SCREEN_HEIGHT - 44);
    lv_obj_set_style_text_font(dictInputArea, &lv_font_montserrat_16, 0);
    lv_textarea_add_text(dictInputArea, "");
    lv_obj_add_state(dictInputArea, LV_STATE_FOCUSED);

    lv_obj_t *hintBar = lv_label_create(oald10DictScene);
    lv_obj_set_size(hintBar, SIPI_SCREEN_WIDTH, 12);
    lv_obj_set_pos(hintBar, 0, SIPI_SCREEN_HEIGHT - 12);
    lv_obj_set_style_bg_color(hintBar, lv_color_hex(0xC0C0C0), 0); // 设置深灰色背景
    lv_obj_set_style_bg_opa(hintBar, LV_OPA_50, LV_PART_MAIN | LV_STATE_DEFAULT); // 设置半透明
    lv_obj_set_style_text_font(hintBar, &lv_font_montserrat_12, 0);
    lv_label_set_text(hintBar, "LEFT: Search  RIGHT: Exit");
}

void oald10DictSceneQuitEvent(){
    lv_obj_del(oald10DictScene);
}

void oald10DictSceneYESEvent(){
    oald10DictSceneQuitEvent();
    oald10WordSceneInit(oald10DictInputShort);
}

void oald10DictSceneNOEvent(){
    oald10DictSceneQuitEvent();
    mainSceneInit();
}

void oald10DictSceneInputEvent(char inputCharOrigin){
    if(inputCharOrigin == 0){ //删除键
        if(oald10DictInputShortCursor > 0){
            oald10DictInputShortCursor--;
            oald10DictInputShort[oald10DictInputShortCursor] = '\0';
            lv_textarea_del_char(dictInputArea);
        }
        return;
    }
    //SIPI_LOGI(TAG, "oald10DictInputShortCursor%d",oald10DictInputShortCursor);
    oald10DictInputShort[oald10DictInputShortCursor] = inputCharOrigin;
    oald10DictInputShortCursor++;
    lv_textarea_add_char(dictInputArea, inputCharOrigin);
}