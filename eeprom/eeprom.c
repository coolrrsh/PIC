#include "pic14/pic16f877a.h"
#include "stdio.h"
#include "lcd.h"
#include "i2c.h"
//#include <pic14regs.h>
//#include <stdint.h>


void delay1();
void main()
{
    lcd_init();
    i2c_init();
    show("@eeprom");
    cmd(0xc2);
    show("Writing...");
    i2c_send_byte(0x0000,"RajeshwarRS");
    delay1();
    cmd(0xc2);
    show("Reading...");
    delay1();
    cmd(0xc2);
    dat(i2c_read_byte(0x0000));
    dat(i2c_read_byte(0x0001));
    dat(i2c_read_byte(0x0002));
    dat(i2c_read_byte(0x0003));
    dat(i2c_read_byte(0x0004));
    dat(i2c_read_byte(0x0005));
    dat(i2c_read_byte(0x0006));
    dat(i2c_read_byte(0x0007));
    dat(i2c_read_byte(0x0008));
    dat(i2c_read_byte(0x0009));
    dat(i2c_read_byte(0x000a));
    
    while(1);
}   
void delay1()
{
    unsigned int j,k;
    for(j=0;j<60000;j++) {
        for(k=0;k<2;k++);
    }
}
