#include "scenes.h"

#include "main.h"
#include "englishDict.h"

static const char *TAG = "SIPI2_WORDSCENE";


LV_IMG_DECLARE(but_but2);

// 获取指定索引的单词并显示
//@param seek 单词在字典中的索引
void getWord(uint32_t seek);


lv_obj_t * wordScene;
lv_obj_t * meaningLabel;
lv_obj_t * labelObj;
lv_obj_t * wordLabel;

void wordSceneInit(char* target){
    SIPI_LOGI(TAG, "wordSceneInit");
    scene = SIPI_SCENE_wordScene;

    wordScene = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(wordScene);
    lv_obj_set_size(wordScene, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT);

    labelObj = lv_obj_create(wordScene);
    lv_obj_remove_style_all(labelObj);
    lv_obj_set_size(labelObj, SIPI_SCREEN_WIDTH, SIPI_SCREEN_HEIGHT - 12);


    lv_group_t * wordsceneGroup = lv_group_create();
#ifdef USEWINDOWS
    lv_indev_set_group(lv_win32_keypad_device_object, wordsceneGroup);
#endif // WINDOWS
#ifdef USEESP32
    lv_indev_set_group(indev_keypad, wordsceneGroup);
#endif // USEESP32
    lv_group_add_obj(wordsceneGroup,labelObj);
    lv_obj_add_state(labelObj, LV_STATE_FOCUSED);


    meaningLabel = lv_label_create(labelObj);
    lv_obj_set_style_text_font(meaningLabel, &simhei, 0);
    lv_label_set_recolor(meaningLabel,1);
    lv_obj_set_width(meaningLabel, SIPI_SCREEN_WIDTH);
    lv_label_set_text(meaningLabel, "Designed by SendToSouthEast\nBased on ESP_IDF & LVGL\nB\nB\nB\nB\nB\nB\nB");
    lv_label_set_long_mode(meaningLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(meaningLabel,0,12);

    wordLabel = lv_label_create(labelObj);
    lv_obj_set_style_text_font(wordLabel, &arial, 0);
    lv_obj_set_width(wordLabel, SIPI_SCREEN_WIDTH);
    lv_label_set_recolor(wordLabel,1);
    lv_label_set_text(wordLabel, NULL);
    lv_label_set_long_mode(wordLabel, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(wordLabel,0,0);

    // 创建操作提示栏
    lv_obj_t *hintBar = lv_label_create(wordScene);
    lv_obj_set_size(hintBar, SIPI_SCREEN_WIDTH, 12);
    lv_obj_set_pos(hintBar, 0, SIPI_SCREEN_HEIGHT - 12);
    lv_obj_set_style_bg_color(hintBar, lv_color_hex(0xC0C0C0), 0); // 设置深灰色背景
    lv_obj_set_style_bg_opa(hintBar, LV_OPA_50, LV_PART_MAIN | LV_STATE_DEFAULT); // 设置半透明
    lv_obj_set_style_text_font(hintBar, &lv_font_montserrat_12, 0);
    lv_label_set_text(hintBar, "LEFT: Exit  RIGHT: Exit");

    SIPI_LOGI(TAG,"finding word: %s",target);
    uint32_t wordSeek = dictFind(target);
    getWord(wordSeek);
}

void wordSceneQuitEvent(){
    lv_obj_del(wordScene);
}
void wordSceneYESEvent(){
    wordSceneQuitEvent();
    dictSceneInit();
}

void wordSceneNOEvent(){
    wordSceneQuitEvent();
    dictSceneInit();
}



void getWord(uint32_t seek){
    if(seek == 0){
        // 创建一个图片控件
        lv_obj_t * img = lv_img_create(wordScene);

        // 设置图片源
        lv_img_set_src(img, &but_but2);
        lv_obj_set_pos(img, 0, 0);


        lv_label_set_text(meaningLabel, "但是...但是...我没有找到..\n实在很抱歉呐...\n也许，你可以在其它地方查查看...");
        lv_obj_set_pos(meaningLabel,0,76);
        return;
    }

    lv_fs_file_t f;
	lv_fs_res_t res;
    char outPutWord[50] = {0};
    uint16_t outPutWordSeek = 0;
	char outPutText[1000] = {0};
    uint16_t outPutTextSeek = 0;

	res = lv_fs_open(&f, DICT_PATH, LV_FS_MODE_RD);
	if(res != LV_FS_RES_OK) {
		LV_LOG_USER("Open error! Error code: %d", res);
		return;
	}
	lv_fs_seek(&f, seek, LV_FS_SEEK_SET);
	uint8_t row = 0;
	for(uint16_t i = 0;i<1000;i++){

        uint8_t buf[1];
        lv_fs_read(&f, buf, 1, NULL);
        if(buf[0] == '\n'){
            break;

        }
        else if(buf[0] == '@'){
            if(row == 0){
                uint8_t things[] = "  #c71585 /";
                for(uint8_t j = 0;j<=10;j++){
                    outPutWord[outPutWordSeek] = things[j];
                    outPutWordSeek++;
                }
            }
            else if(row == 1){
                uint8_t things[] = "/# ";
                for(uint8_t j = 0;j<=2;j++){
                    outPutWord[outPutWordSeek] = things[j];
                    outPutWordSeek++;
                }
            }
            else if(row == 2){
                uint8_t things[] = "\n#006400 ";
                for(uint8_t j = 0;j<=8;j++){
                    outPutText[outPutTextSeek] = things[j];
                    outPutTextSeek++;
                }
            }
            else if(row == 3){
                uint8_t things[] = "#\n #8b4513 ";
                for(uint8_t j = 0;j<=9;j++){
                    outPutText[outPutTextSeek] = things[j];
                    outPutTextSeek++;
                }
            }
            else if(row == 3){
                outPutText[outPutTextSeek] = '#';
                outPutTextSeek++;
            }

            row++;
        }
        else if(buf[0] == '#'){
            outPutText[outPutTextSeek] = '\n';
            outPutTextSeek++;
        }
        else{
            if(row == 0 || row == 1){
                outPutWord[outPutWordSeek] = buf[0];
                outPutWordSeek++;
            }
            else{
                outPutText[outPutTextSeek] = buf[0];
                outPutTextSeek++;
            }
        }
	}
	LV_LOG_USER(outPutText);
	lv_label_set_text(meaningLabel, outPutText);
    lv_label_set_text(wordLabel, outPutWord);
}