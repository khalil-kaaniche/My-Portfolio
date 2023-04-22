/*
 * MyDsp.c
 *
 *  Created on: Nov 28, 2022
 *      Author: khalil
 */


#include"MyDsp.h"

uint64_t Tsig = 0 ;
uint64_t Tsig2 = 0 ;
double Frequence = 0 ;
double Maxim = 0 ;
double Minim = 0 ;

double Frequence2 = 0 ;
double Maxim2 = 0 ;
double Minim2 = 0 ;

double Spo2 = 0 ;

uint8_t IIR_Init(IIR_Filter* IIR,uint16_t SizeNum, double* CoeffNum,uint16_t SizeDenum, double* CoeffDenum)
{
	uint8_t RetVal_u8 = 0;

	IIR->CoeffDenum =(double*) malloc(sizeof(double)*SizeDenum);
	IIR->CoeffNum =(double*) malloc(sizeof(double)*SizeNum);
	IIR->SizeDenum = SizeDenum;
	IIR->SizeNum = SizeNum;
	for(uint16_t i=0;i<SizeDenum;i++)
	{
		IIR->CoeffDenum[i] = CoeffDenum[i];
	}
	for(uint16_t i=0;i<SizeNum;i++)
	{

		IIR->CoeffNum[i] = CoeffNum[i];
	}
	RetVal_u8 =1;

	return RetVal_u8;
}

double IIR_Calculate(IIR_Filter* IIR,Circular_Buffer* Input,Circular_Buffer* Output)
{
	double output =0;
	if( Input->Write_u16 == 0)
	{
		Input->Read_u16 = Input->Size_u16-1;
	}
	else
	{
		Input->Read_u16 = Input->Write_u16-1;
	}

	if( Output->Write_u16 == 0)
	{
		Output->Read_u16 = Output->Size_u16-1;
	}
	else
	{
		Output->Read_u16 = Output->Write_u16-1;
	}

	for(uint16_t i=0;i<(IIR->SizeNum);i++)
	{
		double Var = CircBuff_Backward_Read(Input);
		output = output + Var*IIR->CoeffNum[i];
	}

	for(uint16_t i=1;i<(IIR->SizeDenum);i++)
	{
		double Var = CircBuff_Backward_Read(Output);
		output = output - Var*IIR->CoeffDenum[i];
	}
	return output;
}


uint8_t FIR_Init(FIR_Filter* FIR,uint16_t Size,double* Coef)
{
	uint8_t RetVal_u8 = 0;
	if( Size<MAX_ORDER)
	{

		FIR->Coeff =(double*) malloc(sizeof(double)*Size);
		FIR->Order = Size -1;
		for(uint16_t i=0;i<Size;i++)
		{
			FIR->Coeff[i] = Coef[i];
		}
		RetVal_u8 =1;
	}
	return RetVal_u8;
}

double FIR_Calculate(FIR_Filter* FIR,Circular_Buffer* Input)
{
	double output =0;
	if( Input->Write_u16 == 0)
	{
		Input->Read_u16 = Input->Size_u16-1;
	}
	else
	{
		Input->Read_u16 = Input->Write_u16-1;
	}
	for(uint16_t i=0;i<=(FIR->Order);i++)
	{
		double Var = CircBuff_Backward_Read(Input);
		output = output + Var*FIR->Coeff[i];
	}
	return output;
}

void FIR_CalculateV2(FIR_Filter* FIR,Circular_Buffer* Input,double* Val)
{
	double output =0;
	if( Input->Write_u16 == 0)
	{
		Input->Read_u16 = Input->Size_u16-1;
	}
	else
	{
		Input->Read_u16 = Input->Write_u16-1;
	}
	for(uint16_t i=0;i<=(FIR->Order);i++)
	{
		double Var = CircBuff_Backward_Read(Input);
		output = output + Var*FIR->Coeff[i];
	}
	*Val = output;
}

void FIR_MvgAvgInit(FIR_Filter* FIR,uint16_t Size)
{
	double * Coefs = (double*) malloc(sizeof(double)*Size);
	for(uint16_t i = 0 ; i<Size;i++)
	{
		Coefs[i] = (1/(double)Size);
	}
	FIR_Init(FIR, Size, Coefs);
}

void DSP_Extremum(double Input,double * Max , double * Min , double * Freq)
{
	static double Input_Pred = 0 ;
	static double Deriv_Pred = 0 ;
	static double Peak = 0 ;
	static uint8_t Cnt = 0;


	double Deriv = Input - Input_Pred ;
	double Mul = Deriv * Deriv_Pred ;

	Input_Pred = Input ;
	Deriv_Pred = Deriv ;
	Tsig = Tsig +( 1/ 1000.0);
	if( Mul<0)
	{
		Peak = Input ;
		if(Cnt == 0)
		{
			Cnt = 1 ;
			* Max  = Peak;
		}
		else
		{
			* Freq = 1/Tsig ;
			Tsig = 0 ;
			Cnt = 0 ;
			* Min = Peak;
		}
	}
}


void DSP_ExtremumV2(double Input,double * Max , double * Min , double * Freq)
{
	static double Input_Pred = 0 ;
	static double Deriv_Pred = 0 ;
	static double Peak = 0 ;
	static uint8_t Cnt = 0;


	double Deriv = Input - Input_Pred ;
	double Mul = Deriv * Deriv_Pred ;

	Input_Pred = Input ;
	Deriv_Pred = Deriv ;
	Tsig = Tsig +( 1/ 1000.0);
	if( Mul<0)
	{
		Peak = Input ;
		if(Tsig > 900)
		{
			if(Cnt == 0)
			{
				Cnt = 1 ;
				* Max  = Peak;
			}
			else
			{
				* Freq = 1/Tsig ;
				Tsig = 0 ;
				Cnt = 0 ;
				* Min = Peak;
			}
		}
	}
}


void DSP_ExtremumV3(double Input,double * Max , double * Min , double * Freq)
{
	static double Input_Pred = 0 ;
	static double Deriv_Pred = 0 ;
	static double Peak = 0 ;
	static uint16_t Count = 0 ;

	double Deriv = Input - Input_Pred ;
	double Mul = Deriv * Deriv_Pred ;

	Input_Pred = Input ;
	Deriv_Pred = Deriv ;
	Tsig = Tsig +1;
	if(Tsig>=30000)
	{
		*Freq = Count * 2;
		Count = 0 ;
		Tsig = 0 ;
	}
	if( Mul<0)
	{
		Peak = Input ;
		if(Deriv_Pred<0)
		{
			* Min = Peak;
		}
		else if(Deriv_Pred>0)
		{
			* Max  = Peak;
			Count++;
		}
		else
		{
			if(Deriv<0)
			{
				* Max  = Peak;
				Count++;
			}
			else if(Deriv>0)
			{
				* Min = Peak;
			}
		}
	}
}

void DSP_ExtremumV4(double Input,double * Max , double * Min , double * Freq)
{
	static double Input_Pred = 0 ;
	static double Deriv_Pred = 0 ;
	static double Peak = 0 ;
	static uint16_t Count = 0 ;


	double Deriv = Input - Input_Pred ;
	double Mul = Deriv * Deriv_Pred ;

	Input_Pred = Input ;
	Deriv_Pred = Deriv ;
	Tsig2 = Tsig2 + 1;
	if(Tsig2>=30000)
	{
		*Freq = Count;
		Count = 0 ;
		Tsig2 = 0;
	}
	if( Mul<0)
	{
		Count++;
		Peak = Input ;
		if(Deriv_Pred<0)
		{
			* Min = Peak;
		}
		else if(Deriv_Pred>0)
		{
			* Max  = Peak;

		}
		else
		{
			if(Deriv<0)
			{
				* Max  = Peak;
			}
			else if(Deriv>0)
			{
				* Min = Peak;
			}
		}
	}
}
