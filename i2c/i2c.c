#include "pic14/pic16f877a.h"
#include "stdio.h"
#include <pic14regs.h>
#include <stdint.h>


#define SDA RC4
#define SCK RC3
#define SDA_DIR TRISC4
#define SCK_DIR TRISC3

#define I2C_SPEED 100
#define _XTAL_FREQ 1000000

void InitI2C(void){

	//SSPCON  = 0b00101000;    //pg84/234
        //SSPCON2 = 0b00000000;    //pg85/234
	SDA_DIR = 1; //Make SDA and
	SCK_DIR = 1;  //SCK pins input
	SSPCON = 0x28;
	SSPADD = ((_XTAL_FREQ/4000)/I2C_SPEED) - 1;
	SSPSTAT |= 0x80; //slew rate conrol is disabled;
	//select and enable I2C in master mode

}

void I2C_Start(void){
	SEN = 1; //send start bit
	while(!SSPIF); //wait for it to complete
	SSPIF=0; //clear flag bit
}

void I2C_Restart(void){

	RSEN=1;
	while(!SSPIF);
	SSPIF=0;
}

void I2C_Stop(void){
	PEN = 1; //send stop bits
	while(!SSPIF); //wait for it to complete
	SSPIF=0; //clear flag bit
}

int I2C_Write_Byte(unsigned char Byte){
	SSPBUF = Byte; //Send Byte value
	while(!SSPIF); //wait for it to complete
	SSPIF = 0;  //clear the flag bit
	return ACKSTAT;  //return ACK/NACK from slave
}

unsigned char I2C_Read_Byte(void){
	RCEN=1;
	while(!SSPIF);
	SSPIF=0;
	return (unsigned char)SSPBUF;
}

void I2C_Send_ACK(void){
	ACKDT = 0; //ACK data bit 0 = ACK
	ACKEN = 1; //ACK data enabled
	while(!SSPIF);
	SSPIF=0;
}

void main(void){
	unsigned char RxByte =0;
	InitI2C();
	I2C_Start();
	I2C_Write_Byte(0xA0);
	RxByte = I2C_Read_Byte();
	I2C_Send_ACK();
	I2C_Stop();

	while(1)
	{

	}

}
