# Multiple Blink

## How does this work
Blinks 2 LEDs on the board at a half duty cycles.
Any board specific pins and pits will be substituted with the variable X.
The watchdog timer must be stopped with the line 
```c
WDTCTL = WDTPW + WDTHOLD; or WDTCTL = WDTPW | WDTHOLD;
```
Else, the processor will reset.
The desired led pin and bit must be set to 1 to configure it to be an output.
The desired button pin and bit must be to 0 to configure it to be an input.
Also,  
```c
PXREN |= BITX;
``` 
must be used to enable the pullup resistor for that button.     
By using the line PM5CTL0 = ~LOCKLPM5, the default high impedance on the board is disabled.
This high impedance serves to get rid of any cross currents, but is turned off later.

While(1) keeps the program in the loop forever.
An int is incremented and modulo'd by a number to blink the 2nd LED at a fraction of the rate of the first LED.
Example, using the if statement (if j % 6 = 0), the rate of the LED will be a sixth of the other.
```c
PXOUT ^= BITX; 
```
flips that bit every time it runs. 
__delay_cycles(100000) delays the next toggle by .1 seconds.

## Board specific changes!
In the MPS430g2553 and the MSP430f5529 i must be declared as a volatile unsigned int.
Both of these boards do not use __delay_cycles. Instead, they use i to count down from 50,000 in a for loop,
Which accomplishes the same.
The MSP430g2553 uses for(;;) to initalize an infinite loop instead of while(1)
## How to implement the code
To run this code, simply import the project folder into code composer, build. Plug in your MSP430, hit debug and watch the LED blink