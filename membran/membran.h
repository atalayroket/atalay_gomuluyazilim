#ifndef INC_MEMBRAN_H_
#define INC_MEMBRAN_H_

#include "stm32f4xx_hal.h"
#include <stdbool.h>

typedef struct
{
	GPIO_TypeDef* MENU_Port;
	GPIO_TypeDef* MINUS_Port;
	GPIO_TypeDef* PLUS_Port;
	GPIO_TypeDef* EXIT_Port;

	uint16_t	MENU_Pin;
	uint16_t	MINUS_Pin;
	uint16_t	PLUS_Pin;
	uint16_t	EXIT_Pin;

}Membran_TypeDef_t;

void Membran_Read(Membran_TypeDef_t* MembranWiringStruct ,bool button[4]);

#endif /* INC_MEMBRAN_H_ */
