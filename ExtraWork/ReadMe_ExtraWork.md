# Read Me for ExtraWork
## Author: Ardit Pranvoku, Thai Nghiem.
# How does the code work
Implements opposite but parallel pulse width modules on two LEDS using load, duty, and cycle.
Any board specific pins and pits will be substituted with the variable X.
The watchdog timer must be stopped with the line WDTCTL = WDTPW + WDTHOLD or WDTCTL = WDTPW | WDTHOLD.
Else, the processor will reset.
The desired led pins and bits must be set to 1 to configure it to be an output.
The desired button pin and bit must be to 0 to configure it to be an input.
Also,  PXREN |= BITX; must be used to enable the pullup resistor for that button.     
By using the line PM5CTL0 = ~LOCKLPM5, the default high impedance on the board is disabled.
This high impedance serves to get rid of any cross currents, but is turned off later.

While(1) keeps the program in the loop forever.
Duty is a constant at 500. Load is incremented from 0 to 500. Cycle is also incremented from 0 to 500.
While cycle is less than load, the LED is turned on. While cycle is greater than load, the LED is off.
As load gradually increases, this changing ratio is what causes the fluctuating PWM.
If the button is pressed down, the two LEDs switch. The led that was previously getting brighter gets dimmers
and vice versa.

##Board specific changes!
In the MPS430g2553 and the MSP430f5529 i must be declared as a volatile unsigned int.
Both of these boards do not use __delay_cycles. Instead, they use i to count down from 50,000 in a for loop,
Which accomplishes the same.
The MSP430g2553 uses for(;;) to initalize an infinite loop instead of while(1)
## How to implement the code
To run this code, simply import the project folder into code composer, then build. After plugging your MSP430, hit dubug. 
One of the LED will dim, while the other one brighten. If you press the button, the reverse will happen.