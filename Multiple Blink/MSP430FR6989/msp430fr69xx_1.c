
//******************************************************************************
//  MSP430FR69x 
//	 Multiple Blink
//
//   Description: Blink 2 LEDs at 2 different rate
//   ACLK = 32.768kHz, MCLK = SMCLK = default DCO~1MHz
//
//                MSP430F552x
//             -----------------
//         /|\|                 |
//          | |                 |
//          --|RST              |
//            |                 |
//            |             P1.0|-->LED
//
//   Thai Nghiem (with help of Ardit Pranvoku)
//   Rowan University
//   Spetember 2017
//   Built with CCSv4 and IAR Embedded Workbench Version: 4.21
//******************************************************************************
#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1DIR |= BIT0;                          // Clear P1.0 output latch for a defined power-on state
    P1OUT |= BIT0;                          // Set P1.0 to output direction

    P9OUT &= ~BIT7;                         // Clear P9.7 output latch for a defined power-on state
    P9DIR |= BIT7;                          // Set P9.7 to output direction

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
	{
		volatile unsigned int j;

		P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
		__delay_cycles(10000);             // Delay for 10000*(1/MCLK)=0.01s
		j++;								//increment j
		if (j % 6 == 0) {					//if j is divisible by 6, toggle 9.7
			P9OUT ^= BIT7;                      // Toggle P9.7 using exclusive-OR
		}
	}
}
