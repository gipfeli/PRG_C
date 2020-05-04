#include <msp430.h>
#include "hal_LCD.h"

// Backup Memory variables to track states through LPM3.5
volatile unsigned char * S1buttonDebounce = &BAKMEM2_L;       // S1 button debounce flag
volatile unsigned char * S2buttonDebounce = &BAKMEM2_H;       // S2 button debounce flag

// Define word access definitions to LCD memories
#define LCDMEMW ((int*)LCDMEM)
#define LCDBMEMW ((int*)LCDBMEM)

#define BUTTON1     BIT2 // Port 1.2

#define BUTTON2     BIT6 // Port 2.6

int main( void )
{
    WDTCTL = WDTPW | WDTHOLD;                                  // Stop watchdog timer

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    P1DIR |= 0x01;                                           // Set P1.0 to output
    P4DIR |= 0x01;                                           // Set P4.0 to output

    P1OUT = 0x00;
    P4OUT = 0x00;

    // Button 1 setup
    P1DIR &= ~BUTTON1;               // button is an input
    P1OUT |= BUTTON1;                // pull-up resistor
    P1REN |= BUTTON1;                // resistor enabled

    // Button 2 setup
    P4DIR &= ~BUTTON2;               // button is an input
    P4OUT |= BUTTON2;                // pull-up resistor
    P4REN |= BUTTON2;                // resistor enabled

    volatile int n;
    int m = 6;                      // full battery
    Init_LCD();

    for(n = 2; n!=0; n--) {
        displayScrollText("PRG C DAT NGUYEN");
    }

    for(;;){
        volatile unsigned int i,j;            // volatile to prevent optimization

        // while the button is pressed
        if (P1IN & BUTTON1){
            P1OUT &= ~0x01;
        } else {
            P1OUT |= 0x01;
            if (m>0) m--;
            i = 50000;                          // SW Delay
            do i--;
            while(i != 0);
        }
/*
        // while the button is pressed
        if (!(P2IN & BUTTON2)) {
            P4OUT &= ~0x01;
        } else{
            P4OUT |= 0x01;
            if (m<6) m++;
            j = 50000;                          // SW Delay
            do j--;
            while(j != 0);
        }
*/
        switch(m){
        case 6:
            LCDM12 = 0xF0;
            LCDM13 = 0x0F;
            break;
        case 5:
            LCDM12 = 0x70;
            LCDM13 = 0x0F;
            break;
        case 4:
            LCDM12 = 0x70;
            LCDM13 = 0x07;
            break;
        case 3:
            LCDM12 = 0x20;
            LCDM13 = 0x07;
            break;
        case 2:
            LCDM12 = 0x20;
            LCDM13 = 0x03;
            break;
        case 1:
            LCDM12 = 0x10;
            LCDM13 = 0x03;
            break;
        default:
            LCDM12 = 0x10;
            LCDM13 = 0x01;
            break;
        }
    }

}
