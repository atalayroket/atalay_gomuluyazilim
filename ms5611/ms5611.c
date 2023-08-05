#include "ms5611.h"

extern uint8_t Data;

MS5611_Calibration()
{
	ms5611_handle = (struct MS5611_t *)malloc(sizeof(struct MS5611_t));
	ms5611_handle->reserve = (unsigned short *)malloc(sizeof(unsigned short));
	ms5611_handle->crc = (unsigned short *)malloc(sizeof(unsigned short));

	ms5611_handle->C[0] = 0;
	ms5611_handle->C[1] = 0;
	ms5611_handle->C[2] = 0;
	ms5611_handle->C[3] = 0;
	ms5611_handle->C[4] = 0;
	ms5611_handle->C[5] = 0;

	ms5611_handle->D[0] = 0;
	ms5611_handle->D[1] = 0;

	ms5611_handle->TEMP = 0;
	ms5611_handle->P = 0;
	ms5611_handle->SENS = 0;
	ms5611_handle->OFF = 0;
}

void MS5611_Reset(){
	Data = 0x00;
	HAL_I2C_Mem_Write(MS5611_I2C, MS5611_ADRESS, MS5611_CMD_RESET, 1, &Data, 1, 100);
}

void MS5611_ReadProm(){
	Data = 0x00;
	HAL_I2C_Mem_Write(MS5611_I2C, MS5611_ADRESS, MS5611_CMD_RESET, 1, &Data, 1, 100);
}

int MS5611_Init()
{
	MS5611_Calibration();
	MS5611_Reset();
	HAL_I2C_Mem_Read(MS5611_I2C, MS5611_ADRESS, MS5611_PROM_READ_0, 1, gyroData, 6, 100);
}
