/** @addtogroup init
 *  @{
 */
/**
 * @file
 * @author Juergen Schuele
 * @version 1.0
 * @date 2013-05-24
 * @brief Implements Init functions
 */
/* Copyright (C) 
 * 2013 - Juergen Schuele
 */
#include <p18cxxx.h>
#include "PIC18hardware.h"
#include "PIC18init.h"

void hw_init (void)
{
    // ADC off
    ADCON0bits.ADON=0;

    // Use ADCpins as digital inputs
    ADCON1bits.PCFG0=1;
    ADCON1bits.PCFG1=1;
    ADCON1bits.PCFG2=1;
    ADCON1bits.PCFG3=1;

    // LED pins are out
    LEDTRIS &= ~((1<< LEDGREEN) | (1<< LEDYELLOW ) | (1<< LEDRED));

    // Disable Comparator
    CMCONbits.CM0=0;
    CMCONbits.CM1=0;
    CMCONbits.CM2=0;

    RCONbits.IPEN = 0;   // Disable peripheral interrupts
    INTCONbits.GIEH = 0; // Disable high priority interrupt
    INTCONbits.GIEL = 0; // Disble low priority interrupt
    IPR1bits.TMR1IP = 0; // Timer 1: Low priority
}
/** @} */
