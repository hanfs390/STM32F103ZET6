#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

#define USE_KEY_UP  //如果按键使用上键

/* 按键读取 */
#define KEY0 (GPIOA->IDR & 0x01)
#define KEY1 ((GPIOE->IDR >> 2) & 0x01)
#define KEY2 ((GPIOE->IDR >> 3) & 0x01)
#define KEY3 ((GPIOE->IDR >> 4) & 0x01)

/* 定义按键的键值 */
#define KEY_UP    0x01
#define KEY_DOWN  0x02
#define KEY_LEFT  0x04
#define KEY_RIGHT 0x08

/* 声明全局函数 */
void KEY_Config(void);
u8 KEY_Scan(void);






#endif
