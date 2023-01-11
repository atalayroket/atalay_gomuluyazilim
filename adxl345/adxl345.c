#include "adxl345.h"

void ADXL345_ScanAdress(void)
{
	for(int i=0; i<=255; i++)
	{
		if(HAL_I2C_IsDeviceReady(ADXL345_I2C, i, 1, 10) == HAL_OK)
			break;
	}
}

void ADXL345_Init(void)
{
	ADXL345_Read(DEVID_ID, 1);
	ADXL345_Write(POWER_CTL, 0);
	ADXL345_Write(POWER_CTL, 0x08);      //Measure Bit SET
	ADXL345_Write(DATA_FORMAT, 0x01);      //Range Bit +-4g
}

void ADXL345_Write(uint8_t rRegister, uint8_t value)
{
	uint8_t data[2] = {0};
	data[0] = rRegister;
	data[1] = value;

	HAL_I2C_Master_Transmit(ADXL345_I2C, ADXL345_ADDRESS, data, 2, 100);
}

void ADXL345_Read(uint8_t rRegister, uint8_t numberOfBytes)
{
	HAL_I2C_Mem_Read(ADXL345_I2C, ADXL345_ADDRESS, rRegister, 1, myDatas, numberOfBytes, 100);
}

void ADXL345_AccelRead(void)
{
	 ADXL345_Read(DATAX0, 6);

	 x= (myDatas[1] << 8) | myDatas[0];
	 y= (myDatas[3] << 8) | myDatas[2];
	 z= (myDatas[5] << 8) | myDatas[4];

	 xg = x * .0078;
	 yg = y * .0078;
	 zg = z * .0078;
}

