# Button Blink
## How does this work
Turns on an LED as long as a button is being pressed.
Any board specific pins and pits will be substituted with the variable X.
The watchdog timer must be stopped with the line WDTCTL = WDTPW + WDTHOLD or WDTCTL = WDTPW | WDTHOLD.
Else, the processor will reset.

The desired led pin and bit must be set to 1 to configure it to be an output.
The desired button pin and bit must be to 0 to configure it to be an input.
Also,  PXREN |= BITX; must be used to enable the pullup resistor for that button.     
By using the line PM5CTL0 = ~LOCKLPM5, the default high impedance on the board is disabled.
This high impedance serves to get rid of any cross currents, but is turned off later.

While(1) keeps the program in the loop forever.
if(!(PXIN & BITX)) is the if condition which will check if a button is depressed. 
If a button is depressed, the bit changes from 1 to 0, so a not condition is needed.
PXOUT |= BITX; sets that bit to 1 every time it detects a button press. 
Else, it will be cleared, turning the LED off.

##Board specific changes!
In the MPS430g2553 and the MSP430f5529 i must be declared as a volatile unsigned int.
Both of these boards do not use __delay_cycles. Instead, they use i to count down from 50,000 in a for loop,
Which accomplishes the same.
The MSP430g2553 uses for(;;) to initalize an infinite loop instead of while(1)
# How to implement the code
To run this code, simply import it into code composer, then clikc build. After you plug in your MSP430, hit debug. When you press the button, LED1 one the board should blink