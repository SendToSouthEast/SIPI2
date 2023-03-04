#include "config.h"
#include "delay.h"
#include "GPIO.h"
#include "UART.h"
#define uchar unsigned char
#define uint unsigned int
	
#define FOSC 11059200UL
#define BRT (65536 - FOSC / 115200 / 4)
#define NULL '1'

#define I2C_S0	0x10
#define I2C_S1	0x20
#define EAXFR	0x80

sbit SDA = P1^4;
sbit SCL = P1^5;

sbit Row1 = P1^6;
sbit Row2 = P1^5;
sbit Row3 = P1^4;
sbit Row4 = P1^3;
sbit Row5 = P1^2;


sbit COL1 = P3^6;
sbit COL2 = P3^7;
sbit COL3 = P2^0;
sbit COL4 = P2^1;
sbit COL5 = P2^2;
sbit COL6 = P2^3;
sbit COL7 = P2^4;
sbit COL8 = P2^5;
sbit COL9 = P2^6;
sbit COL10 = P2^7;

sbit Key1 = P3^3;
sbit Key2 = P3^2;

//0x01 NONE
//0x02 NUM
//0x03 ALT
//0x04 UPPER
//0x05 CTRL
//0x06 SHIFT
//0x07 ENTER
//0x08 DELETE
//0x09 YES
//0x10 No
code char keyboard[10][5] = {
{0x01,0x06,'a','q',0x01},
{0x01,'z','s','w',0x01},
{'0','x','d','e',0x01},
{' ','c','f','r',0x01},
{' ','v','g','t',0x01},
{0x03,'b','h','y',0x01},
{0x04,'n','j','u',0x01},
{0x05,'m','k','i',0x01},
{0x01,'\\','l','o',0x01},
{0x01,0x07,0x08,'p',0x01}
};
code char keyboardup[10][5] = {
{0X01,0X06,'A','Q',0X01},
{0X01,'Z','S','W',0X01},
{'0','X','D','E',0X01},
{' ','C','F','R',0X01},
{' ','V','G','T',0X01},
{0X03,'B','H','Y',0X01},
{0X04,'N','J','U',0X01},
{0X05,'M','K','I',0X01},
{0X01,'\\','L','O',0X01},
{0X01,0X07,0X08,'P',0X01}
};
code char keyboardnum[10][5] = {
{0x01,0x06,'*','#',0x01},
{0x01,'7','4','1',0x01},
{'0','8','5','2',0x01},
{' ','9','6','3',0x01},
{' ','?','/','(',0x01},
{0x03,'!',':',')',0x01},
{0x04,',',';','_',0x01},
{0x05,'.','\'','-',0x01},
{0x01,'~','\"','+',0x01},
{0x01,0x07,0x08,'@',0x01}
};

bit upMode = 0;
bit numMode = 0;

char lastkey = 0x00;
char lastkeydown;
bit busy;
char wptr;
char rptr;
char buffer[16];



void UartSend(char dat);
void GPIOInit(){
	P0M0 = 0x00;
	P0M1 = 0x00;
	P1M0 = 0x00;
	P1M1 = 0x00;
	P2M0 = 0x00;
	P2M1 = 0x00;
	P3M0 = 0x00;
	P3M1 = 0x00;
	P5M0 = 0x00;
	P5M1 = 0x00;
	
	Key1 = 1;
	Key2 = 1;
}
void ROWUpDown(bit a){
	Row1 = a;
	Row2 = a;
	Row3 = a;
	Row4 = a;
	Row5 = a;

}
void COLUpDown(bit a){
	COL1 = a;
	COL2 = a;
	COL3 = a;
	COL4 = a;
	COL5 = a;
	COL6 = a;
	COL7 = a;
	COL8 = a;
	COL9 = a;
	COL10 = a;
}
void KeyInit(){
	ROWUpDown(1);
	COLUpDown(0);
}
bit ifROWDown(){
	if(!(Row1&Row2&Row3&Row4&Row5)){
		delay_ms(10);
		if(!(Row1&Row2&Row3&Row4&Row5)){//(!(Row1&Row2&Row3&Row4&Row5&Row6&Row7)){
		return 1;
		}
	}
	else{
		return 0;
	}
}
void keyboardinit();
char KeyScan(){
	uchar Line1 = 0;
	uchar Line2 = 0;
	uchar Line3 = 0;
	uchar Line4 = 0;
	uchar P1old = 0x00;
	uchar originKey = 0x00;
	uchar finallyKey = 0x00;
	KeyInit();
	
	delay_ms(1);
	if(Key1 == 0){
		delay_ms(10);
		if(Key1 == 0){
			return 0x09;
		}
	}
	
	if(Key2 == 0){
		delay_ms(10);
		if(Key2 == 0){
			return 0x10;
		}
	}
	
	if(ifROWDown()){
		uchar i = 1;	
		if(!Row1){if(Line1 > 0){Line3 = 1;}else{Line1 = 1;}}
		if(!Row2){if(Line1 > 0){Line3 = 2;}else{Line1 = 2;}}
		if(!Row3){if(Line1 > 0){Line3 = 3;}else{Line1 = 3;}}
		if(!Row4){if(Line1 > 0){Line3 = 4;}else{Line1 = 4;}}
		if(!Row5){if(Line1 > 0){Line3 = 5;}else{Line1 = 5;}}
		
		P1old = P1;
		//P1 = 0x30 & P1old;
		for(i = 1;i < 11;i++){
			COLUpDown(1);
			if(i == 1)COL1 = 0;
			if(i == 2)COL2 = 0;
			if(i == 3)COL3 = 0;
			if(i == 4)COL4 = 0;
			if(i == 5)COL5 = 0;
			if(i == 6)COL6 = 0;
			if(i == 7)COL7 = 0;
			if(i == 8)COL8 = 0;
			if(i == 9)COL9 = 0;
			if(i == 10)COL10 = 0;
			delay_ms(1);
			if(Line1 == 1){if(!Row1){if(!Line2)Line2 = i;}}
			if(Line1 == 2){if(!Row2){if(!Line2)Line2 = i;}}
			if(Line1 == 3){if(!Row3){if(!Line2)Line2 = i;}}
			if(Line1 == 4){if(!Row4){if(!Line2)Line2 = i;}}
			if(Line1 == 5){if(!Row5){if(!Line2)Line2 = i;}}
		}
		COLUpDown(0);
		while(!(Row1&Row2&Row3&Row4&Row5));
		delay_ms(10);
		while(!(Row1&Row2&Row3&Row4&Row5));
		originKey = keyboard[Line2-1][Line1-1];
		if(originKey == 0x04){
			upMode = !upMode;
			return 0x00;
		}
		if(originKey == 0x03){
			numMode = !numMode;
			return 0x00;
		}
		else if(upMode == 1){
			finallyKey = keyboardup[Line2-1][Line1-1];
			return finallyKey;
		}
		else if(numMode == 1){
			finallyKey = keyboardnum[Line2-1][Line1-1];
			return finallyKey;
		}
		else{
			return keyboard[Line2-1][Line1-1];
		}
	}
	else{
		return 0x00;
	}
}




#ifdef USEUART2
void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;		//结构定义

	GPIO_InitStructure.Pin  = GPIO_Pin_6 | GPIO_Pin_7;		//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
	GPIO_InitStructure.Mode = GPIO_PullUp;	//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P4,&GPIO_InitStructure);	//初始化
}

/***************  串口初始化函数 *****************/
void	UART_config(void)
{
	COMx_InitDefine		COMx_InitStructure;					//结构定义
	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;		//模式,   UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
//	COMx_InitStructure.UART_BRT_Use   = BRT_Timer2;			//选择波特率发生器, BRT_Timer2 (注意: 串口2固定使用BRT_Timer2, 所以不用选择)
	COMx_InitStructure.UART_BaudRate  = 115200ul;			//波特率,     110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//接收允许,   ENABLE或DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//中断允许,   ENABLE或DISABLE
	COMx_InitStructure.UART_Priority    = Priority_0;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
	COMx_InitStructure.UART_P_SW      = UART2_SW_P10_P11;	//切换端口,   UART2_SW_P10_P11,UART2_SW_P46_P47
	UART_Configuration(UART2, &COMx_InitStructure);		//初始化串口2 UART1,UART2,UART3,UART4
}
#endif
#ifdef USEUART1
void	GPIO_config(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;		//结构定义

	GPIO_InitStructure.Pin  = GPIO_Pin_0 | GPIO_Pin_1;		//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
	GPIO_InitStructure.Mode = GPIO_PullUp;	//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
	GPIO_Inilize(GPIO_P3,&GPIO_InitStructure);	//初始化
}

/***************  串口初始化函数 *****************/
void	UART_config(void)
{
	COMx_InitDefine		COMx_InitStructure;					//结构定义
	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;	//模式, UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
	COMx_InitStructure.UART_BRT_Use   = BRT_Timer1;			//选择波特率发生器, BRT_Timer1, BRT_Timer2 (注意: 串口2固定使用BRT_Timer2)
	COMx_InitStructure.UART_BaudRate  = 115200ul;			//波特率, 一般 110 ~ 115200
	COMx_InitStructure.UART_RxEnable  = ENABLE;				//接收允许,   ENABLE或DISABLE
	COMx_InitStructure.BaudRateDouble = DISABLE;			//波特率加倍, ENABLE或DISABLE
	COMx_InitStructure.UART_Interrupt = ENABLE;				//中断允许,   ENABLE或DISABLE
	COMx_InitStructure.UART_Priority    = Priority_0;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
	COMx_InitStructure.UART_P_SW      = UART1_SW_P30_P31;	//切换端口,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17,UART1_SW_P43_P44
	UART_Configuration(UART1, &COMx_InitStructure);		//初始化串口1 UART1,UART2,UART3,UART4
}
#endif
/**********************************************/
void main(){
	GPIOInit();
	KeyInit();
	GPIO_config();
	UART_config();
	EA = 1;
	while(1){
		char a = KeyScan();
		if(lastkey != a){
			if(a!=0x00){
#ifdef USEUART1
				TX1_write2buff(a);
#endif
#ifdef USEUART2
				TX2_write2buff(a);
#endif
			}
			lastkey = a;
		}
	}
}
