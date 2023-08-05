#ifndef INC_MS5611_H_
#define INC_MS5611_H_

#include "stdio.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_i2c.h"

extern  I2C_HandleTypeDef hi2c1;
#define MS5611_I2C &hi2c1

#define MS5611_ADRESS 0xEE			//CSB is GND, 7 bit address is 0x77, 8 bit address 0x77<<1 = 0xEE
									//CSB is VCC, 7 bit address is 0x76, 8 bit address 0x76<<1 = 0xEC

#define MS5611_CMD_RESET 				0X1E
#define MS5611_CMD_CONVERT_D1_256 		0x40
#define MS5611_CMD_CONVERT_D1_512 		0x42
#define MS5611_CMD_CONVERT_D1_1024 		0x44
#define MS5611_CMD_CONVERT_D1_2048 		0x46
#define MS5611_CMD_CONVERT_D1_4096 		0x48
#define MS5611_CMD_CONVERT_D2_256 		0x50
#define MS5611_CMD_CONVERT_D2_512 		0x52
#define MS5611_CMD_CONVERT_D2_1024 		0x54
#define MS5611_CMD_CONVERT_D2_2048 		0x56
#define MS5611_CMD_CONVERT_D2_4096 		0x58
#define MS6511_ADC_READ 				0x00
#define MS5611_PROM_READ_0 				0xA0
#define MS5611_PROM_READ_1 				0xA2
#define MS5611_PROM_READ_2 				0xA4
#define MS5611_PROM_READ_3 				0xA6
#define MS5611_PROM_READ_4 				0xA8
#define MS5611_PROM_READ_5 				0xAA
#define MS5611_PROM_READ_6 				0xAC
#define MS5611_PROM_READ_7 				0xAE

typedef struct MS5611_t
{
	unsigned short *reserve;
	unsigned short *crc;
	unsigned short C[6];
	unsigned int D[2];
	signed long long dT;
	signed long long OFF;
	signed long long SENS;
	signed int TEMP;
	signed int P;
}*ms5611_handle;

void MS5611_Reset();
int MS5611_Init();
int MS5611_Calibration();
int MS5611_read_temp();
int MS5611_read_press();
int MS5611_calculate();

#endif /* INC_MS5611_H_ */
