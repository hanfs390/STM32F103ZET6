#include "key.h"

/* 声明函数 */
static void KEY_Delay10ms(void);

/****************************************************************************
* Function Name  : KEY_Config
* Description    : 初始化按键是用的IO口
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

void KEY_Config(void)
{
	/*打开GPIOE的时钟*/
	RCC->APB2ENR |= 0x00000040;
    
    /* 设置PE2/PE3/PE4为上拉输入 */
    GPIOE->CRL &= 0xFFF000FF;
    GPIOE->CRL |= 0x00088800;
    GPIOE->ODR |= (0x07 << 2); 
    	          
#ifdef USE_KEY_UP
    /* 打开GPIOA的时钟 */  
    RCC->APB2ENR |= 0x00000004;
    
    /* PA0为下拉输入 */
    GPIOA->CRL &= 0xFFFFFFF0;
    GPIOA->CRL |= 0x00000008;
    GPIOA->ODR |= 0xFFFFFFFE;;

#endif
}

/****************************************************************************
* Function Name  : KEY_Delay10ms
* Description    : 按键使用的消抖延时函数。注意：该延时函数具体延时时间是不确
*                * 定的，并非真的就延时10ms，要精确延时请使用定时器。
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
* Description    : 按键扫描，注意该按键扫描支持一次按1个键，不支持同时按多个键
* Input          : None
* Output         : None
* Return         : keyValue：按键的键值
****************************************************************************/

u8 KEY_Scan(void)
{
    u8 keyValue = 0, timeCount = 0;

    if((KEY0 == 1) || (KEY1 == 0) || (KEY2 == 0) || (KEY3 == 0)) //检测是否有按键按下
    {
        KEY_Delay10ms();                                      //延时消抖

        /* 检测是哪个按键按下 */
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
        
        /* 有按键按下时，做松手检测 */
        if(keyValue != 0)
        {
            while(((KEY0 == 1) || (KEY1 == 0) || (KEY2 == 0) || (KEY3 == 0)) && (timeCount < 150))
            {
                KEY_Delay10ms();
                timeCount++;        
            }
            KEY_Delay10ms();//由于主函数中程序较少，连续扫描的速度太快，加一个松手消抖减少误读   
        }        
    }

    return keyValue;
}












