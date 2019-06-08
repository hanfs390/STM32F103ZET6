#include "led.h"


/****************************************************************************
* Function Name  : LED_Config
* Description    : ��LEDʹ�õ�IO������Ϊͨ���������
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void LED_Config(void)
{

	/*��GPIOC��ʱ��*/
	RCC->APB2ENR |= 0x00000010;

    /* ����GPIOC�ĵ�8λΪͨ��������� */
    GPIOC->CRL |= 0x33333333;
    
    /* ��ʼ��ΪIo�� */
    GPIOC->ODR |= 0xFF00; 
}

/****************************************************************************
* Function Name  : LED_SetState
* Description    : ����LED��״̬��0������Ӧ��LED������1��ʾ��Ӧ��LEDϨ��
* Input          : stateValue��LED��״̬
* Output         : None
* Return         : None
****************************************************************************/

void LED_SetState(u8 stateValue)
{    
    /* ����LED�Ƶ�״̬, GPIOһ������16λ������ֵǿ��ת��λ16λ */
    GPIOC->BSRR = (u16)stateValue & 0x00FF;
    GPIOC->BRR =  ~((u16)stateValue & 0x00FF);                  
}



