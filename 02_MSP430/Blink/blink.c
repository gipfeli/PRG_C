//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0
//
//  Description; Toggle P1.0 by xor'ing P1.0 inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED
//
//  Texas Instruments, Inc
//  July 2013
//***************************************************************************************

#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW | WDTHOLD;               // Stop watchdog timer
    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings
    P1DIR |= 0x01;                          // Set P1.0 to output direction
    P4DIR |= 0x01;

    P1OUT = 0x00;
    P4OUT = 0x01;

    LCDM12 = 0x00;
    LCDM13 = 0x00;

    LCDM13 = 0x01;
    LCDM12 = 0x10;

    LCDM13 = 0x03;

    volatile int n;

    for(n = 2; n!=0; n--) {
        volatile unsigned int i;            // volatile to prevent optimization

        P1OUT ^= 0x01;                      // Toggle P1.0 using exclusive-OR
        P4OUT ^= 0x01;

        i = 50000;                          // SW Delay
        do i--;
        while(i != 0);
    }
}
