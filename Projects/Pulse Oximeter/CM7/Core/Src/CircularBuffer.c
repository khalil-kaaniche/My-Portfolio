/*
 * CircularBuffer.c
 *
 *  Created on: Nov 28, 2022
 *      Author: khalil
 */


#include "CircularBuffer.h"

uint8_t CircBuff_Init(Circular_Buffer* CircBuff,uint16_t Size)
{

	uint8_t RetVal_u8 = 0;
	if(Size<MAX_BUFFER){
		CircBuff->Write_u16 = 0;
		CircBuff->Read_u16 = 0;
		CircBuff->Size_u16 = Size;
		CircBuff->Buffer = (double*)malloc(sizeof(double)*CircBuff->Size_u16);
		for(uint16_t i = 0 ; i<Size;i++)
		{
			CircBuff->Buffer[i] = 0;
		}
		RetVal_u8=1;
	}
	return RetVal_u8;
}



void CircBuff_Destroy(Circular_Buffer* CircBuff)
{
	free(CircBuff->Buffer);
}

void CircBuff_Write(Circular_Buffer* CircBuff,double Data)
{
	CircBuff->Buffer[CircBuff->Write_u16]=Data;
	CircBuff->Write_u16++;
	if(CircBuff->Write_u16==CircBuff->Size_u16)
	{
		CircBuff->Write_u16 = 0 ;
	}
}

double CircBuff_Backward_Read(Circular_Buffer* CircBuff)
{

	double Result = CircBuff->Buffer[CircBuff->Read_u16];
	if(CircBuff->Read_u16==0){
		CircBuff->Read_u16=(CircBuff->Size_u16)-1;
	}
	else{
		CircBuff->Read_u16--;
	}
	return Result;

}

double CircBuff_Read(Circular_Buffer* CircBuff)
{

	double Result = CircBuff->Buffer[CircBuff->Read_u16];
	CircBuff->Read_u16++;
	if(CircBuff->Read_u16==CircBuff->Size_u16)
	{
		CircBuff->Read_u16=0;
	}
	return Result;

}
