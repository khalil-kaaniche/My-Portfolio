/*
 * maestro.h
 *
 *  Created on: Jan 15, 2022
 *      Author: khalil
 */

#ifndef INC_MAESTRO_H_
#define INC_MAESTRO_H_

#include <main.h>
#include "stdint.h"

#define YES 1
#define NO	0
#define NbrOfServo 1
#define EnableCRC NO

extern UART_HandleTypeDef huart3;
extern DMA_HandleTypeDef hdma_usart3_rx;
extern DMA_HandleTypeDef hdma_usart3_tx;


void Set_Target(uint8_t Channel_Nbr_u8 ,uint16_t Target_u16);
void Set_Speed(uint8_t Channel_Nbr_u8 ,uint16_t Target_u16);
void Set_Acceleration(uint8_t Channel_Nbr_u8 ,uint16_t Target_u16);
uint16_t Get_Position(uint8_t Channel_Nbr_u8);
uint8_t Get_Moving_State();
uint16_t Get_Errors();
void Go_Home();
void Set_Multiple_Target(uint8_t NbrOfTargets,uint8_t FirstChannelNumber , uint16_t* Targets );


// Functions To Use
void Servo_vInit();
uint8_t Servo_vCommande(uint8_t Channel_Nbr_u8 ,uint16_t Target_u16);
uint8_t Servo_vMultiple(uint8_t NbrOfTargets,uint8_t FirstChannelNumber , uint16_t* Targets );
uint8_t Servo_u16CheckArrived(uint8_t NbrOfTargets,uint8_t FirstChannelNumber , uint16_t* Targets);

void CodeBrute();

#endif /* INC_MAESTRO_H_ */
