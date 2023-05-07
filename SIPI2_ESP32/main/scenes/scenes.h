#ifndef __SIPI2_SCENE_H__
#define __SIPI2_SCENE_H__



// main界面初始化
void mainSceneInit();

// main界面注销事件
void mainSceneQuitEvent();




// HID界面初始化
void HIDSceneInit();

// HID界面注销事件
void HIDSceneQuitEvent();

// HID界面YES事件
void HIDSceneYESEvent();

// HID界面NO事件
void HIDSceneNOEvent();

// HID界面输入事件
//@param inputCharOrigin 输入的原字符
void HIDSceneInputEvent(char inputCharOrigin);



//字典界面初始化
void dictSceneInit();

//字典界面注销事件
void dictSceneQuitEvent();

//字典界面YES事件
void dictSceneYESEvent();

//字典界面NO事件
void dictSceneNOEvent();

//字典界面输入事件
//@param inputCharOrigin 输入原数据
void dictSceneInputEvent(char inputCharOrigin);


// 单词界面初始化
//@param Target 单词目标
void wordSceneInit(char* Target);

// 单词界面注销事件
void wordSceneQuitEvent();

// 单词界面YES事件
void wordSceneYESEvent();

// 单词界面NO事件
void wordSceneNOEvent();



//计算器界面初始化
void calcSceneInit();

//计算器界面注销事件
void calcSceneQuitEvent();

//计算器界面YES事件
void calcSceneYESEvent();

//计算器界面NO事件
void calcSceneNOEvent();

//计算器界面输入事件
//@param inputCharOrigin 输入原数据
void calcSceneInputEvent(char inputCharOrigin);




void oald10DictSceneInit();
void oald10DictSceneQuitEvent();
void oald10DictSceneYESEvent();
void oald10DictSceneNOEvent();
void oald10DictSceneInputEvent(char inputCharOrigin);




void oald10WordSceneInit(char* target);
void oald10WordSceneQuitEvent();
void oald10WordSceneYESEvent();
void oald10WordSceneNOEvent();





#endif // __SIPI2_SCENE_H__