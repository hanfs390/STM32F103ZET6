#include "key.h"

/* �������� */
static void KEY_Delay10ms(void);

/****************************************************************************
* Function Name  : KEY_Config
* Description    : ��ʼ���������õ�IO��
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void KEY_Config(void)
{
	/*��GPIOE��ʱ��*/
	RCC->APB2ENR |= 0x00000040;
    
    /* ����PE2/PE3/PE4Ϊ�������� */
    GPIOE->CRL &= 0xFFF000FF;
    GPIOE->CRL |= 0x00088800;
    GPIOE->ODR |= (0x07 << 2); 
    	          
#ifdef USE_KEY_UP
    /* ��GPIOA��ʱ�� */  
    RCC->APB2ENR |= 0x00000004;
    
    /* PA0Ϊ�������� */
    GPIOA->CRL &= 0xFFFFFFF0;
    GPIOA->CRL |= 0x00000008;
    GPIOA->ODR |= 0xFFFFFFFE;;

#endif
}

/****************************************************************************
* Function Name  : KEY_Delay10ms
* Description    : ����ʹ�õ�������ʱ������ע�⣺����ʱ����������ʱʱ���ǲ�ȷ
*                * ���ģ�������ľ���ʱ10ms��Ҫ��ȷ��ʱ��ʹ�ö�ʱ����
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

static void KEY_Delay10ms(void)
{
    u16 i;
    for(i=0; i<0x5FFF; i++);
}

/****************************************************************************
* Function Name  : KEY_Scan
* Description    : ����ɨ�裬ע��ð���ɨ��֧��һ�ΰ�1��������֧��ͬʱ�������
* Input          : None
* Output         : None
* Return         : keyValue�������ļ�ֵ
****************************************************************************/

u8 KEY_Scan(void)
{
    u8 keyValue = 0, timeCount = 0;

    if((KEY0 == 1) || (KEY1 == 0) || (KEY2 == 0) || (KEY3 == 0)) //����Ƿ��а�������
    {
        KEY_Delay10ms();                                      //��ʱ����

        /* ������ĸ��������� */
        if(KEY0 == 1)
        {
            keyValue = KEY_UP;
        }
        else if(KEY1 == 0)
        {
            keyValue = KEY_LEFT;
        }
        else if(KEY2 == 0)
        {
            keyValue = KEY_DOWN;
        }
        else if(KEY3 == 0)
        {
            keyValue = KEY_RIGHT;
        }
        else
        {
            keyValue = 0;
        }
        
        /* �а�������ʱ�������ּ�� */
        if(keyValue != 0)
        {
            while(((KEY0 == 1) || (KEY1 == 0) || (KEY2 == 0) || (KEY3 == 0)) && (timeCount < 150))
            {
                KEY_Delay10ms();
                timeCount++;        
            }
            KEY_Delay10ms();//�����������г�����٣�����ɨ����ٶ�̫�죬��һ�����������������   
        }        
    }

    return keyValue;
}












