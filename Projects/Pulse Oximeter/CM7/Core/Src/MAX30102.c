/*
 * MAX30102.c
 *
 *  Created on: 27 nov. 2022
 *      Author: khalil
 */


#include "MAX30102.h"

// Variables
uint8_t TxBuffer_au8[2] = {0};
uint8_t RxBuffer_au8[32] = {0};
uint8_t DeviceID_u8 = 0;
int32_t an_x[100]={0}; // IR
int32_t an_y[100]={0}; // RED


void MAX30102_Write_Register(uint8_t reg,uint8_t value)
{
	TxBuffer_au8[0] = reg ;
	TxBuffer_au8[1] = value ;
#if (I2C_MODE == POLLING)
	HAL_I2C_Master_Transmit(USED_I2C_HANDLER, MAX30102_I2C_Write, &TxBuffer_au8[0], 2, HAL_MAX_DELAY);
#elif(I2C_MODE == IT)

#else

#endif
}
void MAX30102_Read_Register(uint8_t reg,uint8_t* Buffer)
{
	TxBuffer_au8[0] = reg;
#if (I2C_MODE == POLLING)
	HAL_I2C_Master_Transmit(USED_I2C_HANDLER, MAX30102_I2C_Read, &TxBuffer_au8[0], 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(USED_I2C_HANDLER, MAX30102_I2C_Read, Buffer, 1, HAL_MAX_DELAY);
#elif(I2C_MODE == IT)

#else

#endif
}
void MAX30102_Read_N_Register(uint8_t reg,uint8_t* Buffer,uint8_t NumberOfRegisters)
{
	TxBuffer_au8[0] = reg;
#if (I2C_MODE == POLLING)
	HAL_I2C_Master_Transmit(USED_I2C_HANDLER, MAX30102_I2C_Read, &TxBuffer_au8[0], 1, HAL_MAX_DELAY);
	HAL_I2C_Master_Receive(USED_I2C_HANDLER, MAX30102_I2C_Read, Buffer, NumberOfRegisters, HAL_MAX_DELAY);
#elif(I2C_MODE == IT)

#else

#endif
}
void MAX30102_Bit_Mask_Register(uint8_t reg, uint8_t mask , uint8_t value)
{
	uint8_t Temp_u8;
	MAX30102_Read_Register(reg, &Temp_u8);
	Temp_u8 = (Temp_u8 & mask)|value ;
	MAX30102_Write_Register(reg, Temp_u8);
}

void MAX30102_Clear()
{
	MAX30102_Read_Register(MAX30102_INTSTAT1, &RxBuffer_au8[0]);
	MAX30102_Read_Register(MAX30102_INTSTAT2, &RxBuffer_au8[0]);
	MAX30102_Write_Register(MAX30102_FIFOWRITEPTR, 0);
	MAX30102_Write_Register(MAX30102_FIFOOVERFLOW, 0);
	MAX30102_Write_Register(MAX30102_FIFOREADPTR, 0);
}

void MAX30102_Reset()
{
	MAX30102_Bit_Mask_Register(MAX30102_MODECONFIG, MAX30102_RESET_MASK, MAX30102_RESET);
}

void MAX30102_EnableSlot(uint8_t SlotNumber , uint8_t Device)
{
	switch(SlotNumber)
	{
		case (1):
		{
			MAX30102_Bit_Mask_Register(MAX30102_MULTILEDCONFIG1, MAX30102_SLOT1_MASK, Device);
		}break;
		case (2):
		{
			MAX30102_Bit_Mask_Register(MAX30102_MULTILEDCONFIG1, MAX30102_SLOT2_MASK, Device << 4);
		}break;
		case (3):
		{
			MAX30102_Bit_Mask_Register(MAX30102_MULTILEDCONFIG2, MAX30102_SLOT3_MASK, Device);
		}break;
		case (4):
		{
			MAX30102_Bit_Mask_Register(MAX30102_MULTILEDCONFIG2, MAX30102_SLOT4_MASK, Device << 4);
		}break;
		default:
		{

		}break;
	}
}

void MAX30102_Init()
{

	MAX30102_Read_Register(MAX30102_PARTID, &DeviceID_u8);

	MAX30102_Reset();

	// Sample Average = 1		// 4
	MAX30102_Bit_Mask_Register(MAX30102_FIFOCONFIG, MAX30102_SAMPLEAVG_MASK, MAX30102_SAMPLEAVG_1);

	// Enable FIFO Rollover
	MAX30102_Bit_Mask_Register(MAX30102_FIFOCONFIG, MAX30102_ROLLOVER_MASK, MAX30102_ROLLOVER_ENABLE);

	// LED Mode = SpO2 Moade
	MAX30102_Bit_Mask_Register(MAX30102_MODECONFIG, MAX30102_MODE_MASK, MAX30102_MODE_REDIRONLY);

	// ADC Range = 4096
	MAX30102_Bit_Mask_Register(MAX30102_SPO2, MAX30102_ADCRANGE_MASK, MAX30102_ADCRANGE_4096);

	// Sample Rate = 1000		// 100
	MAX30102_Bit_Mask_Register(MAX30102_SPO2, MAX30102_SAMPLERATE_MASK, MAX30102_SAMPLERATE_1000);

	// Pulse Width =  69		// 411
	MAX30102_Bit_Mask_Register(MAX30102_SPO2, MAX30102_PULSEWIDTH_MASK, MAX30102_PULSEWIDTH_69);

	// Power Level
	uint8_t value = 60 ;
	MAX30102_Write_Register(MAX30102_LED1_PULSEAMP, value);
	MAX30102_Write_Register(MAX30102_LED2_PULSEAMP, value);

	// Enable the reading of the 2 LEDs
	MAX30102_EnableSlot(1,SLOT_RED_LED);
	MAX30102_EnableSlot(2,SLOT_IR_LED);

	// Clear the FIFO
	MAX30102_Clear();

}

void MAX30102_GetValues(uint32_t* RedBuffer,uint32_t* IrBuffer)
{
	MAX30102_Clear();
	MAX30102_Read_N_Register(MAX30102_FIFODATA, &RxBuffer_au8[0], 6);
	uint8_t Temp[4]={0};
	Temp[3] = 0 ;
	Temp[2] = RxBuffer_au8[0];
	Temp[1] = RxBuffer_au8[1];
	Temp[0] = RxBuffer_au8[2];
	memcpy(RedBuffer,Temp,sizeof(*RedBuffer));
	*RedBuffer &= 0x3FFFF;
	Temp[3] = 0 ;
	Temp[2] = RxBuffer_au8[3];
	Temp[1] = RxBuffer_au8[4];
	Temp[0] = RxBuffer_au8[5];
	memcpy(IrBuffer,Temp,sizeof(*IrBuffer));

//	*RedBuffer = (RxBuffer_au8[2]|(RxBuffer_au8[1]<<8)|((RxBuffer_au8[0]&0b11)<<16))>>3;
//	*IrBuffer = (RxBuffer_au8[5]|(RxBuffer_au8[4]<<8)|((RxBuffer_au8[3]&0b11)<<16))>>3;
}


