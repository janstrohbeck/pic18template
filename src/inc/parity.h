/** @defgroup parity Parity
 *  This module contains functions concerning the parity of bitfields.
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Parity functions
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
#ifndef PARITY_H
#define PARITY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

/// Macro to check if the bit cnt in num is set
#define BIT_IS_SET(num, cnt) ((num & (1 << cnt)) != 0)
/// Macro to set bit cnt in num
#define SET_BIT(num, cnt) (num | (1 << cnt))
/// Macro to unset bit cnt in num
#define UNSET_BIT(num, cnt) (num & ~(1 << cnt))

/**
 * Calculates the number of set bits in a given bitfield.
 * 
 * @param u8byte The bitfield
 * @return The number of set bits (ones)
 */
uint8_t u8ones (uint8_t u8byte);

/**
 * Restores Parity in a bitfield.
 * 
 * If the bitfield has an odd number of set bits, this function will restore
 * parity by setting bit 0 in the bitfield. <br />
 * Important: In order to prevent destruction of the information, the bitfield
 * will be shiftet by one position to the left. If the bit of highest value is
 * already set, an error code is returned.
 * 
 * @param u8sevenbits The bitfield where only the first seven bits may be set.
 * @return The resulting bitfield with parity.
 */
uint8_t u8evenparity (uint8_t u8sevenbits);

#ifdef __cplusplus
}
#endif

#endif /* PARITY_H */
/** @} */
