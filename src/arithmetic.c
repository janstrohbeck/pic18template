/** @addtogroup arithmetic
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Implements Functions for safe Arithmetic.
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
#include "arithmetic.h"
#include "types.h"

int16_t i16LimAdd (int16_t i16arg1, int16_t i16arg2)
{
    // Perform Addition in 32bit, so that no bits are lost if result is too high
    int32_t i32res = (int32_t) i16arg1 + (int32_t) i16arg2;

    // If result is too high for 16bit
    if (i32res > (int32_t)0x00007FFF)
        // Simply return the highest possible 16bit number
        return 0x7FFF;
    // If result is too low for 16bit
    else if (i32res < (int32_t)0xFFFF8000)
        // Simply return the lowest possible 16bit number
        return 0x8000;
    // Otherwise result must be ok, cast it to 16bit and return it
    return (int16_t)i32res;
}

int16_t i16LimNeg (int16_t i16arg1)
{
    // If the number is the lowest possible number in 16bit
    if (i16arg1 == 0x8000)
        // Return the highest possible number in 16bit
        return 0x7FFF;
    // For all other numbers the normal negation should work as expected.
    return -i16arg1;
}
/** @} */
