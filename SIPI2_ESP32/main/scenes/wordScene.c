#include "scenes.h"

#include "main.h"
#include "englishDict.h"

static const char *TAG = "SIPI2_WORDSCENE";

// 获取指定索引的单词并显示
//@param seek 单词在字典中的索引
void getWord(uint32_t seek);


lv_obj_t * wordScene;
lv_obj_t * wordSceneLabel;

void wordSceneInit(char* target){
    scene = SIPI_SCENE_wordScene;

    wordScene = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(wordScene);
    lv_obj_set_size(wordScene, 160, 128);

    wordSceneLabel = lv_label_create(wordScene);
    lv_obj_set_style_text_font(wordSceneLabel, &simhei, 0);
    lv_label_set_recolor(wordSceneLabel,1);
    lv_obj_set_width(wordSceneLabel, 160);
    lv_label_set_text(wordSceneLabel, "Write a #ff0000 red# word ECDICT    Designed by SendToSouthEast\nBased on ESP_IDF & LVGL");
    lv_label_set_long_mode(wordSceneLabel, LV_LABEL_LONG_WRAP);


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
        lv_label_set_text(wordSceneLabel, "但是...但是...我没有找到...\n实在很抱歉呐...\n也许，你可以在其它地方查查看...");
        return;
    }

    lv_fs_file_t f;
	lv_fs_res_t res;
	char text[1000];

	res = lv_fs_open(&f, DICT_PATH, LV_FS_MODE_RD);
	if(res != LV_FS_RES_OK) {
		LV_LOG_USER("Open error! Error code: %d", res);
		return;
	}
	lv_fs_seek(&f, seek, LV_FS_SEEK_SET);
	uint16_t textseek = 0;
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
                    text[textseek] = things[j];
                    textseek++;
                }
            }
            else if(row == 1){
                uint8_t things[] = "/#\n ";
                for(uint8_t j = 0;j<=3;j++){
                    text[textseek] = things[j];
                    textseek++;
                }
            }
            else if(row == 2){
                uint8_t things[] = "\n#006400 ";
                for(uint8_t j = 0;j<=8;j++){
                    text[textseek] = things[j];
                    textseek++;
                }
            }
            else if(row == 3){
                uint8_t things[] = "#\n #8b4513 ";
                for(uint8_t j = 0;j<=9;j++){
                    text[textseek] = things[j];
                    textseek++;
                }
            }
            else if(row == 3){
                text[textseek] = '#';
                textseek++;
            }

            row++;
        }
        else if(buf[0] == '#'){
            text[textseek] = '\n';
            textseek++;
        }
        else{
            text[textseek] = buf[0];
            textseek++;
        }
	}
	LV_LOG_USER(text);
	lv_label_set_text(wordSceneLabel, text);

}