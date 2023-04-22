/*
 * MAX30102_Macros.h
 *
 *  Created on: 27 nov. 2022
 *      Author: khalil
 */

#ifndef INC_MAX30102_MACROS_H_
#define INC_MAX30102_MACROS_H_


// Macros

#define MAX30102_I2C_Write			0xAE
#define MAX30102_I2C_Read			0xAF

// Status Registers
#define MAX30102_INTSTAT1 			0x00
#define MAX30102_INTSTAT2 			0x01
#define MAX30102_INTENABLE1 		0x02
#define MAX30102_INTENABLE2 		0x03

// FIFO Registers
#define MAX30102_FIFOWRITEPTR 	 	0x04
#define MAX30102_FIFOOVERFLOW 	 	0x05
#define MAX30102_FIFOREADPTR  		0x06
#define MAX30102_FIFODATA 			0x07

// Configuration Registers
#define MAX30102_FIFOCONFIG  		0x08
#define MAX30102_MODECONFIG  		0x09
#define MAX30102_SPO2		  		0x0A

#define MAX30102_LED1_PULSEAMP  	0x0C
#define MAX30102_LED2_PULSEAMP  	0x0D


#define MAX30102_MULTILEDCONFIG1  	0x11
#define MAX30102_MULTILEDCONFIG2 	0x12

// Die Temperature Registers
#define MAX30102_DIETEMPINT  		0x1F
#define MAX30102_DIETEMPFRAC  		0x20
#define MAX30102_DIETEMPCONFIG  	0x21

// Part ID Registers
#define MAX30102_REVISIONID  		0xFE
#define MAX30102_PARTID  			0xFF


// Reset Macros
#define MAX30102_RESET_MASK 		0xBF
#define MAX30102_RESET  			0x40

// Sample Average Macros
#define MAX30102_SAMPLEAVG_MASK 	0b11100000
#define MAX30102_SAMPLEAVG_1  		0x00
#define MAX30102_SAMPLEAVG_2  		0x20
#define MAX30102_SAMPLEAVG_4  		0x40
#define MAX30102_SAMPLEAVG_8  		0x60
#define MAX30102_SAMPLEAVG_16  		0x80
#define MAX30102_SAMPLEAVG_32  		0xA0

// FIFO Rollover
#define MAX30102_ROLLOVER_MASK  	0xEF
#define MAX30102_ROLLOVER_ENABLE  	0x10
#define MAX30102_ROLLOVER_DISABLE  	0x00

// Mode Config Macros
#define MAX30102_MODE_MASK			0xF8
#define MAX30102_MODE_REDONLY		0x02
#define MAX30102_MODE_REDIRONLY		0x03
#define MAX30102_MODE_MULTILED		0x07

// Spo2 Config
#define MAX30102_ADCRANGE_MASK  	0x9F
#define MAX30102_ADCRANGE_2048  	0x00
#define MAX30102_ADCRANGE_4096  	0x20
#define MAX30102_ADCRANGE_8192  	0x40
#define MAX30102_ADCRANGE_16384  	0x60

#define MAX30102_SAMPLERATE_MASK  	0xE3
#define MAX30102_SAMPLERATE_50  	0x00
#define MAX30102_SAMPLERATE_100  	0x04
#define MAX30102_SAMPLERATE_200  	0x08
#define MAX30102_SAMPLERATE_400  	0x0C
#define MAX30102_SAMPLERATE_800  	0x10
#define MAX30102_SAMPLERATE_1000  	0x14
#define MAX30102_SAMPLERATE_1600  	0x18
#define MAX30102_SAMPLERATE_3200  	0x1C

#define MAX30102_PULSEWIDTH_MASK  	0xFC
#define MAX30102_PULSEWIDTH_69  	0x00
#define MAX30102_PULSEWIDTH_118  	0x01
#define MAX30102_PULSEWIDTH_215  	0x02
#define MAX30102_PULSEWIDTH_411  	0x03

//Multi-LED Mode configuration
#define MAX30102_SLOT1_MASK  		0xF8
#define MAX30102_SLOT2_MASK  		0x8F
#define MAX30102_SLOT3_MASK  		0xF8
#define MAX30102_SLOT4_MASK  		0x8F

#define SLOT_NONE  					0x00
#define SLOT_RED_LED  				0x01
#define SLOT_IR_LED  				0x02

#endif /* INC_MAX30102_MACROS_H_ */
