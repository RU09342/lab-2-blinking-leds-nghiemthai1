
//******************************************************************************
//  MSP430FR5x9x Demo - Toggle P1.0 using software
//
//  Description: Toggle P1.0 using software.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//           MSP430FR5994
//         ---------------
//     /|\|               |
//      | |               |
//      --|RST            |
//        |               |
//        |           P1.0|-->LED
//
//   William Goh
//   Texas Instruments Inc.
//   October 2015
//   Built with IAR Embedded Workbench V6.30 & Code Composer Studio V6.1
//******************************************************************************
#include <msp430.h>

int position = 0;
int currentON = 0;

int main(void)
{

    WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT

    // Configure GPIO
    P1OUT &= ~BIT0;      // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    P4OUT &= ~BIT7;      // Clear P1.1 output latch for a defined power-on state
    P4DIR |= BIT7;                          // Set P1.1 to output direction

    P2DIR &= ~BIT1;                         // Set P2.1 to input direction
    P2REN |= BIT1;                          // Enable resistor for P2.1

    while (1)
    {
            int i;
            int x = 0;
            i = 0;
            for (; i < 200 && i >= 0; x++)
            {
                int cnt;
                for (cnt = 0; cnt < i; cnt++)
                {
                    if(!(P2IN & BIT1)){
                        P4OUT &= ~BIT7;
                        P1OUT &= ~BIT0;
                    }else{
                        P4OUT &= ~BIT7;
                        P1OUT |= BIT0;
                    }
                }

                for (cnt = 0; cnt < 200 - i; cnt++)
                {
                    if(!(P2IN & BIT1)){
                        P4OUT |= BIT7;
                    } else{
                        P1OUT &= ~BIT0;
                    }
                }

                if (x == 2)
                {
                    x = 0;
                    i++;
                }

            }
    }
}
