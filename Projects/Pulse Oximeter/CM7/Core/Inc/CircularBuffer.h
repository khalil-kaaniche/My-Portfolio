/*
 * CircularBuffer.h
 *
 *  Created on: Nov 28, 2022
 *      Author: khalil
 */

#ifndef INC_CIRCULARBUFFER_H_
#define INC_CIRCULARBUFFER_H_

#include "stdint.h"
#include "stdlib.h"

#define MAX_BUFFER				10000

typedef struct
{
	double* Buffer;
	uint16_t Write_u16;
	uint16_t Read_u16;
	uint16_t Size_u16;
}Circular_Buffer;

uint8_t CircBuff_Init(Circular_Buffer* CircBuff,uint16_t Size);

void CircBuff_Write(Circular_Buffer* CircBuff,double Data);

double CircBuff_Backward_Read(Circular_Buffer* CircBuff);

double CircBuff_Read(Circular_Buffer* CircBuff);

void CircBuff_Destroy(Circular_Buffer* CircBuff);

#endif /* INC_CIRCULARBUFFER_H_ */
