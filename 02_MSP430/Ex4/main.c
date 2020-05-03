#include <msp430.h>
#include <stdint.h>

void showChar(char c, int position);
void showCharB(char c, int position);
void showCharC(char c, int position);
#define pos1 4                                                 // Digit A1 - L4
#define pos2 6                                                 // Digit A2 - L6
#define pos3 8                                                 // Digit A3 - L8
#define pos4 10                                                // Digit A4 - L10
#define pos5 2                                                 // Digit A5 - L2
#define pos6 18                                                // Digit A6 - L18
// Define word access definitions to LCD memories
#define LCDMEMW ((int*)LCDMEM)
#define LCDBMEMW ((int*)LCDBMEM)

// Number of character positions in the display
#define LCD_NUM_CHAR                6
// Memory locations for LCD characters
const uint8_t digit_loc[ LCD_NUM_CHAR ] =
{
       pos1,                                                                    // Position 1 = Digit A1
       pos2,                                                                    // Position 2 = Digit A2
       pos3,                                                                    // Position 3 = Digit A3
       pos4,                                                                    // Position 4 = Digit A4
       pos5,                                                                    // Position 5 = Digit A5
       pos6                                                                     // Position 6 = Digit A6
};

// LCD memory map for fancy icons
const uint8_t symbol_loc[] [2] =
{
    {   2,   0x01},   //  LCD_SEG_MARK,
    {   2,   0x02},   //  LCD_SEG_R,
    {   2,   0x04},   //  LCD_SEG_HEART,
    {   2,   0x08},   //  LCD_SEG_CLOCK,
    {   4,   0x01},   //  LCD_SEG_DOT3,
    {   4,   0x04},   //  LCD_SEG_RADIO,
    {   6,   0x01},   //  LCD_SEG_DOT2,
    {   6,   0x04},   //  LCD_SEG_COLON2,
    {   8,   0x01},   //  LCD_SEG_RX,
    {   8,   0x04},   //  LCD_SEG_TX,
    {  10,   0x01},   //  LCD_SEG_DOT1,
    {  10,   0x04},   //  LCD_SEG_MINUS1,
    {  13,   0x10},   //  LCD_SEG_BAT_POL,
    {  13,   0x20},   //  LCD_SEG_BAT1,
    {  13,   0x40},   //  LCD_SEG_BAT3,
    {  13,   0x80},   //  LCD_SEG_BAT5,
    {  15,   0x01},   //  LCD_SEG_DOT5,
    {  15,   0x04},   //  LCD_SEG_DEG5,
    {  17,   0x10},   //  LCD_SEG_BAT_ENDS,
    {  17,   0x20},   //  LCD_SEG_BAT0,
    {  17,   0x40},   //  LCD_SEG_BAT2,
    {  17,   0x80},   //  LCD_SEG_BAT4,
    {  19,   0x01},   //  LCD_SEG_DOT4,
    {  19,   0x04},   //  LCD_SEG_COLON4,
};

// LCD memory map for numeric digits
const char digit[10][2] =
{
    {0xFC, 0x28},  /* "0" LCD segments a+b+c+d+e+f+k+q */
    {0x60, 0x20},  /* "1" */
    {0xDB, 0x00},  /* "2" */
    {0xF3, 0x00},  /* "3" */
    {0x67, 0x00},  /* "4" */
    {0xB7, 0x00},  /* "5" */
    {0xBF, 0x00},  /* "6" */
    {0xE4, 0x00},  /* "7" */
    {0xFF, 0x00},  /* "8" */
    {0xF7, 0x00}   /* "9" */
};

// LCD memory map for uppercase letters
const char alphabetBig[26][2] =
{
    {0xEF, 0x00},  /* "A" LCD segments a+b+c+e+f+g+m */
    {0xF1, 0x50},  /* "B" */
    {0x9C, 0x00},  /* "C" */
    {0xF0, 0x50},  /* "D" */
    {0x9F, 0x00},  /* "E" */
    {0x8F, 0x00},  /* "F" */
    {0xBD, 0x00},  /* "G" */
    {0x6F, 0x00},  /* "H" */
    {0x90, 0x50},  /* "I" */
    {0x78, 0x00},  /* "J" */
    {0x0E, 0x22},  /* "K" */
    {0x1C, 0x00},  /* "L" */
    {0x6C, 0xA0},  /* "M" */
    {0x6C, 0x82},  /* "N" */
    {0xFC, 0x00},  /* "O" */
    {0xCF, 0x00},  /* "P" */
    {0xFC, 0x02},  /* "Q" */
    {0xCF, 0x02},  /* "R" */
    {0xB7, 0x00},  /* "S" */
    {0x80, 0x50},  /* "T" */
    {0x7C, 0x00},  /* "U" */
    {0x0C, 0x28},  /* "V" */
    {0x6C, 0x0A},  /* "W" */
    {0x00, 0xAA},  /* "X" */
    {0x00, 0xB0},  /* "Y" */
    {0x90, 0x28}   /* "Z" */
};

//Writes to screen 1
 void showChar(char c, int position)
 {
     if (c == ' ')
     {
         // Display space
         LCDMEMW[position/2] = 0;
     }
     else if (c >= '0' && c <= '9')
     {
         // Display digit
         LCDMEMW[position/2] = digit[c-48][0] | (digit[c-48][1] << 8);
     }
     else if (c >= 'A' && c <= 'Z')
     {
         // Display alphabet
         LCDMEMW[position/2] = alphabetBig[c-65][0] | (alphabetBig[c-65][1] << 8);
     }
     else
     {
         // Turn all segments on if character is not a space, digit, or uppercase letter
         LCDMEMW[position/2] = 0xFFFF;
     }
 }

 //Writes to screen 2
 void showCharB(char c, int position)
 {
     if (c == ' ')
     {
         // Display space
         LCDBMEMW[position/2] = 0;
     }
     else if (c >= '0' && c <= '9')
     {
         // Display digit
         LCDBMEMW[position/2] = digit[c-48][0] | (digit[c-48][1] << 8);
     }
     else if (c >= 'A' && c <= 'Z')
     {
         // Display alphabet
         LCDBMEMW[position/2] = alphabetBig[c-65][0] | (alphabetBig[c-65][1] << 8);
     }
     else
     {
         // Turn all segments on if character is not a space, digit, or uppercase letter
         LCDBMEMW[position/2] = 0xFFFF;
     }
 }

int main( void )
{
    WDTCTL = WDTPW | WDTHOLD;                                  // Stop watchdog timer

    // Configure XT1 oscillator
    P4SEL0 |= BIT1 | BIT2;                                     // P4.2~P4.1: crystal pins
    do
    {
        CSCTL7 &= ~(XT1OFFG | DCOFFG);                         // Clear XT1 and DCO fault flag
        SFRIFG1 &= ~OFIFG;
    }while (SFRIFG1 & OFIFG);                                  // Test oscillator fault flag
    CSCTL6 = (CSCTL6 & ~(XT1DRIVE_3)) | XT1DRIVE_2;            // Higher drive strength and current consumption for XT1 oscillator


    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    // Configure LCD pins
    SYSCFG2 |= LCDPCTL;                                        // R13/R23/R33/LCDCAP0/LCDCAP1 pins selected

    LCDPCTL0 = 0xFFFF;
    LCDPCTL1 = 0x07FF;
    LCDPCTL2 = 0x00F0;                                         // L0~L26 & L36~L39 pins selected

    LCDCTL0 = LCDSSEL_0 | LCDDIV_7;                            // flcd ref freq is xtclk

    //LCD Operation - Mode 2
    LCDVCTL = LCDCPEN |                                        //Enable charge pump
            LCDSELVDD |                                        //Internally connect to Vcc
            VLCD_8 |                                           //internal 3.08v
           (LCDCPFSEL0 | LCDCPFSEL1 | LCDCPFSEL2 | LCDCPFSEL3);//Charge pump frequency selection 256Hz

    LCDMEMCTL |= LCDCLRM | LCDCLRBM;                           // Clear LCD memory

    LCDCSSEL0 = 0x000F;                                        // Configure COMs and SEGs
    LCDCSSEL1 = 0x0000;                                        // L0, L1, L2, L3: COM pins
    LCDCSSEL2 = 0x0000;

    LCDM0 = 0x21;                                              // L0 = COM0, L1 = COM1
    LCDM1 = 0x84;                                              // L2 = COM2, L3 = COM3


    showChar('P', pos2);
    showChar('R', pos3);
    showChar('G', pos4);
    showChar('C', pos6);

    LCDBM0 = 0x21;
    LCDBM1 = 0x84;

    showCharB('D', pos1);
    showCharB('A', pos2);
    showCharB('T', pos3);
    showCharB('N', pos5);
    showCharB('G', pos6);

    LCDBLKCTL = LCDBLKPRE__512 |                               //Divide xtclk by 512
            LCDBLKMOD_3;                                       //Switch between memory contents of LCDM and LCDB

    LCDCTL0 |= LCD4MUX | LCDON;                                // Turn on LCD, 4-mux selected

    PMMCTL0_H = PMMPW_H;                                       // Open PMM Registers for write
    PMMCTL0_L |= PMMREGOFF_L;                                  // and set PMMREGOFF

    __bis_SR_register(LPM3_bits | GIE);                        // Enter LPM3
    __no_operation();                                          // For debugger
}
