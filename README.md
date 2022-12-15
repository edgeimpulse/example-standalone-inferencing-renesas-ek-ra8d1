# example-standalone-inferencing-renesas-ek-ra8d1
Static inference on Renesas EK-RA8D1

## Note
FSP version 4.1.0beta
CMSIS version 5.9
ARM GCC version 10.3.1
Compiled using -march=armv8.1-m.main+mve.fp+fp.dp which is ok for Cortex-M85 
Using -mcpu=cortex-m85 is not working.

edge-impulse-sdk/CMSIS has been updated to v5.9.

UART is using pin TX and RX on the Arduino connector.
Clock running@480MHz
