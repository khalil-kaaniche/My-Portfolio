/*
 * MAX30102.h
 *
 *  Created on: 27 nov. 2022
 *      Author: khalil
 */

#ifndef INC_MAX30102_H_
#define INC_MAX30102_H_

#include "main.h"
#include"string.h"
#include "MAX30102_Macros.h"

// Declare the used I2C handle
extern I2C_HandleTypeDef hi2c1;

#define POLLING						0U
#define IT							1U
#define DMA							2U
#define I2C_MODE					POLLING

#define USED_I2C_HANDLER			&hi2c1



void MAX30102_Write_Register(uint8_t reg,uint8_t value);

void MAX30102_Read_Register(uint8_t reg,uint8_t* Buffer);

void MAX30102_Read_N_Register(uint8_t reg,uint8_t* Buffer,uint8_t NumberOfRegisters);

void MAX30102_Bit_Mask_Register(uint8_t reg, uint8_t mask , uint8_t value);

void MAX30102_Clear();

void MAX30102_Reset();

void MAX30102_EnableSlot(uint8_t SlotNumber , uint8_t Device);

void MAX30102_Init();

void MAX30102_GetValues(uint32_t* RedBuffer,uint32_t* IrBuffer);

void MAX30102_HrAndSpo2(uint32_t* IR_Buffer,uint8_t IR_Buffer_Length,uint32_t* Red_Buffer,double* Spo2,double* Hr);



#endif /* INC_MAX30102_H_ */
