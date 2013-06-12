/** @addtogroup ms_interrupt
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-29
 * @brief Millisecond Ticker using Interrupts
 */
/* Copyright (C) 
 * 2013 - Jan Strohbeck
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

#include <p18cxxx.h>
#include "PIC18hardware.h"
#include "ms_interrupt.h"
#include "types.h"
#include "utils.h"

void msInterruptInit (void)
{
    RCONbits.IPEN = 1;       // Disable PIC16 Compatibility mode

#ifndef INT_DEBUG
    // Configure Timer1 Interrupts
    IPR1bits.TMR1IP = 0;     // Set Timer1 Interrupt as low priority
    PIE1bits.TMR1IE = 1;     // Enable Timer1 Interrupt on Overflow
#else
    // Configure Timer3 for testing purposes
    T3CONbits.TMR3CS = 0;    // Use internal Clock
    T3CONbits.T3CKPS = 0;    // Turn off Prescaler
    T3CONbits.T3RD16 = 1;    // Enable TMR3H Buffer Register
    IPR2bits.TMR3IP = 1;     // Timer3 Interrupt is high priority
    PIE2bits.TMR3IE = 1;     // Enable Timer3 Interrupt
    T3CONbits.TMR3ON = 1;    // Activate Timer3

    PIE1bits.TMR1IE = 0;     // Disable Timer1 Interrupts
#endif

    // Finally enable Interrupts
    INTCONbits.GIEL = 1;     // Globally enable low priority interrupts
    INTCONbits.GIEH = 1;     // Globally enable high priority interrupts

#ifndef INT_DEBUG
    // Pre-Set Timer1-Value
    uint16_t u16new = -10000;
    // Write Value to Timer (High byte first)
    TMR1H = u16new >> 8;
    TMR1L = u16new;
#else
    // Pre-Set Timer3-Value
    uint16_t u16new = -10000;
    // Write Value to Timer (High byte first)
    TMR3H = u16new >> 8;
    TMR3L = u16new;
#endif
}

void interrupt high_priority high_interrupt (void)
{
#ifdef INT_DEBUG
    // If Timer3 Interrupt Flag is set
    if (PIR2bits.TMR3IF)
    {
        // One millisecond has passed -> Increment Millisecond Counter
        u32msTicker++;
        // get current Timer1 count (read low byte first)
        uint16_t u16counter = TMR3L;
        // Then read the high byte (from the latch)
        u16counter |= (TMR3H << 8);
        // calculate new value for the Timer
        uint16_t u16new = u16counter - 10000
                          + 19; // Manual adjust
        // Write Value to Timer (high byte first -> Latch)
        TMR3H = u16new >> 8;
        TMR3L = u16new;

        // Finally clear Timer3 interrupt flag
        PIR2bits.TMR3IF = 0;
    }
#endif
}

void interrupt low_priority low_interrupt (void)
{
#ifndef INT_DEBUG
    // If Timer1 Interrupt Flag is set
    if (PIR1bits.TMR1IF)
    {
        // One millisecond has passed -> Increment Millisecond Counter
        u32msTicker++;
        // get current Timer1 count (read low byte first)
        uint16_t u16counter = TMR1L;
        // Then read the high byte (from the latch)
        u16counter |= (TMR1H << 8);
        // calculate new valuew for the Timer
        uint16_t u16new = u16counter - 10000
                          + 19; // Manual adjust
        // Write Value to Timer (high byte first -> Latch)
        TMR1H = u16new >> 8;
        TMR1L = u16new;

        // Finally clear Timer1 interrupt flag
        PIR1bits.TMR1IF = 0;
    }
#endif
}
/** @} */
