
//******************************************************************************
//  MSP430FR231x
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
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer

    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    P1DIR &= ~BIT1;                         // Set P1.1 to input direction
    P1REN |= BIT1;                          // Enable resistor for P1.1


    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1){
        if(!(P1IN & BIT1))						// If you press P1.1 button
        {
            P1OUT ^= BIT0;                      // Toggle P1.0 using exclusive-OR
        }
        else{
            P1OUT &= ~BIT0;                     // Clear P1.0 using exclusive-OR
        }

    }
}
