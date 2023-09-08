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
File��ps2Ӧ�ó���
Author��pinggai    Version:1.1     Data:2015/10/20
Description: ps2Ӧ�ó����������ֵ
             �����¡�L1��ʱ��С�𶯵��ת�������¡�R1��ʱ�����𶯵��ת����			   
History:  
V1.0: 	2015/05/16
1���������ֵ��ģ��ֵ
**********************************************************/	 	 	  
int main(void)
{	
#ifdef TEST0	
	u8 key;  
	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72);	     //��ʱ��ʼ��
	uart_init(72,9600);  //����1��ʼ�� 
	LED_Init();
	PS2_Init();			 //�����˿ڳ�ʼ��
	PS2_SetInit();		 //�����ó�ʼ��,���á����̵�ģʽ������ѡ���Ƿ�����޸�
	                     //������ģʽ
#endif
	
#ifdef TEST1
	Stm32_Clock_Init(9);            //=====ϵͳʱ������
    delay_init(72);                 //=====��ʱ��ʼ��
    LED_Init();                     //=====��ʼ���� LED ���ӵ�Ӳ���ӿ�
    uart_init(72,9600);           	//=====����1��ʼ��
    delay_ms(1000);                 //=====��ʱ�ȴ���ʼ���ȶ�
    PS2_Init();						//=====ps2�����˿ڳ�ʼ��
    PS2_SetInit();		 			//=====ps2���ó�ʼ��,���á����̵�ģʽ������ѡ���Ƿ�����޸�
    delay_ms(1000);
#endif
	while(1)
	{
#ifdef TEST0
		////////////////////////////////////////////////////////
		//motor1:�Ҳ�С�𶯵�� 0x00�أ�������
	    //motor2:�����𶯵�� 0x40~0xFF �������ֵԽ�� ��Խ��
		////////////////////////////////////////////////////////
		LED =! LED;
		key=PS2_DataKey();
		if(key!=0)                   //�а�������
    	{
			printf("  \r\n   %d  is  light  \r\n",Data[1]);//ID
			printf("  \r\n   %d  is  pressed  \r\n",key);
			if(key == 11)//��L1
			{
				PS2_Vibration(0x00,0x41);//moter2������
				delay_ms(500);//�����𶯺��������ʱ  delay_ms(1000);
			}
			else if(key == 12)//��R1
			{
				PS2_Vibration(0x01,0x00);//moter1�Ҳ�С��
				delay_ms(500);//�����𶯺��������ʱ  delay_ms(1000);
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
            break;  //�������£�LED״̬��PC13���͵�ƽ��������ת
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
        printf("%d     PS2��X��:",PS2_LX);   //��ӡ���X���ֵ
        printf("%d     PS2��Y��:",PS2_LY);   //��ӡ�ұ�Y���ֵ
        printf("%d     PS2��X��:",PS2_RX);   //��ӡ���X���ֵ
        printf("%d     PS2��Y��:",PS2_RY);   //��ӡ�ұ�Y���ֵ
        printf("%d \r\nPS2����:",PS2_KEY);   //��ӡ������ֵ
        delay_ms(100);										   //��ʱ100m����
#endif
	}	 
}


