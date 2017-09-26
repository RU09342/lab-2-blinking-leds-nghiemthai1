# Simple Blink
## How does this work
Blinks an LED on the board at a half duty cycle, no user input is needed.
Any board specific pins and bits will be substituted with the variable X.

The watchdog timer must be stopped with the line 
```c
WDTCTL = WDTPW + WDTHOLD or WDTCTL = WDTPW | WDTHOLD.
```
Else, the processor will reset.
The desired led pin and bit must be set to 1 to configure it to be an output.
By using the line 
```c
PM5CTL0 = ~LOCKLPM5
``` 
the default high impedance on the board is disabled.
This high impedance serves to get rid of any cross currents, but is turned off later.
 

While(1) keeps the program in the loop forever.
```c
PXOUT ^= BITX;
```
 flips that bit every time it runs.
__delay_cycles(100000) delays the next toggle by .1 seconds.

## Board specific changes!
In the MSP430g2553 and the MSP430f5529, i must be declared as a volatile unsigned int.
Also in the MSP430g2553 and the MSP430f5529 the default high impedance mode does not need to be disabled,
As the lack one.
Both of these boards do not use __delay_cycles. Instead, they use i to count down from 50,000 in a for loop,
Which accomplishes the same.
The MSP430g2553 uses for(;;) to initalize an infinite loop instead of while(1)

## How to implement this on your computer
To run this code, simply import it into code composer, then click build. After plugging in the MSP430, hit debug button then watch the LED1 blink