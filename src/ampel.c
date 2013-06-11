/** @addtogroup ampel
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Implementation of Traffic Light
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
#include "types.h"
#include "ampel.h"
#include "utils.h"

void ampel (void)
{
    // State Variable
    static uint8_t state = 0;
    // Delay Counter
    static uint8_t delays = 0;
    // Here we later set the number of delays required to get to the next state
    uint8_t req_delays = 0;

    // First make sure all LEDs are enabled
    LED (LEDGREEN, ENABLED);
    LED (LEDYELLOW, ENABLED);
    LED (LEDRED, ENABLED);
    // Then turn them all off
    LED (LEDGREEN, OFF);
    LED (LEDYELLOW, OFF);
    LED (LEDRED, OFF);

    // Activate Pull-Up-Resistors for PORTB
    INTCON2bits.RBPU = 0;

    // Is the Button pressed?
    if ( state == 0 && !(INPPORT & (1<<INP)) )
    {
        // Then start the Traffic Light sequence
        state = 1;
    }

    // Switch over the state
    // Enable the corresponding LEDs and set the required delays after which the next state shall be triggered
    switch (state)
    {
        case 1:
            LED (LEDGREEN, ON);
            req_delays = DELAYS_GREEN;
            break;
        case 2:
            LED (LEDYELLOW, ON);
            req_delays = DELAYS_YELLOW;
            break;
        case 3:
            LED (LEDRED, ON);
            req_delays = DELAYS_RED;
            break;
        case 4:
            LED (LEDYELLOW, ON);
            LED (LEDRED, ON);
            req_delays = DELAYS_YELLOWRED;
            break;
        // Idle state
        case 0:
        default:
            // State 0 is default-state
            LED (LEDGREEN, ON);
            break;
    }

    // Only check for delays when not in idle state 0
    if (state != 0)
    {
        // If the required delays are reached
        if (delays == req_delays)
        {
            // Go to the next state
            state++;
            // And reset the delay counter
            delays = 0;
        }

        // Increment counter
        delays++;

        // At the end of the sequence
        if (state > 4)
            // Go to idle state again
            state = 0;
    }
}
/** @} */

