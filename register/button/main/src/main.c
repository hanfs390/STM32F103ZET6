#include <stm32f10x.h>
#include "system.h"
#include "led.h"
#include "key.h"

/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

int main(void)
{
    u8 ledState = 0, keyValue = 0;

    SYSTEM_SetClock(72);
    LED_Config();             
    KEY_Config();

	while(1)
	{
        /* 设置LED灯的状态 */
        LED_SetState(ledState);

        /* 扫描按键 */
        keyValue = KEY_Scan();

        /* 根据按键值，设置不一样的LED状态 */
        switch(keyValue)                        
        {
            case(KEY_UP):                                 //上按键按下
                if((ledState == 0xFF) | (ledState == 0))  //若灯全亮或全灭
                {   
                    ledState = 0xFE;                      //点亮一盏灯
                }
                else                                      //否则移动
                {
                    ledState <<= 1;
                    ledState += 1;    
                }
                if(ledState == 0xFF)
                {
                    ledState = 0xFE;    
                }
                break;
                             
            case(KEY_DOWN):                               //下按键按下        
                if((ledState == 0xFF) | (ledState == 0))  //若灯全亮或全灭
                {   
                    ledState = 0x7F;                      //点亮一盏灯
                }
                else                                      //否则移动
                {
                    ledState >>= 1;
                    ledState |= 0x80;    
                }
                if(ledState == 0xFF)
                {
                    ledState = 0x7F;    
                }
                break;

            case(KEY_LEFT):                 //左按键按下
                ledState = 0;               //点亮全部灯
                break;

            case(KEY_RIGHT):                //右按键按下
                ledState = 0xFF;            //熄灭全部灯
                break;

            default:
                break;
        } // end of switch(keyValue)       
	}
}
