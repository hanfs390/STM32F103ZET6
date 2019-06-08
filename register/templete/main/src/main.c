#include <stm32f10x.h>
#include "system.h"
#include "led.h"

/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

int main(void)
{
    u32 i,j;
    u8 ledState;
	  int x[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

    SYSTEM_SetClock(72);
    LED_Config();                     //����IO�ڵ�ģʽ
    //ledState = 0x00;                  //��ʼ��LED��״̬
	while(1)
	{
       //LED_SetState(ledState);       //����LED
        //for(i=0; i<0x000FFFFF; i++);  //��ʱ
        
        /* ��ˮ�����ݴ��� */
        //ledState <<= 1;               //�൱�� ledState = ledState << 1;
        //ledState += 1;                //�൱�� ledState = ledState + 1;
        //if(ledState == 0xFF)          //����ˮ�Ƶ�������ͷʱ
       // {
            /* ����LED����˸һ�� */
            //LED_SetState(0x00);    //LED������
            //for(i=0; i<0x00FFFFFF; i++);  //��ʱ
           // LED_SetState(0xFF);    //LED��Ϩ��
            //for(i=0; i<0x000FFFFFF; i++);  //��ʱ
            //LED_SetState(0x00);    //LED��Ϩ��
           // for(i=0; i<0x000FFFFFF; i++);  //��ʱ
            //LED_SetState(0xFF);    //LED��Ϩ��
            //ledState = 0xFE;              //����������ˮ��״̬
					for(j=0;j<10;j++)
					{
					  ledState =  x[j];
						LED_SetState(ledState);
						for(i=0; i<0x000FFFFFF; i++);
					}
        //}
	}
}
