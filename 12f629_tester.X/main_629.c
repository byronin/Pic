/*
 * File:   main_629.c
 * Author: Ronin
 *
 * Created on September 3, 2020, 11:54 PM
 */
/*          

* 
*                                        * * * * * * * * * * * * *
*                                       *                         * 
*                                   ***** VDD/VSS         VSS/GND ***** 
*                                       *                         * 
*                                       *                         * 
*                                       *                         * 
*            GP5/T1CKI/OSC1/CLKIN   *****                    DAT  *****   GP0/CIN+/ICSPDAT
*                                       *                         * 
*                                       *        PIC12F629        * 
*                 ___                   *                         * 
*             GP4/T1G/OSC2/CLKOUT   *****                    CLK  *****   GP1/CIN-/ICSPCLK
*                                       *                         * 
*                                       *                         * 
*                                       *                         * 
*                    GP3/MCLR/VPP   ***** MCLR/RST                *****   GP2/T0CKI/INT/COUT
*                                       *                         * 
*                                        * * * * * * * * * * * * * 
PIC12F629*/


#pragma config FOSC = INTRCCLK   // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-Up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is MCLR)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)


// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000

#include <xc.h>

void main(void)
{
    TRISIO2 = 0 ; 
    TRISIO5 = 1 ;
    while(1)
    {
        
        if(GP5 == 0){
            GP2 = 0;  
        }else{
            GP2 = 1;         
       __delay_ms(1000); 
       GP2 = 0;  
        }
  
    }
}
