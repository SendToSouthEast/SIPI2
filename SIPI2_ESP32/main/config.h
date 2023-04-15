#ifndef __CONFIG_H__
#define __CONFIG_H__

// 设备
#define USEESP32

// SD卡路径
#define DICT_INDEX_PATH "S:/SIPI2/DICT/index.txt"
#define DICT_PATH "S:/SIPI2/DICT/dic.txt"
#define ALBUM_PATH "S:/SIPI2/ALBUM"

#define SIPI_SCREEN_HEIGHT 128
#define SIPI_SCREEN_WIDTH 160




// 定义
#define SIPI_INPUTMODE_UNAVAILABLE 0
#define SIPI_INPUTMODE_LETTER 1
#define SIPI_INPUTMODE_UPLETTER 2
#define SIPI_INPUTMODE_NUM_SYM 3

#define SIPI_SCENE_mainScene 0
#define SIPI_SCENE_1Scene 1
#define SIPI_SCENE_2Scene 2
#define SIPI_SCENE_3Scene 3

#define SIPI_SCENE_dictScene 10
#define SIPI_SCENE_wordScene 11
#define SIPI_SCENE_AlbumScene 12
#define SIPI_SCENE_ImgShowScene 13
#define SIPI_SCENE_HIDScene 14

#define SIPI_OK 1
#define SIPI_YES 1
#define SIPI_NO 0



#endif // __CONFIG_H__