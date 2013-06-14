/** @defgroup interrupt Interrupt Handler functions
 * This module contains the Interrupt Handler functions (ISR).
 * @{
*/
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @since 2013-06-12
 * @brief Interrupt Handler functions
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
 */
#ifndef INTERRUPT_H
#define INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * General handler function for low-priority interrupts.
 * 
 * Handles interrupts by looking up which functionality caused
 * the interrupt.
 */
void interrupt low_priority low_interrupt (void);

/**
 * General handler function for high-priority interrupts.
 * 
 * Handles interrupts by looking up which functionality caused
 * the interrupt.
 */
void interrupt high_priority high_interrupt (void);

#ifdef __cplusplus
}
#endif

#endif /* INTERRUPT_H */
/** @} */
