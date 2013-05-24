/** @addtogroup chiffre
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Implements encryption function
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
#include "chiffre.h"
#include "types.h"

void chiffre (c8_t *pac8text, c8_t *pac8key, c8_t u8option)
{
    // Position in the key-string (offset from the beginning)
    uint8_t u8count = 0;

    // While we are not yet at the end of the string
    while (*pac8text != 0)
    {
        // Perform an action depending on the option
        switch (u8option) {
            case '+':
                // Add the character which is at the current position in the key
                // string to the current character of the text.
                *pac8text += pac8key[u8count];
                break;
            case '-':
                // Subtract the character which is at the current position in
                // the key from the current character of the text.
                *pac8text -= pac8key[u8count];
                break;
            default:
                // Invalid option. Sorry.
                return;
        }
        // Incrementing the Pointer will move one position to the right in the
        // string.
        pac8text++;
        // Move right in the key string.
        u8count++;
        // If the end of the key string is reached
        if (pac8key[u8count] == 0)
            // Reset our position to the beginning of the string
            u8count = 0;
    }
}
