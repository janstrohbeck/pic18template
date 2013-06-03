/** @defgroup sin Lookup-Sinus
 *  This module contains a function calculating the sinus of a given angle.
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-06-03
 * @brief Lookup-Sinus
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

#ifndef SIN_H
#define SIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

/**
 * Sinus Funktion with Lookup-Table
 * 
 * Calculates the Sinus of a given angle using a Lookup-Table. <br />
 * The Lookup-Table is defined only for 0 <= phi <= 90 Degrees.
 * 
 * @param i16phi The angle in degrees.
 * @return The sinus of the angle in 16-Bit-Integer representation. Divide
 * by 2**15 to get the value in floating point representation.
 */
fp1d15_t fp1d15sin (int16_t i16phi);

#ifdef __cplusplus
}
#endif

#endif /* SIN_H */

/** @} */
