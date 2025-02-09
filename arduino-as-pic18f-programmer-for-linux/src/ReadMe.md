##Verify the hardware connection Arduino Mega

```
import serial

try:
    arduino = serial.Serial('/dev/ttyACM0', 115200)  # Replace with your port, and baud rate (set via arduino application)
    print("Connected to Arduino!")
except serial.SerialException as e:
    print(f"Error: {e}")
```
