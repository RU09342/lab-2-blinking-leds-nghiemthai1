
//******************************************************************************
//  MSP430FR5x9x 
//		Extra work
//  Description: LED1 will dim, while LED2 will brighten. When you press the button, 
// 					this process will be reversed. 
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
//   Ardit Pranvoku and Thai Nghiem
//   Rowan University
//   September 2017
//   Built with IAR Embedded Workbench V6.30 & Code Composer Studio V6.1
//******************************************************************************
#include <msp430.h>

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
    P2OUT |= BIT1;							// Enables pull down resistor for P2.1

    while (1)
    {
         const int duty = 500;				//Acts as a total time
         int load;

         for (load = 0; load < duty ; load++)	//Load is incremented up to duty
         {
             int i;
             for (i = 0; i < duty; i ++)		// i is also incremented up to duty.
             {
                 if(!(P2IN & BIT1))    //If button is pressed, this functionality is activated.
                 {
                     if(i < load)     //if i is less then steadily increasing load, LED is flipped on.
                                      //Ratio of when LED is on increases as load increases.
                       {
                          P4OUT &= ~BIT7;	//While i is less than load, P4.7 is turned off.
                          P1OUT |= BIT0;	//While i is less than load, P1.0 is turned on.
                       }
                     else
                        {
                          P4OUT |= BIT7;    //While i is greater than load, P4.7 is turned on.
                          P1OUT &= ~BIT0;   //While i is greater than load, P1.0 turned on. 
						  //Thus, P1.0 will be going from dim to bright while the button is pressed, and P4.7 will be going from bright to dim.
                        }

                 }
                 else                 //If button is not pressed, this alternate functionality is activated.
                 {
                     if(i > load)	//if i is greater than steadily increasing load, P1.0 is turned on, and will go from bright to dim.
                           {
                               P4OUT &= ~BIT7; //While i is greater than load, P4.7 is turned off.
                               P1OUT |= BIT0;  //While i is greater than load, P1.o is turned on.
                           }
                     else
                           {
                               P4OUT |= BIT7;  //While i is less than load, P4.7 is turned on.
                               P1OUT &= ~BIT0; //While i is less than load, P1.0 is turned off.
                           }
                 }
             }
         }
   }
}
