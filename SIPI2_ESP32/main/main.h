#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/unistd.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "lvgl.h"
#include "lvgl_helpers.h"
#include "lv_fs_if.h"
#include "esp_system.h"
#include "esp_log.h"


#include "init.h"
#include "config.h"


const lv_font_t simhei;
uint8_t scene;

#endif // __MAIN_H__
