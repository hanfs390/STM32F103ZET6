#include <stm32f10x.h>
#include "system.h"
#include "beep.h"

/****************************************************************************
* Function Name  : main
* Description    : Main program.
* Input          : None
* Output         : None
* Return         : None
****************************************************************************/

int main(void)
{
	SYSTEM_SetClock(72);
	BEEP_Config();
	while (1) {
		BEEP_Work();

	}
}
