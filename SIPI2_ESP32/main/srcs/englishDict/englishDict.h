#ifndef __ENGLISH_DICT_H__
#define __ENGLISH_DICT_H__

#include<stdint.h>

// 在字典中查找单词
//@param Target 目标单词
//@return 单词在字典中的索引，若不存在则返回0
uint32_t dictFind(char* target, uint8_t thisDictScene);


#endif // __ENGLISH_DICT_H__
