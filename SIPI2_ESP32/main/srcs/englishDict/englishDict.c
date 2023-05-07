#include "englishDict.h"

#include "main.h"

static const char *TAG = "SIPI2_ENGLISHDICT";

// 将字符串转换为整数
//@param str 待转换的字符串
//@return 转换后的整数
static uint32_t strToInt(const char* str);

// 比较两个字符串位置顺序
//@param a 第一个字符串
//@param b 第二个字符串
//@return 如果相等返回0，在前面返回1，在后面返回2，出错返回3
static uint8_t compareStringOrder(char* a, char* b);

// 判断一个字符串是否以另一个字符串结尾
//@param str1 待判断的字符串
//@param str2 结尾字符串
//@return 如果以str2结尾返回1，否则返回0
static bool isEndWith(const char* str1, const char* str2);

// 判断一个字符串是否以另一个字符串开头
//@param str1 待判断的字符串
//@param str2 开头字符串
//@return 如果以str2开头返回1，否则返回0
static bool isBeginWith(const char* str1, const char* str2);

// 去除文件扩展名
//@param dir 待处理的字符串
static void stripExt(char* dir);

static bool isEndWith(const char * str1, const char * str2){
    if(str1 == NULL || str2 == NULL)
        return false;

    uint16_t len1 = strlen(str1);
    uint16_t len2 = strlen(str2);
    if((len1 < len2) || (len1 == 0 || len2 == 0))
        return false;

    while(len2 >= 1)
    {
        if(str2[len2 - 1] != str1[len1 - 1])
            return false;

        len2--;
        len1--;
    }

    return true;
}

static bool isBeginWith(const char * str1, const char * str2){
    if(str1 == NULL || str2 == NULL)
        return false;

    uint16_t len1 = strlen(str1);
    uint16_t len2 = strlen(str2);
    if((len1 < len2) || (len1 == 0 || len2 == 0))
        return false;

    uint16_t i = 0;
    char * p = str2;
    while(*p != '\0')
    {
        if(*p != str1[i])
            return false;

        p++;
        i++;
    }

    return true;
}

static void stripExt(char *dir){
    char *end = dir + strlen(dir);

    while (end >= dir && *end != '/') {
        --end;
    }
    if (end > dir) {
        *end = '\0';
    }
    else if (end == dir) {
        *(end+1) = '\0';
    }
}

static uint32_t strToInt(const char* str){
	uint32_t result=0; //8个字节长度
	if (str==NULL)
		return 0;
	while(isspace(*str)){
		++str;
	}
	if(*str=='-'){
		str++;
	}else if(*str=='+')
		str++;
	while(*str<='9' && *str>='0'){
		result=result*10+*str-'0';
		str++;
	}
	return result;
}


static uint8_t compareStringOrder(char* a,char* b){
    // for(int i= 0;i<20;i++){
    //     a[i] = tolower(a[i]);

    // }
    // for(int i=0;i<20;i++){
    //     b[i] = tolower(b[i]);
    // }
    for(int i= 0;i<20;i++){
        char aNum = a[i];
        char bNum = b[i];
        //SIPI_LOGI(TAG,"compareing: %s,%s,%c,%c",a,b,aNum,bNum);
        if((aNum == 0) && (bNum == 0)){
            return 0;//找到了
        }
        else if(aNum < bNum){
            return 2;//在后面
        }
        else if(aNum > bNum){
            return 1;//在前面
        }
    }
    return 3;//
}

uint32_t dictFind(char* target, uint8_t thisDictScene){
    lv_fs_file_t f;
	lv_fs_res_t res;

    if(thisDictScene == SIPI_SCENE_wordScene){
        res = lv_fs_open(&f, DICT_INDEX_PATH, LV_FS_MODE_RD);
    }
    else if(thisDictScene == SIPI_SCENE_oald10DictScene){
        res = lv_fs_open(&f, OALD_DICT_INDEX_PATH, LV_FS_MODE_RD);
    }
    else{
        SIPI_LOGI(TAG, "wrong Scene %d,",thisDictScene);
        return 0;
    }
	
	if(res != LV_FS_RES_OK) {
		LV_LOG_USER("Open error! Error code: %d", res);
		return 0;
	}
	char TargetWord[20] = {0};
    for(int i= 0;i<20;i++){
        TargetWord[i] = target[i];
    }

	char seekall[13];
	lv_fs_read(&f, seekall, 13, NULL);
    uint32_t seekallint = strToInt(seekall);
    uint32_t seekCurrent = seekallint/2 + 1;//当前
    uint32_t seekUpperLimit = seekallint;//范围上限
    uint32_t seekLowerLimit = 0;//范围下限

    uint8_t foundFlag = 0;
    char data[30] = {0};
    char word[30] = {0};
    uint32_t seekWord = 16;
    for(uint8_t ia = 0;ia<30;ia++){
        for(uint8_t ib=0;ib<30;ib++){
            data[ib] = '\0';
        }
        for(uint8_t ib=0;ib<30;ib++){
            word[ib] = '\0';
        }
        lv_fs_seek(&f, seekCurrent, LV_FS_SEEK_SET);
        for(uint8_t i = 0;i<30;i++){
            uint8_t buf[1];
            uint32_t seekNow;
            lv_fs_tell(&f, &seekNow);
            lv_fs_seek(&f, seekNow-2, LV_FS_SEEK_SET);
            lv_fs_read(&f, buf, 1, NULL);
            //LV_LOG_USER(buf);
            if(buf[0] == '\n'){
                int l = 0;
                for(uint8_t j = 0;j<30;j++){
                    lv_fs_read(&f, buf, 1, NULL);
                    if(buf[0] == '\n'){
                        seekWord = strToInt(data);
                        break;
                    }
                    if(buf[0] == ','){
                        data[l] = buf[0];
                        for(uint8_t k = 0;k<30;k++){
                            if(data[k]==','){
                                break;
                            }
                            word[k] = data[k];
                        }
                        l = -1;
                    }
                    else{
                        data[l] = buf[0];
                    }
                    l++;
                }
                break;
            }
        }
        //LV_LOG_USER("Current: %s,%s,%d",TargetWord,word,seekWord);
        uint8_t compareStrResult =  compareStringOrder(word,TargetWord);
        //LV_LOG_USER("compareStrResult: %d", compareStrResult);
        if(compareStrResult == 0){
            foundFlag = 1;
            break;
        }
        else if(compareStrResult == 1){
            seekUpperLimit = seekCurrent;
            seekCurrent = (seekUpperLimit - seekLowerLimit)/2 + 1 + seekLowerLimit;
        }
        else if(compareStrResult == 2){
            seekLowerLimit = seekCurrent;
            seekCurrent = (seekUpperLimit - seekLowerLimit)/2 + 1 + seekLowerLimit;
        }

    }
    if(!foundFlag){
        seekWord = 0;
    }
	lv_fs_close(&f);
	return seekWord;

}