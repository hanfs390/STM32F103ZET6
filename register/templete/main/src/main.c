#include <stm32f10x.h>
#include "system.h"

/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

int main(void)
{
	SYSTEM_SetClock(72); /* init clock is 72 MHz */
}
