
//******************************************************************************
//  MSP430G2xx3 
//		Button Blink
//
//   Description: When you press a button, LED1 will light up. When you release it
//					will be off again. 
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
//   Thai Nghiem
//   Rowan University
//   September 2017
//   Built with CCSv4 and IAR Embedded Workbench Version: 4.21
//******************************************************************************

#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  P1DIR |= 0x01;                            // Set P1.0 to output direction

  P1DIR &= ~BIT3;                         // Set P1.3 to input direction
  P1REN |= BIT3;                          // Enable resistor for P1.3

  for (;;)
  {
      if(!(P1IN & BIT3))					  // If you press the P1.3 button
      {
          P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
      }
      else{
          P1OUT &= ~BIT0;                     // Clear P1.0 using exclusive-OR
  }
}
}
