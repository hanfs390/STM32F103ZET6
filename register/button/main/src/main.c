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
        /* ����LED�Ƶ�״̬ */
        LED_SetState(ledState);

        /* ɨ�谴�� */
        keyValue = KEY_Scan();

        /* ���ݰ���ֵ�����ò�һ����LED״̬ */
        switch(keyValue)                        
        {
            case(KEY_UP):                                 //�ϰ�������
                if((ledState == 0xFF) | (ledState == 0))  //����ȫ����ȫ��
                {   
                    ledState = 0xFE;                      //����һյ��
                }
                else                                      //�����ƶ�
                {
                    ledState <<= 1;
                    ledState += 1;    
                }
                if(ledState == 0xFF)
                {
                    ledState = 0xFE;    
                }
                break;
                             
            case(KEY_DOWN):                               //�°�������        
                if((ledState == 0xFF) | (ledState == 0))  //����ȫ����ȫ��
                {   
                    ledState = 0x7F;                      //����һյ��
                }
                else                                      //�����ƶ�
                {
                    ledState >>= 1;
                    ledState |= 0x80;    
                }
                if(ledState == 0xFF)
                {
                    ledState = 0x7F;    
                }
                break;

            case(KEY_LEFT):                 //�󰴼�����
                ledState = 0;               //����ȫ����
                break;

            case(KEY_RIGHT):                //�Ұ�������
                ledState = 0xFF;            //Ϩ��ȫ����
                break;

            default:
                break;
        } // end of switch(keyValue)       
	}
}
