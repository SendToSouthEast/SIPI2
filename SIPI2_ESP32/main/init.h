#ifndef __INIT_H__
#define __INIT_H__

#include "lvgl.h"


#define SIPI_KEY_UP     GPIO_NUM_36
#define SIPI_KEY_DOWN   GPIO_NUM_34
#define SIPI_KEY_LEFT   GPIO_NUM_39
#define SIPI_KEY_RIGHT  GPIO_NUM_35
#define SIPI_KEY_YES    GPIO_NUM_32
#define SIPI_KEY_NO     GPIO_NUM_33

#define EX_UART_NUM UART_NUM_2  //串口2
#define TXD_PIN    (GPIO_NUM_27) //txd使用gpio27
#define RXD_PIN    (GPIO_NUM_14) //rxd使用gpio14

// 初始化串口2
void UART2_INIT();

// 初始化串口1
void GPIO_INIT();

// 键盘读取函数
void key_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

// 检查串口缓冲区
// @return 缓冲区数据（char），若无则为0
char cheakUartKeyboard();

// 日志信息输出函数
void SIPI_LOGI(const char* tag, const char* format, ...);
void SIPI_LOGE(const char* tag, const char* format, ...);

#endif //__INIT_H__
