#include "scenes.h"

#include "main.h"

#include "calculate.h"

static const char *TAG = "SIPI2_DICTSCENE";

lv_obj_t * calcScene;
lv_obj_t * calcInputArea;
lv_obj_t *calcSceneResultLable;
char calcInputShort[20] = {0};
uint8_t calcInputShortCursor;

void calcSceneInit(){
    SIPI_LOGI(TAG, "calcSceneInit");
    scene = SIPI_SCENE_calcScene;
    for(int i = 0;i<21;i++){calcInputShort[i] = '\0';};
    calcInputShortCursor = 0;
    calcScene = lv_obj_create(NULL);
    lv_obj_remove_style_all(calcScene);
    lv_obj_set_size(calcScene, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);

    lv_obj_t *calcSceneTitleLable = lv_label_create(calcScene);
    lv_obj_set_style_text_font(calcSceneTitleLable, &lv_font_montserrat_16, 0);
    lv_obj_set_width(calcSceneTitleLable, SIPI_SCREEN_WIDTH);
    lv_obj_set_style_text_color(calcSceneTitleLable, lv_color_hex(0x990000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(calcSceneTitleLable, "calculate on c");
    lv_obj_set_pos(calcSceneTitleLable, 0, 0);


    calcSceneResultLable = lv_label_create(calcScene);
    lv_obj_set_style_text_font(calcSceneResultLable, &simhei, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_recolor(calcSceneResultLable, 1);
    lv_obj_set_width(calcSceneResultLable, SIPI_SCREEN_WIDTH);
    lv_label_set_text(calcSceneResultLable, "Designed by SendToSouthEast");
    lv_obj_set_pos(calcSceneResultLable, 0, 20);

    calcInputArea = lv_textarea_create(calcScene);
    lv_obj_set_size(calcInputArea, SIPI_SCREEN_WIDTH, 20);
    lv_textarea_set_one_line(calcInputArea, true);
    lv_obj_set_pos(calcInputArea, 0, SIPI_SCREEN_HEIGHT - 44);
    lv_obj_set_style_text_font(calcInputArea, &lv_font_montserrat_16, 0);
    lv_textarea_add_text(calcInputArea, "");
    lv_obj_add_state(calcInputArea, LV_STATE_FOCUSED);

    // lv_obj_t *hintBar = lv_label_create(calcScene);
    // lv_obj_set_size(hintBar, SIPI_SCREEN_WIDTH, 12);
    // lv_obj_set_pos(hintBar, 0, SIPI_SCREEN_HEIGHT - 12);
    // lv_obj_set_style_bg_color(hintBar, lv_color_hex(0xC0C0C0), 0); // 设置深灰色背景
    // lv_obj_set_style_bg_opa(hintBar, LV_OPA_50, LV_PART_MAIN | LV_STATE_DEFAULT); // 设置半透明
    // lv_obj_set_style_text_font(hintBar, &lv_font_montserrat_12, 0);
    // lv_label_set_text(hintBar, "LEFT: Count  RIGHT: Exit");

    lv_scr_load_anim(calcScene,LV_SCR_LOAD_ANIM_NONE,10,0,true);
}

void calcTask(void *p)
{
    char strbuff[30];
    SIPI_LOGI(TAG,"counting……");
    double result = calculate(calcInputShort);
    SIPI_LOGI(TAG,"result:result");
    for(int i = 0;i<21;i++){calcInputShort[i] = '\0';};
    calcInputShortCursor = 0;
    lv_textarea_set_text(calcInputArea,"");
    snprintf(strbuff,30,"%.2f",result);
    lv_label_set_text(calcSceneResultLable, strbuff);
    vTaskDelete(NULL);
}

void calcSceneQuitEvent(){

}

void calcSceneYESEvent(){
    xTaskCreate(calcTask,"calcTask",1024*4,NULL,1,NULL);
} 



void calcSceneNOEvent(){
    calcSceneQuitEvent();
    mainSceneInit();
}

void calcSceneInputEvent(char inputCharOrigin){
    if(inputCharOrigin == 0){ //删除键
        if(calcInputShortCursor > 0){
            calcInputShortCursor--;
            calcInputShort[calcInputShortCursor] = '\0';
            lv_textarea_del_char(calcInputArea);
        }
        return;
    }
    //SIPI_LOGI(TAG, "calcInputShortCursor%d",calcInputShortCursor);
    calcInputShort[calcInputShortCursor] = inputCharOrigin;
    calcInputShortCursor++;
    lv_textarea_add_char(calcInputArea, inputCharOrigin);
}