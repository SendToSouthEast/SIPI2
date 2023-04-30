#include "scenes.h"

#include "main.h"
#include "englishDict.h"
#include "cJSON.h"

#include "oald10Styles.c"

static const char *TAG = "SIPI2_oald10WordScene";


LV_IMG_DECLARE(but_but2);

// 获取指定索引的单词并显示
//@param seek 单词在字典中的索引
void oald10Display(uint32_t seek, uint8_t page);


lv_obj_t * oald10WordScene;
lv_obj_t * labelObj;

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
    
    oald10Display(1, 2);
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
void oald10StrRead(uint32_t pos, lv_fs_file_t *olad10StrFile, char bufferText[]){
    lv_fs_seek(olad10StrFile, pos, LV_FS_SEEK_SET);
    for(uint16_t i = 0;i<500;i++){

        uint8_t buf[1];
        lv_fs_read(olad10StrFile, buf, 1, NULL);
        if(buf[0] == '\n' || buf[0] == 13 ){
            bufferText[i] = '\0';
            break;
        }
        else{
            bufferText[i] = buf[0];
        }
        //SIPI_LOGI(TAG, "buffer read %d,%s,",buf[0],buf[0]);
    }
}




void oald10Display(uint32_t seek, uint8_t page){
    lv_fs_file_t olad10StrFile;
    lv_fs_file_t olad10MainFile;
	lv_fs_res_t res;
	res = lv_fs_open(&olad10StrFile, OALD_DICT_STR_PATH, LV_FS_MODE_RD);
	if(res != LV_FS_RES_OK) {
		SIPI_LOGE(TAG, "LVFS open olad10StrFile error! Error code: %d", res);
        return;
	}

    res = lv_fs_open(&olad10MainFile, OALD_DICT_MAIN_PATH, LV_FS_MODE_RD);
	if(res != LV_FS_RES_OK) {
		SIPI_LOGE(TAG, "LVFS open olad10MainFile error! Error code: %d", res);
        return;
	}

    cJSON* cJSONobj;
    char bufferText[500] = {0};
    uint32_t readSeek = 0;

    char* json_string = "{\"word\": 775029, \"Pos\": 775039, \"cMean\": 775055, \"USp\": 775171, \"UKp\": 775192, \"USps\": 0, \"UKps\": 0, \"senses\": [{\"shcut_en\": 0, \"shcut_ch\": 0, \"senses\": [{\"def_en\": 775215, \"def_ch\": 775244, \"egs\": [{\"en\": 775267, \"ch\": 775287}]}, {\"def_en\": 775304, \"def_ch\": 775345, \"egs\": [{\"en\": 775356, \"ch\": 775370}]}], \"pos\": 775387}, {\"shcut_en\": 0, \"shcut_ch\": 0, \"senses\": [{\"def_en\": 775398, \"def_ch\": 775457, \"egs\": []}, {\"def_en\": 775510, \"def_ch\": 775579, \"egs\": [{\"en\": 775614, \"ch\": 775631}]}], \"pos\": 775657}], \"idioms\": [], \"pvs\": []}";
    
    // 解析JSON词典数据
    cJSON* root = cJSON_Parse(json_string);
    if (root == NULL) {
        SIPI_LOGE(TAG, "Error parsing JSON: %s\n", cJSON_GetErrorPtr());
        return ;
    }

    if(page == 1){
        // 读取word字段的值
        cJSONobj = cJSON_GetObjectItem(root, "word");
        if (cJSONobj != NULL) {
            readSeek = cJSONobj->valueint;
            if(readSeek != 0){
                oald10StrRead(readSeek, &olad10StrFile, bufferText);
                SIPI_LOGI(TAG, "read word :%s",bufferText);

                lv_obj_t *bufferLabel = lv_label_create(labelObj);
                lv_obj_add_style(bufferLabel, &sipi2_oald10_headword_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_long_mode(bufferLabel, LV_LABEL_LONG_WRAP);
                lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);
                lv_label_set_text(bufferLabel, bufferText);
                SIPI_LOGI(TAG,"carrentPosY %d",lv_obj_get_height(bufferLabel));
            }
        }


        // 读取USp字段的值
        cJSONobj = cJSON_GetObjectItem(root, "USp");
        if (cJSONobj != NULL) {
            readSeek = cJSONobj->valueint;
            if(readSeek != 0){
                oald10StrRead(readSeek, &olad10StrFile, bufferText);

                lv_obj_t *bufferLabel = lv_label_create(labelObj);
                lv_obj_add_style(bufferLabel, &sipi2_oald10_phon_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_long_mode(bufferLabel, LV_LABEL_LONG_WRAP);
                lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);
                lv_label_set_text(bufferLabel, bufferText);
            }

        }

        
        // 读取Pos字段的值
        cJSONobj = cJSON_GetObjectItem(root, "Pos");
        if (cJSONobj != NULL) {
            readSeek = cJSONobj->valueint;
            if(readSeek != 0){
                oald10StrRead(readSeek, &olad10StrFile, bufferText);

                lv_obj_t *bufferLabel = lv_label_create(labelObj);
                lv_obj_add_style(bufferLabel, &sipi2_oald10_pos_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_long_mode(bufferLabel, LV_LABEL_LONG_WRAP);
                lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);
                lv_label_set_text(bufferLabel, bufferText);
            }
        }
        
        // 读取cMean字段的值
        cJSONobj = cJSON_GetObjectItem(root, "cMean");
        if (cJSONobj != NULL) {
            readSeek = cJSONobj->valueint;
            if(readSeek != 0){
                oald10StrRead(readSeek, &olad10StrFile, bufferText);

                lv_obj_t *bufferLabel = lv_label_create(labelObj);
                lv_obj_add_style(bufferLabel, &sipi2_oald10_chn_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_label_set_long_mode(bufferLabel, LV_LABEL_LONG_WRAP);
                lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);
                lv_label_set_text(bufferLabel, bufferText);
            }
        }

        
    }
    else if(page == 2){
        cJSON *senses = cJSON_GetObjectItem(root, "senses");
        if (senses != NULL && senses->child != NULL) {
            int senses_array_size = cJSON_GetArraySize(senses);
            for (int i = 0; i < senses_array_size; i++) {

                // 获取数组senses中的对象
                cJSON *sense = cJSON_GetArrayItem(senses, i);
                readSeek = cJSON_GetObjectItem(sense, "shcut_en")->valueint;
                if(readSeek != 0){
                    oald10StrRead(readSeek, &olad10StrFile, bufferText);
                    lv_obj_t *bufferLabel = lv_label_create(labelObj);
                    lv_obj_add_style(bufferLabel, &sipi2_oald10_shcut_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_add_style(bufferLabel, &sipi2_oald10_shcutline_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_long_mode(bufferLabel, LV_LABEL_LONG_WRAP);
                    lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);
                    lv_label_set_text(bufferLabel, bufferText);
                }


                // 获取数组senses中的子数组senses
                cJSON *sub_senses = cJSON_GetObjectItem(sense, "senses");
                int sub_senses_array_size = cJSON_GetArraySize(sub_senses);
                
                lv_obj_t *senseObj = lv_obj_create(labelObj);
                lv_obj_remove_style_all(senseObj);
                lv_obj_add_style(bufferLabel, &sipi2_oald10_senseline_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);

                for (int j = 0; j < sub_senses_array_size; j++) {
                    // 获取数组senses中的子数组senses中的对象
                    cJSON *sub_sense = cJSON_GetArrayItem(sub_senses, j);
                    readSeek = cJSON_GetObjectItem(sub_sense, "def_en")->valueint;
                    if(readSeek != 0){
                        oald10StrRead(readSeek, &olad10StrFile, bufferText);
                        lv_obj_t *bufferLabel = lv_label_create(senseObj);
                        lv_obj_add_style(bufferLabel, &sipi2_oald10_def_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_obj_add_style(bufferLabel, &sipi2_oald10_senseline_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_label_set_long_mode(bufferLabel, LV_LABEL_LONG_WRAP);
                        lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);
                        lv_label_set_text(bufferLabel, bufferText);
                    }


                    readSeek = cJSON_GetObjectItem(sub_sense, "def_ch")->valueint;
                    if(readSeek != 0){
                        oald10StrRead(readSeek, &olad10StrFile, bufferText);
                        lv_obj_t *bufferLabel = lv_label_create(senseObj);
                        lv_obj_add_style(bufferLabel, &sipi2_oald10_chn_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                        lv_label_set_long_mode(bufferLabel, LV_LABEL_LONG_WRAP);
                        lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);
                        lv_label_set_text(bufferLabel, bufferText);
                    }


                    // 获取数组senses中的子数组senses中的对象中的数组egs
                    cJSON *egs = cJSON_GetObjectItem(sub_sense, "egs");
                    int egs_array_size = cJSON_GetArraySize(egs);
                    for (int k = 0; k < egs_array_size; k++) {
                        // 获取数组senses中的子数组senses中的对象中的数组egs中的对象
                        cJSON *eg = cJSON_GetArrayItem(egs, k);
                        readSeek = cJSON_GetObjectItem(eg, "en")->valueint;
                        if(readSeek != 0){
                            oald10StrRead(readSeek, &olad10StrFile, bufferText);
                            lv_obj_t *bufferLabel = lv_label_create(senseObj);
                            lv_obj_add_style(bufferLabel, &sipi2_oald10_examples_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_long_mode(bufferLabel, LV_LABEL_LONG_WRAP);
                            lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);
                            lv_label_set_text(bufferLabel, bufferText);
                        }


                        readSeek = cJSON_GetObjectItem(eg, "ch")->valueint;
                        if(readSeek != 0){
                            oald10StrRead(readSeek, &olad10StrFile, bufferText);
                            lv_obj_t *bufferLabel = lv_label_create(senseObj);
                            lv_obj_add_style(bufferLabel, &sipi2_oald10_examplechn_style,LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_long_mode(bufferLabel, LV_LABEL_LONG_WRAP);
                            lv_obj_set_width(bufferLabel, SIPI_SCREEN_WIDTH);
                            lv_label_set_text(bufferLabel, bufferText);
                        }
                    }
                }
            }
        }
    }
    cJSON_Delete(root);
}