#include "scenes.h"

#include "main.h"
#include "englishDict.h"


#include "oald10Styles.c"

static const char *TAG = "SIPI2_oald10WordScene";


LV_IMG_DECLARE(but_but2);

// 获取指定索引的单词并显示
//@param seek 单词在字典中的索引
void oald10Display(uint32_t seek, uint8_t page);


lv_obj_t * oald10WordScene;
lv_obj_t * labelObj;

void event(){
    SIPI_LOGI(TAG, "click");
}
void oald10WordSceneInit(char* target){
    SIPI_LOGI(TAG, "oald10WordSceneInit");
    scene = SIPI_SCENE_oald10WordScene;

    oald10WordScene = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(oald10WordScene);
    lv_obj_set_size(oald10WordScene, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);

    labelObj = lv_obj_create(oald10WordScene);
    lv_obj_remove_style_all(labelObj);
    lv_obj_set_size(labelObj, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);



    lv_group_t * oald10WordSceneGroup = lv_group_create();
#ifdef USEWINDOWS
    lv_indev_set_group(lv_win32_keypad_device_object, oald10WordSceneGroup);
#endif // WINDOWS
#ifdef USEESP32
    lv_indev_set_group(indev_keypad, oald10WordSceneGroup);
#endif // USEESP32
    lv_group_add_obj(oald10WordSceneGroup,labelObj);
    lv_obj_add_state(labelObj, LV_STATE_FOCUSED);
    lv_obj_set_flex_flow(labelObj, LV_FLEX_FLOW_COLUMN);

    oald10StylesInit();


    //SIPI_LOGI(TAG,"finding word: %s",target);
    //uint32_t wordSeek = dictFind(target);
    //oald10Display(wordSeek, 1);
    oald10Display(1, 1);
    lv_obj_add_event_cb(labelObj, event, LV_EVENT_KEY, NULL);
}

void oald10WordSceneQuitEvent(){
    lv_obj_del(oald10WordScene);
}
void oald10WordSceneYESEvent(){
    oald10WordSceneQuitEvent();
    dictSceneInit();
}

void oald10WordSceneNOEvent(){
    oald10WordSceneQuitEvent();
    dictSceneInit();
}


void oald10Display(uint32_t seek, uint8_t page){
    if(page == 1){
        char bufferText[500] = {0};
        




        
        //uint32_t carrentPosY = 0;
        lv_obj_t *oald10HeadwordLabel = lv_label_create(labelObj);
        lv_obj_add_style(oald10HeadwordLabel, &sipi2_oald10_headword_style,LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(oald10HeadwordLabel, LV_LABEL_LONG_WRAP);
        //lv_obj_set_pos(oald10HeadwordLabel, 0, carrentPosY);
        lv_obj_set_width(oald10HeadwordLabel, SIPI_SCREEN_WIDTH);
        lv_label_set_text(oald10HeadwordLabel, "This is a multi-line label.");
        //carrentPosY += lv_obj_get_height(oald10HeadwordLabel);
        SIPI_LOGI(TAG,"carrentPosY %d",lv_obj_get_height(oald10HeadwordLabel));



        lv_obj_t *oald10PhonLabel = lv_label_create(labelObj);
        lv_obj_add_style(oald10PhonLabel, &sipi2_oald10_phon_style,LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(oald10PhonLabel, LV_LABEL_LONG_WRAP);
        //lv_obj_set_pos(oald10PhonLabel, 0, carrentPosY);
        lv_obj_set_width(oald10PhonLabel, SIPI_SCREEN_WIDTH);
        lv_label_set_text(oald10PhonLabel, " phon");
        carrentPosY += lv_obj_get_height(oald10PhonLabel);

    }
    
}