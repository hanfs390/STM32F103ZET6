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
    LED_Config();                     //配置IO口的模式
    //ledState = 0x00;                  //初始化LED的状态
	while(1)
	{
       //LED_SetState(ledState);       //设置LED
        //for(i=0; i<0x000FFFFF; i++);  //延时
        
        /* 流水灯数据处理 */
        //ledState <<= 1;               //相当于 ledState = ledState << 1;
        //ledState += 1;                //相当于 ledState = ledState + 1;
        //if(ledState == 0xFF)          //当流水灯点亮到尽头时
       // {
            /* 所有LED都闪烁一下 */
            //LED_SetState(0x00);    //LED都点亮
            //for(i=0; i<0x00FFFFFF; i++);  //延时
           // LED_SetState(0xFF);    //LED都熄灭
            //for(i=0; i<0x000FFFFFF; i++);  //延时
            //LED_SetState(0x00);    //LED都熄灭
           // for(i=0; i<0x000FFFFFF; i++);  //延时
            //LED_SetState(0xFF);    //LED都熄灭
            //ledState = 0xFE;              //重新设置流水灯状态
					for(j=0;j<10;j++)
					{
					  ledState =  x[j];
						LED_SetState(ledState);
						for(i=0; i<0x000FFFFFF; i++);
					}
        //}
	}
}
