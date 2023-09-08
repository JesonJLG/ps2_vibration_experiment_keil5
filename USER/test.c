#include "sys.h"
#include "usart.h"		
#include "delay.h"
#include "led.h"	
#include "pstwo.h"

#define TEST0
//#define TEST1

int PS2_LX,PS2_LY,PS2_RX,PS2_RY,PS2_KEY;
/*********************************************************
Copyright (C), 2015-2025, YFRobot.
www.yfrobot.com
File：ps2应用程序
Author：pinggai    Version:1.1     Data:2015/10/20
Description: ps2应用程序输出按键值
             当按下“L1”时，小震动电机转动，按下“R1”时，大震动电机转动。			   
History:  
V1.0: 	2015/05/16
1、输出按键值，模拟值
**********************************************************/	 	 	  
int main(void)
{	
#ifdef TEST0	
	u8 key;  
	Stm32_Clock_Init(9); //系统时钟设置
	delay_init(72);	     //延时初始化
	uart_init(72,9600);  //串口1初始化 
	LED_Init();
	PS2_Init();			 //驱动端口初始化
	PS2_SetInit();		 //配配置初始化,配置“红绿灯模式”，并选择是否可以修改
	                     //开启震动模式
#endif
	
#ifdef TEST1
	Stm32_Clock_Init(9);            //=====系统时钟设置
    delay_init(72);                 //=====延时初始化
    LED_Init();                     //=====初始化与 LED 连接的硬件接口
    uart_init(72,9600);           	//=====串口1初始化
    delay_ms(1000);                 //=====延时等待初始化稳定
    PS2_Init();						//=====ps2驱动端口初始化
    PS2_SetInit();		 			//=====ps2配置初始化,配置“红绿灯模式”，并选择是否可以修改
    delay_ms(1000);
#endif
	while(1)
	{
#ifdef TEST0
		////////////////////////////////////////////////////////
		//motor1:右侧小震动电机 0x00关，其他开
	    //motor2:左侧大震动电机 0x40~0xFF 电机开，值越大 震动越大
		////////////////////////////////////////////////////////
		LED =! LED;
		key=PS2_DataKey();
		if(key!=0)                   //有按键按下
    	{
			printf("  \r\n   %d  is  light  \r\n",Data[1]);//ID
			printf("  \r\n   %d  is  pressed  \r\n",key);
			if(key == 11)//左L1
			{
				PS2_Vibration(0x00,0x41);//moter2左侧大震动
				delay_ms(500);//发出震动后必须有延时  delay_ms(1000);
			}
			else if(key == 12)//右R1
			{
				PS2_Vibration(0x01,0x00);//moter1右侧小震动
				delay_ms(500);//发出震动后必须有延时  delay_ms(1000);
			}
			else
				 PS2_Vibration(0x00,0x00); 
    	}
		printf(" %5d %5d %5d %5d\r\n",PS2_AnologData(PSS_LX),PS2_AnologData(PSS_LY),
		                              PS2_AnologData(PSS_RX),PS2_AnologData(PSS_RY) );
		delay_ms(50);
#endif

#ifdef TEST1
        PS2_LX=PS2_AnologData(PSS_LX);
        PS2_LY=PS2_AnologData(PSS_LY);
        PS2_RX=PS2_AnologData(PSS_RX);
        PS2_RY=PS2_AnologData(PSS_RY);
        PS2_KEY=PS2_DataKey();
        switch(PS2_KEY)
        {
        case 1:
            LED = !LED;
            break;  //按键按下，LED状态（PC13，低电平点亮）反转
        case 2:
            LED = !LED;
            break;
        case 3:
            LED = !LED;
            break;
        case 4:
            LED = !LED;
            break;
        case 5:
            LED = !LED;
            break;
        case 6:
            LED = !LED;
            break;
        case 7:
            LED = !LED;
            break;
        case 8:
            LED = !LED;
            break;
        case 9:
            LED = !LED;
            break;
        case 10:
            LED = !LED;
            break;
        case 11:
            LED = !LED;
            break;
        case 12:
            LED = !LED;
            break;
        case 13:
            LED = !LED;
            break;
        case 14:
            LED = !LED;
            break;
        case 15:
            LED = !LED;
            break;
        case 16:
            LED = !LED;
            break;
        }
        printf("%d     PS2左X轴:",PS2_LX);   //打印左边X轴的值
        printf("%d     PS2左Y轴:",PS2_LY);   //打印右边Y轴的值
        printf("%d     PS2右X轴:",PS2_RX);   //打印左边X轴的值
        printf("%d     PS2右Y轴:",PS2_RY);   //打印右边Y轴的值
        printf("%d \r\nPS2按键:",PS2_KEY);   //打印按键的值
        delay_ms(100);										   //延时100m秒钟
#endif
	}	 
}


