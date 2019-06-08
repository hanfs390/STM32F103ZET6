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
    GPIO_InitTypeDef GPIO_InitStructure;

    /* ����GPIOʱ�� */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
    
    /*  ����GPIO��ģʽ��IO�� */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_KEY;        //ѡ����Ҫ���õ�IO��
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //���ô�������
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;      //������������ģʽ

    /* ��ʼ��GPIO */
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    	          
#ifdef USE_KEY_UP 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    /* PA0 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;          //ѡ����Ҫ���õ�IO��
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;      //������������ģʽ

    GPIO_Init(GPIOA, &GPIO_InitStructure);
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
    uint16_t i;
    for(i=0; i<0x5FFF; i++);
}

/****************************************************************************
* Function Name  : KEY_Scan
* Description    : ����ɨ�裬ע��ð���ɨ��֧��һ�ΰ�1��������֧��ͬʱ�������
* Input          : None
* Output         : None
* Return         : keyValue�������ļ�ֵ
****************************************************************************/

uint8_t KEY_Scan(void)
{
    uint8_t keyValue = 0, timeCount = 0;

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
//            KEY_Delay10ms();//�����������г�����٣�����ɨ����ٶ�̫�죬��һ�����������������   
        }        
    }

    return keyValue;
}












