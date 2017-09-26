
//******************************************************************************
//   MSP430F552x
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
  volatile unsigned int i;

  WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT
  P1DIR |= BIT0;                            // P1.0 set as output

  P4OUT &= ~BIT7;                         // Clear P4.7 output latch for a defined power-on state
  P4DIR |= BIT7;                          // Set P4.7 to output direction

  while (1)
  {
	  volatile unsigned int j;
	
		  P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
		  j++;							//increment j
	  __delay_cycles(10000);             // Delay for 100000*(1/MCLK)=0.1s
	  if (j % 6 == 0)					//if j is divisible by 6, toggle 1.1
	  {
		  P1OUT ^= BIT1;                      // Toggle P1.1 using exclusive-OR
	  }
  }
}

