/** @defgroup arithmetic Arithmetic Module
 *  This module contains Functions for safe arithmetic.
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Safe Arithmetic Functions
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

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

/**
 * Safe 16bit Addition
 * 
 * This function handles the cases, that the result of an additon of two 16bit
 * Integers could possibly not fit into a 16bit variable. The result of this
 * could be way different from the real mathematical result. To handle this,
 * this function simply returns the number which would come the closest to the
 * real result.
 * 
 * @param i16arg1 The first number.
 * @param i16arg2 The second number. Will be added to the first number.
 * @return The result of the addition.
 */
int16_t i16LimAdd (int16_t i16arg1, int16_t i16arg2);

/**
 * Safe 16bit Negation
 * 
 * The negation of the lowest possible number in 16bit would result in 1. As
 * this is appearantly not correct, this function catches this case and instead
 * returns the highest possible number in 16bit, which comes closer to the real
 * result.
 * 
 * @param i16arg1 The number to negate.
 * @return The result of the negation of i16arg1.
 */
int16_t i16LimNeg (int16_t i16arg1);

#ifdef __cplusplus
}
#endif

#endif /* ARITHMETIC_H */
/** @} */
