/*
 * MyDsp.h
 *
 *  Created on: Nov 28, 2022
 *      Author: khalil
 */

#ifndef INC_MYDSP_H_
#define INC_MYDSP_H_

#include"CircularBuffer.h"

#define MAX_ORDER				MAX_BUFFER-1

typedef struct
{
	double* Coeff;
	uint16_t Order;
}FIR_Filter;

typedef struct
{
	double* CoeffNum;
	double* CoeffDenum;
	uint16_t SizeNum;
	uint16_t SizeDenum;
}IIR_Filter;

uint8_t IIR_Init(IIR_Filter* IIR,uint16_t SizeNum, double* CoeffNum,uint16_t SizeDenum, double* CoeffDenum);

double IIR_Calculate(IIR_Filter* IIR,Circular_Buffer* Input,Circular_Buffer* Output);

uint8_t FIR_Init(FIR_Filter* FIR,uint16_t Size, double* Coeff);

double FIR_Calculate(FIR_Filter* FIR,Circular_Buffer* Input);

void FIR_CalculateV2(FIR_Filter* FIR,Circular_Buffer* Input,double* Val);

void FIR_MvgAvgInit(FIR_Filter* FIR,uint16_t Size);

void DSP_Extremum(double Input,double * Max , double * Min , double * Freq);

void DSP_ExtremumV2(double Input,double * Max , double * Min , double * Freq);

void DSP_ExtremumV3(double Input,double * Max , double * Min , double * Freq);

void DSP_ExtremumV4(double Input,double * Max , double * Min , double * Freq);

#endif /* INC_MYDSP_H_ */
