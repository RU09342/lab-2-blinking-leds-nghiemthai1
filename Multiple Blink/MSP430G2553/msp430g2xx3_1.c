
//******************************************************************************
//  MSP430G2xx3 
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
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer


  P1DIR |= BIT0;                            // Set P1.0 to output direction
  P1DIR |= BIT6;                          // Set P1.6 to output direction


  for (;;)
  {

    volatile unsigned int i;
    volatile unsigned int j;
    P1OUT ^= BIT0;                          // Toggle P1.0 using exclusive-OR


    i = 10000;                              // Delay
    do (i--);
    while (i != 0);
    j++;						//increment j
        if(j % 6 == 0)					//if j is divisible by 6, run this code.
            {
                P1OUT ^= BIT6;                      // Toggle P1.6 using exclusive-OR
            }
    }
}
