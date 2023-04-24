/*
 * maestro.c
 *
 *  Created on: Jan 15, 2022
 *      Author: khalil
 */


#include <maestro.h>

#if EnableCRC == YES
uint8_t Buffer_Reversed[5]={0,0,0,0,0};
#endif

extern uint8_t WaitForRx;
extern uint8_t WaitForTx;
uint16_t Return_u16=0;
uint8_t Sending_Buffer_u8[15]={0};
uint8_t Payload[NbrOfServo*2+1]={0x83,0x01,0x00};
uint8_t Payload_Reversed[NbrOfServo*2+1]={0x00,0x00,0x00};
uint8_t Poly = 0x91;
uint8_t Poly_Reversed=0x00;
uint64_t Data = 0 ;
uint8_t CRC_u8 =0;
uint8_t CRC_Reversed_u8=0;
uint8_t Answer[10]={0};
uint8_t State=0;
uint8_t Buff[4]={0};
uint16_t Position[16]={};

uint8_t I=0;
extern UART_HandleTypeDef huart3;
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;

uint8_t Servo_u16CheckArrived(uint8_t NbrOfTargets,uint8_t FirstChannelNumber , uint16_t* Targets)
{
	for(I=FirstChannelNumber;I<FirstChannelNumber+NbrOfTargets;I++)
	{
		if (Get_Position(I)!=Targets[I-FirstChannelNumber])
		{
			return 0;
		}
	}
	return 1;
}


void Servo_vInit()
{
	HAL_UARTEx_ReceiveToIdle_IT(&huart3, Buff, 50);
	__HAL_IT_DISABLE_IT ( &hdma_usart3_rx, DMA_IT_HT );
}
uint8_t Servo_vMultiple(uint8_t NbrOfTargets,uint8_t FirstChannelNumber , uint16_t* Targets )
{
	if(Servo_u16CheckArrived(NbrOfTargets, FirstChannelNumber, Targets)==1)
	{
		return 1;
	}
	else
	{
		Set_Multiple_Target(NbrOfTargets, FirstChannelNumber, Targets);
		return 0;
	}
}
uint8_t Servo_vCommande(uint8_t Channel_Nbr_u8 ,uint16_t Target_u16)
{
	if(Servo_u16CheckArrived(1, Channel_Nbr_u8, &Target_u16)==1)
		{
			return 1;
		}
		else
		{
			Set_Target(Channel_Nbr_u8, Target_u16);
			return 0;
		}
}

void Set_Target(uint8_t Channel_Nbr_u8 ,uint16_t Target_u16)
{

	Sending_Buffer_u8[0]=0x84;
	Sending_Buffer_u8[1]=Channel_Nbr_u8;
	Sending_Buffer_u8[2]=(Target_u16*4)&0x7F;
	Sending_Buffer_u8[3]=((Target_u16*4)>>7)&0x7F;
	
#if EnableCRC == YES
	// Reverse charge
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<8;j++)
		{
			Buffer_Reversed[i]=(((Sending_Buffer_u8[i]>>j)&0b1)<<(7-j))|Buffer_Reversed[i];
		}
	}
	// Reverse polynom
	for (int j=0;j<8;j++)
	{
		Poly_Reversed = (((Poly>>j)&0b1)<<(7-j))|Poly_Reversed;
	}
	// Calculate CRC

	for (int i=0 ; i<4;i++)
	{
		Data = (Data<<8) | Buffer_Reversed[i];
	}
	Data = Data << 7 ;

	// 23
	//
	CRC_u8=(Data>>31);
	CRC_u8=CRC_u8^Poly_Reversed;
	for (int i=0 ; i<31;i++)
	{
		CRC_u8=CRC_u8<<1;
		CRC_u8=CRC_u8|((Data>>(30-i))&0b1);
		if((CRC_u8&0b10000000)==0x80)
		{
			CRC_u8=CRC_u8^Poly_Reversed;
		}
		else
		{
			CRC_u8=CRC_u8^0b00000000;
		}
	}
	// Reverse Calculated CRC
	for (int j=0;j<8;j++)
	{
		CRC_Reversed_u8 = (((CRC_u8>>j)&0b1)<<(7-j))|CRC_Reversed_u8;
	}
	Sending_Buffer_u8[4]=CRC_Reversed_u8;
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 5);
#elif(EnableCRC == NO)
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 4);
	while(WaitForTx==0){}
	WaitForTx=0;
#endif

}

void Set_Speed(uint8_t Channel_Nbr_u8 ,uint16_t Target_u16)
{
	// Set Speed 0x87 , Channel number , Speed 7 low bits, Speed 7 high bits
	/*
	 *
 This command limits the speed at which a servo channel’s output value changes.
 The speed limit is given in units of (0.25 μs)/(10 ms), except in special cases (see Section 4.b).
 The command 0x87, 0x05, 0x0C, 0x01 sets the speed of servo channel 5 to a value of 140, which
corresponds to a speed of 3.5 μs/ms.
 What this means is that if you send a Set Target command to adjust the target from, say, 1000 μs to 1350 μs,
 it will take 100 ms to make that adjustment. A speed of 0 makes the speed unlimited.
	 *
	 * */

	//	uint8_t Sending_Buffer_u8[5]={0x87,0,0,0,0};
	//	uint8_t Buffer_Reversed[5]={0,0,0,0,0};
	Sending_Buffer_u8[0]=0x87;
	Sending_Buffer_u8[1]=Channel_Nbr_u8;
	Sending_Buffer_u8[2]=(Target_u16*4)&0x7F;
	Sending_Buffer_u8[3]=((Target_u16*4)>>7)&0x7F;


#if EnableCRC == YES
	// Reverse charge
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<8;j++)
		{
			Buffer_Reversed[i]=(((Sending_Buffer_u8[i]>>j)&0b1)<<(7-j))|Buffer_Reversed[i];
		}
	}
	// Reverse polynom
	for (int j=0;j<8;j++)
	{
		Poly_Reversed = (((Poly>>j)&0b1)<<(7-j))|Poly_Reversed;
	}
	// Calculate CRC

	for (int i=0 ; i<4;i++)
	{
		Data = (Data<<8) | Buffer_Reversed[i];
	}
	Data = Data << 7 ;

	// 23
	//
	CRC_u8=(Data>>31);
	CRC_u8=CRC_u8^Poly_Reversed;
	for (int i=0 ; i<31;i++)
	{
		CRC_u8=CRC_u8<<1;
		CRC_u8=CRC_u8|((Data>>(30-i))&0b1);
		if((CRC_u8&0b10000000)==0x80)
		{
			CRC_u8=CRC_u8^Poly_Reversed;
		}
		else
		{
			CRC_u8=CRC_u8^0b00000000;
		}
	}

	// Reverse Calculated CRC
	for (int j=0;j<8;j++)
	{
		CRC_Reversed_u8 = (((CRC_u8>>j)&0b1)<<(7-j))|CRC_Reversed_u8;
	}
	Sending_Buffer_u8[4]=CRC_Reversed_u8;
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 5);
#elif(EnableCRC == NO)
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 4);
	while(WaitForTx==0){}
	WaitForTx=0;
#endif

}
void Set_Acceleration(uint8_t Channel_Nbr_u8 ,uint16_t Target_u16)
{
	// Set Accel 0x89 , Channel number , Accel 7 low bits, Accel 7 high bits
	/*

This command limits the acceleration of a servo channel’s output.
The acceleration limit is a value from 0 to 255 in units
A value of 0 corresponds to no acceleration limit.
An acceleration limit causes the speed of a servo to slowly
ramp up until it reaches the maximum speed, then to ramp down again as position approaches target,
resulting in a relatively smooth motion from one point to another.
	 */


	//	uint8_t Sending_Buffer_u8[5]={0x89,0,0,0,0};
	//	uint8_t Buffer_Reversed[5]={0,0,0,0,0};
	Sending_Buffer_u8[0]=0x89;
	Sending_Buffer_u8[1]=Channel_Nbr_u8;
	Sending_Buffer_u8[2]=(Target_u16*4)&0x7F;
	Sending_Buffer_u8[3]=((Target_u16*4)>>7)&0x7F;


#if EnableCRC == YES
	// Reverse charge
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<8;j++)
		{
			Buffer_Reversed[i]=(((Sending_Buffer_u8[i]>>j)&0b1)<<(7-j))|Buffer_Reversed[i];
		}
	}
	// Reverse polynom
	for (int j=0;j<8;j++)
	{
		Poly_Reversed = (((Poly>>j)&0b1)<<(7-j))|Poly_Reversed;
	}
	// Calculate CRC

	for (int i=0 ; i<4;i++)
	{
		Data = (Data<<8) | Buffer_Reversed[i];
	}
	Data = Data << 7 ;

	// 23
	//
	CRC_u8=(Data>>31);
	CRC_u8=CRC_u8^Poly_Reversed;
	for (int i=0 ; i<31;i++)
	{
		CRC_u8=CRC_u8<<1;
		CRC_u8=CRC_u8|((Data>>(30-i))&0b1);
		if((CRC_u8&0b10000000)==0x80)
		{
			CRC_u8=CRC_u8^Poly_Reversed;
		}
		else
		{
			CRC_u8=CRC_u8^0b00000000;
		}
	}
	for (int j=0;j<8;j++)
	{
		CRC_Reversed_u8 = (((CRC_u8>>j)&0b1)<<(7-j))|CRC_Reversed_u8;
	}
	Sending_Buffer_u8[4]=CRC_Reversed_u8;
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 5);
#elif(EnableCRC == NO)
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 4);
	while(WaitForTx==0){}
	WaitForTx=0;
#endif

}
uint16_t Get_Position(uint8_t Channel_Nbr_u8){
	/*
: 0x90, channel number

If the specified channel is configured as a servo, this position value represents the current pulse width
that the Maestro is transmitting on the channel, reflecting the effects of any previous commands,
speed and acceleration limits, or scripts running on the Maestro.
	 */

	//	uint16_t Return_u16=0;
	//	uint8_t Sending_Buffer_u8[3]={0x90,0,0};
	//	uint8_t Buffer_Reversed[3]={0,0,0};
	Sending_Buffer_u8[0]=0x90;
	Sending_Buffer_u8[1]=Channel_Nbr_u8;


#if EnableCRC == YES
	// Reverse charge
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<8;j++)
		{
			Buffer_Reversed[i]=(((Sending_Buffer_u8[i]>>j)&0b1)<<(7-j))|Buffer_Reversed[i];
		}
	}
	// Reverse polynom
	for (int j=0;j<8;j++)
	{
		Poly_Reversed = (((Poly>>j)&0b1)<<(7-j))|Poly_Reversed;
	}
	// Calculate CRC

	for (int i=0 ; i<2;i++)
	{
		Data = (Data<<8) | Buffer_Reversed[i];
	}

	Data = Data << 7 ;

	CRC_u8=(Data>>15);
	CRC_u8=CRC_u8^Poly_Reversed;
	for (int i=0 ; i<15;i++)
	{
		CRC_u8=CRC_u8<<1;
		CRC_u8=CRC_u8|((Data>>(14-i))&0b1);
		if((CRC_u8&0b10000000)==0x80)
		{
			CRC_u8=CRC_u8^Poly_Reversed;
		}
		else
		{
			CRC_u8=CRC_u8^0b00000000;
		}
	}
	for (int j=0;j<8;j++)
	{
		CRC_Reversed_u8 = (((CRC_u8>>j)&0b1)<<(7-j))|CRC_Reversed_u8;
	}

	Sending_Buffer_u8[2]=CRC_Reversed_u8;
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 3);
#elif(EnableCRC == NO)
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 2);
	while(WaitForTx!=1){}
	WaitForTx=0;
#endif
	HAL_UART_Receive_IT(&huart3, Answer, 2);
	while(WaitForRx!=1){}
	WaitForRx=0;
	Return_u16=(Answer[0])|(Answer[1]<<8);
	Return_u16=Return_u16/4;
	return Return_u16;
}

uint8_t Get_Moving_State(){


	//	Response: 0x00 if no servos are moving, 0x01 if servos are moving

	//	uint8_t Sending_Buffer_u8[2]={0x93,0};
	//	uint8_t Buffer_Reversed[2]={0,0};
	Sending_Buffer_u8[0]=0x93;


#if EnableCRC == YES
	// Reverse charge
	for (int i=0;i<1;i++)
	{
		for (int j=0;j<8;j++)
		{
			Buffer_Reversed[i]=(((Sending_Buffer_u8[i]>>j)&0b1)<<(7-j))|Buffer_Reversed[i];
		}
	}
	// Reverse polynom
	for (int j=0;j<8;j++)
	{
		Poly_Reversed = (((Poly>>j)&0b1)<<(7-j))|Poly_Reversed;
	}
	// Calculate CRC

	for (int i=0 ; i<1;i++)
	{
		Data = (Data<<8) | Buffer_Reversed[i];
	}
	Data = Data << 7 ;

	// 23
	//
	CRC_u8=(Data>>7);
	CRC_u8=CRC_u8^Poly_Reversed;
	for (int i=0 ; i<7;i++)
	{
		CRC_u8=CRC_u8<<1;
		CRC_u8=CRC_u8|((Data>>(6-i))&0b1);
		if((CRC_u8&0b10000000)==0x80)
		{
			CRC_u8=CRC_u8^Poly_Reversed;
		}
		else
		{
			CRC_u8=CRC_u8^0b00000000;
		}
	}
	for (int j=0;j<8;j++)
	{
		CRC_Reversed_u8 = (((CRC_u8>>j)&0b1)<<(7-j))|CRC_Reversed_u8;
	}

	Sending_Buffer_u8[2]=CRC_Reversed_u8;
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 2);
#elif(EnableCRC == NO)
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 1);
	while(WaitForTx!=1){}
	WaitForTx=0;
	#endif
	HAL_UART_Receive_IT(&huart3, Answer, 1);
	while(WaitForRx!=1){}
	WaitForRx=0;
	return Answer[0];
}
uint16_t Get_Errors(){


	//	uint8_t Sending_Buffer_u8[2]={0xA1,0};
	//	uint8_t Buffer_Reversed[2]={0,0};
	Sending_Buffer_u8[0]=0xA1;


#if EnableCRC == YES
	// Reverse charge
	for (int i=0;i<1;i++)
	{
		for (int j=0;j<8;j++)
		{
			Buffer_Reversed[i]=(((Sending_Buffer_u8[i]>>j)&0b1)<<(7-j))|Buffer_Reversed[i];
		}
	}
	// Reverse polynom
	for (int j=0;j<8;j++)
	{
		Poly_Reversed = (((Poly>>j)&0b1)<<(7-j))|Poly_Reversed;
	}
	// Calculate CRC

	for (int i=0 ; i<1;i++)
	{
		Data = (Data<<8) | Buffer_Reversed[i];
	}
	Data = Data << 7 ;

	// 23
	//
	CRC_u8=(Data>>7);
	CRC_u8=CRC_u8^Poly_Reversed;
	for (int i=0 ; i<7;i++)
	{
		CRC_u8=CRC_u8<<1;
		CRC_u8=CRC_u8|((Data>>(6-i))&0b1);
		if((CRC_u8&0b10000000)==0x80)
		{
			CRC_u8=CRC_u8^Poly_Reversed;
		}
		else
		{
			CRC_u8=CRC_u8^0b00000000;
		}
	}
	for (int j=0;j<8;j++)
	{
		CRC_Reversed_u8 = (((CRC_u8>>j)&0b1)<<(7-j))|CRC_Reversed_u8;
	}

	Sending_Buffer_u8[2]=CRC_Reversed_u8;
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 2);
#elif(EnableCRC == NO)
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 1);
#endif
	HAL_UART_Receive_IT(&huart3, Answer, 2);
	while(WaitForRx!=1){}
	WaitForRx=0;
	Return_u16=(Answer[0])|(Answer[1]<<8);
	return Return_u16;
}
void Go_Home(){


	//	uint8_t Sending_Buffer_u8[2]={0xA2,0};
	//	uint8_t Buffer_Reversed[2]={0,0};
	Sending_Buffer_u8[0]=0xA2;


#if EnableCRC == YES
	// Reverse charge
	for (int i=0;i<1;i++)
	{
		for (int j=0;j<8;j++)
		{
			Buffer_Reversed[i]=(((Sending_Buffer_u8[i]>>j)&0b1)<<(7-j))|Buffer_Reversed[i];
		}
	}
	// Reverse polynom
	for (int j=0;j<8;j++)
	{
		Poly_Reversed = (((Poly>>j)&0b1)<<(7-j))|Poly_Reversed;
	}
	// Calculate CRC

	for (int i=0 ; i<1;i++)
	{
		Data = (Data<<8) | Buffer_Reversed[i];
	}
	Data = Data << 7 ;

	// 23
	//
	CRC_u8=(Data>>7);
	CRC_u8=CRC_u8^Poly_Reversed;
	for (int i=0 ; i<7;i++)
	{
		CRC_u8=CRC_u8<<1;
		CRC_u8=CRC_u8|((Data>>(6-i))&0b1);
		if((CRC_u8&0b10000000)==0x80)
		{
			CRC_u8=CRC_u8^Poly_Reversed;
		}
		else
		{
			CRC_u8=CRC_u8^0b00000000;
		}
	}
	for (int j=0;j<8;j++)
	{
		CRC_Reversed_u8 = (((CRC_u8>>j)&0b1)<<(7-j))|CRC_Reversed_u8;
	}

	Sending_Buffer_u8[2]=CRC_Reversed_u8;
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 2);
#elif(EnableCRC == NO)
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 1);
	while(WaitForTx!=1){}
	WaitForTx=0;
#endif

}
void Set_Multiple_Target(uint8_t NbrOfTargets,uint8_t FirstChannelNumber , uint16_t* Targets )
{
	Sending_Buffer_u8[0]=0x9F;
	Sending_Buffer_u8[1]=NbrOfTargets;
	Sending_Buffer_u8[2]=FirstChannelNumber;
	for(int i=0;i<NbrOfTargets;i++)
	{
		Sending_Buffer_u8[3+(2*i)]=((*(Targets+i))*4)&0x7F;
		Sending_Buffer_u8[3+(2*i)+1]=(((*(Targets+i))*4)>>7)&0x7F;
	}

#if EnableCRC == YES

#else
	while(HAL_UART_GetState(&huart3)==HAL_UART_STATE_BUSY){}
	HAL_UART_Transmit_IT(&huart3, Sending_Buffer_u8, 3+(2*NbrOfTargets));
	while(WaitForTx!=1){}
	WaitForTx=0;
#endif

}




void CodeBrute()
{
	// Reverse charge
	for (int i=0 ; i<(NbrOfServo*2);i++)
	{
		for (int j=0;j<8;j++)
		{
			Payload_Reversed[i]=(((Payload[i]>>j)&0b1)<<(7-j))|Payload_Reversed[i];
		}
	}

	// Reverse polynom
	for (int j=0;j<8;j++)
	{
		Poly_Reversed = (((Poly>>j)&0b1)<<(7-j))|Poly_Reversed;
	}

	// Calculate CRC

	for (int i=0 ; i<(NbrOfServo*2);i++)
	{
		Data = (Data<<8) | Payload_Reversed[i];
	}
	Data = Data << 7 ;

	CRC_u8=(Data>>15);
	CRC_u8=CRC_u8^Poly_Reversed;
	for (int i=0 ; i<15;i++)
	{
		CRC_u8=CRC_u8<<1;
		CRC_u8=CRC_u8|((Data>>(14-i))&0b1);
		if((CRC_u8&0b10000000)==0x80)
		{
			CRC_u8=CRC_u8^Poly_Reversed;
		}
		else
		{
			CRC_u8=CRC_u8^0b00000000;
		}
	}

	// Reverse Calculated CRC
	for (int j=0;j<8;j++)
	{
		CRC_Reversed_u8 = (((CRC_u8>>j)&0b1)<<(7-j))|CRC_Reversed_u8;
	}

	// use compact protocol

	// Set Target 0x84 , Channel number , target 7 low bits, target 7 high bits
	// if target is 1500 us (1500*4 = 6000);
	// target 0 tells the maestro  to stop sending pulse


	// Transmit tab

}


