#include "pic14/pic16f877a.h"
#include "stdio.h"

void main(){

	TRISB0 = 0;
	TRISC3 = 0;
	TRISC4 = 1;
	TRISC5 = 0;

	SMP = 1;
	CKE = 0;
	SSPM0=0;
	SSPM1=0;
	SSPM2=0;
	SSPM3=0; //master mode Fosc/4

	SSPEN=1;
	CKP=0;

	int i=0;
	unsigned char a;

	while(1){
		
		for(i=0;i<500;i++);
		RB0=0;
		for(i=0;i<500;i++);
		if(BF==1)
		{
			a=SSPBUF;
			RB0=1; /*chip select high*/
		}
		for(i=0;i<500;i++);
		RB0 = 0;
		SSPBUF = 0x75;
		for(i=0;i<500;i++);
		RB0 = 1;

	}

	return;
}

