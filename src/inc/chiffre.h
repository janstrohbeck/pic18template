/** @defgroup chiffre Simple String Encryption
 *  This module provides a simple string encryption algorithm.
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Simple String Ecryption
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

#include "types.h"

/**
 * Simple encryption function
 * 
 * Encrypts a string by numerically adding the characters of the text with those
 * of the key. <br />
 * The decryption reverses this by subtracting the characters of the key
 * from the chracters of the encrypted text. 
 *
 * @param pac8text A pointer to the beginning of the text-string
 * @param pac8key A pointer to the beginning of the key-string
 * @param u8option The Operation to perform on the text: '+' to encrypt, '-' to
 * decrypt.
 */
void chiffre (c8_t *pac8text, c8_t *pac8key, c8_t u8option);
