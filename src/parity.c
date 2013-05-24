/** @addtogroup parity
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Implements parity functions
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
#include "parity.h"
#include "types.h"

uint8_t u8ones (uint8_t u8byte)
{
    // Number of ones - counter
    uint8_t u8cnt = 0;
    uint8_t i;

    // Iterate over all bits
    for ( i = 0; i < 8; i++ )
    {
        // If bit is set, increment counter
        u8cnt += BIT_IS_SET (u8byte, i);
    }
    // return counter
    return u8cnt;
}

uint8_t u8evenparity (uint8_t u8sevenbits)
{
    // Invalid Bitfield?
    if (BIT_IS_SET (u8sevenbits, 7)) 
        // Return error code
        return 0xFF; 

    // Shift the Bitfield by one position to the left
    u8sevenbits <<= 1;

    // Odd number of ones?
    if (u8ones (u8sevenbits) % 2 == 1)
        // Set Bit at Position 0
        u8sevenbits = SET_BIT (u8sevenbits, 0); 

    // return resulting Bitfield
    return u8sevenbits;
}
/** @} */
