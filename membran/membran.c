#include "membran.h"

static Membran_TypeDef_t MembranStruct;

void Membran_Read(Membran_TypeDef_t* MembranWiringStruct, bool button[4])
{
	MembranStruct = *MembranWiringStruct;

	button[0] = HAL_GPIO_ReadPin(MembranStruct.MENU_Port, MembranStruct.MENU_Pin);
	button[1] = HAL_GPIO_ReadPin(MembranStruct.MINUS_Port, MembranStruct.MINUS_Pin);
	button[2] = HAL_GPIO_ReadPin(MembranStruct.PLUS_Port, MembranStruct.PLUS_Pin);
	button[3] = HAL_GPIO_ReadPin(MembranStruct.EXIT_Port, MembranStruct.EXIT_Pin);
}
