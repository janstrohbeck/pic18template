/** @addtogroup eggtimer
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-29
 * @brief Eggtimer Module
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
#include "eggtimer.h"
#include "types.h"
#include "utils.h"
#include "PIC18hardware.h"

uint8_t u8UpdateMsTicker (uint32_t *pu32ticker)
{
    // Reference Value for the Timer
    static uint16_t i16referenz = 0;
    // Current Value of the Timer
    uint16_t u16counter = (TMR1L | (TMR1H << 8));

    // Stepped over Reference Time?
    if ((int16_t) (i16referenz - u16counter) < 0)
    {
        // Increment Millisecond Ticker
        (*pu32ticker)++;
        // Set Reference Value to 10000 x 100ns = 1ms into the future
        i16referenz = u16counter + 0x2710;
        // Ticker has been incremented
        return 1;
    }
    // Ticker has not been incremented
    return 0;
} // u8UpdateMsTicker

void EggTimerInit ()
{
    // Configure Timer
    T1CONbits.TMR1ON = 1;    // Activate Timer1
    T1CONbits.TMR1CS = 0;    // Use internal Clock
    T1CONbits.T1OSCEN = 0;   // Deactivate Timer1 Oscillator
    T1CONbits.T1CKPS = 0b10; // Prescale to 1/4 
    T1CONbits.T1RD16 = 0;    // Read timer as 2*8bit

    // Activate Pull-Up-Restistors at PORTB
    INTCON2 &= (1<<7);       

    // Configure LEDs
    LED (LEDGREEN, ENABLED);
    LED (LEDRED, ENABLED);
    LED (LEDYELLOW, ENABLED);
    LED (LEDGREEN, OFF);
    LED (LEDRED, OFF);
    LED (LEDYELLOW, OFF);
} // EggTimerInit

void EggTimer (uint32_t *pu32ticker)
{
    // Egg Timer state
    static uint8_t u8state = 0;
    // Dummy variable to prevent multiple toggling during the same millisecond
    static uint8_t u8toggled = 0;

    // Not during idle state
    if (u8state != 0)
    {
        // Has one second eleapsed?
        if (*pu32ticker % 1000 == 0)
        {
            // If it hasn't been toggled yet
            if (!u8toggled)
            {
                // If one minute has eleapsed, go to the next state
                if (*pu32ticker > 0 && *pu32ticker % 60000 == 0)
                    u8state ++;

                // Toggle/Switch on LEDs accoring to state
                switch (u8state)
                {
                    case 1:
                        LED (LEDRED, TOGGLE);
                        LED (LEDYELLOW, ON);
                        LED (LEDGREEN, ON);
                        break;
                    case 2:
                        LED (LEDRED, OFF);
                        LED (LEDYELLOW, TOGGLE);
                        LED (LEDGREEN, ON);
                        break;
                    case 3:
                        LED (LEDRED, OFF);
                        LED (LEDYELLOW, OFF);
                        LED (LEDGREEN, TOGGLE);
                        break;
                    case 4:
                        LED (LEDRED, TOGGLE);
                        LED (LEDYELLOW, TOGGLE);
                        LED (LEDGREEN, TOGGLE);
                        break;
                    case 5:
                    default:
                        // Back to idle state
                        u8state = 0;
                        break;
                }
                // LED have been toggled/switched on
                u8toggled = 1;
            }
        }
        else
            // Make it possible to toggle/switch again
            u8toggled = 0;
    }
    // Button RB4 pressed?
    else if (! (PORTB & (1<<4)))
        // Start the Sequence
        u8state = 1;
} // EggTimer
/** @} */
