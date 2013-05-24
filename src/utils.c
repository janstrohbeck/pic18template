/** @addtogroup utils
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-23
 * @brief Implements utility functions
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
#include <delays.h>
#include "types.h"
#include "utils.h"
#include "PIC18hardware.h"

void LED ( uint8_t u8led, uint8_t u8action )
{
    switch ( u8action )
    {
        case ON:
            // Create a "1" in LAT -> Logically on
            LEDLAT |= (1 << u8led);
            break;
        case OFF:
            // Create a "0" in LAT -> Logically off
            LEDLAT &= ~(1 << u8led);
            break;
        case TOGGLE:
            // Toggle Bit in LAT -> Switch State
            LEDLAT ^= (1 << u8led);
            break;
        case ENABLED:
            // Create a "0" in TRIS -> Pin is Output -> LED functionallity
            LEDTRIS &= ~(1 << u8led);
            break;
        case DISABLED:
        default:
            // Create a "1" in TRIS -> Pin is Input -> No LED functionallity
            LEDTRIS |= (1 << u8led);
            break;
    }
}

uint8_t button_is_pressed ( volatile uint8_t *u8register, uint8_t u8port )
{
    // Wait for the Button to reach its final state
    Delay10KTCYx ( 1 );
    // Negate the PORT value (-> Pull-Up) and return it
    return ! (*u8register & (1<<u8port)); 
}
/** @} */
