﻿----------------------------------------------------------------

INSTALLATION:

 - Debian/Ubuntu: 
   apt install arduino python-serial

HOW TO:

1. Upload the sketch to the arduino
2. Connect the chip to the arduino
3. Run ./pic_programmer.py -i HEX_FILE

* For help run ./pic_programmer.py -h

Thats it!

----------------------------------------------------------------

RELEASE:

version 0.3
 - Support loading EEPROM, Id and comment sections from HEX file.
 - Programming is faster
   Arduino UNO serial USB operate at 2000000 baud instead of 9600 baud
 - Verification that Program, ID & EEPROM memory have been programmed correctly

version 0.2 - has a new PC-side software written in Python. It's simpler than the old one and a bit faster, it uses the pySerial library and allows to program the following microcontrollers:
	18F2420
	18F2455
	18F2520
	18F2550
	18F4420
	18F4455
	18F4520
	18F4550

Only the 18F2550 and 18F4550 have been tested.
