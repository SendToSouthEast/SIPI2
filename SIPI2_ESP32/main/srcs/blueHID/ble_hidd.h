#ifndef BLE_HIDD_H
#define BLE_HIDD_H

// 初始化蓝牙HID设备
void blueHIDInit(void);

// 模拟点击按键
//@param key_vaule 按键值
void blueHIDClickKey(uint8_t key_vaule);
#endif