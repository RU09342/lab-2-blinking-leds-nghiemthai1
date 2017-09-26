
//******************************************************************************
//   MSP430F552x 
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
  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT
  P1DIR |= BIT0;                            // P1.0 set as output

  P2DIR &= ~BIT1;                         // Set P2.1 to input direction
  P2REN |= BIT1;                          // Enable resistor for P2.1


  while(1){
      if(!(P2IN & BIT1))						// If you press P2.1 button
      {
          P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
      }
      else{
          P1OUT &= ~BIT0;                     // Clear P1.0 using exclusive-OR
      }

  }
}
