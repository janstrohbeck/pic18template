/** @defgroup ms_interrupt
 *  This module contains functions to create a millisecond ticker using
 *  Interrupts. It can either use Timer1 or Timer3 as a time source, depending
 *  on if the INT_DEBUG flag is set or not.
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-29
 * @brief Millisecond Timer using Interrupts
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
#ifndef EGGTIMER_INTERRUPT_H
#define EGGTIMER_INTERRUPT_H

#ifdef __cplusplus
extern "C" {
#endif

#define INT_DEBUG

#include "types.h"

/// our Millisecond Ticker is defined in the main C file -> extern
extern volatile uint32_t u32msTicker;

/**
 * Init function for the Millisecond Ticker based
 * on Timer Interrupt.
 * 
 * Initializes all Registers and functionality related to
 * Timer1 and its interrupt.
 */
void msInterruptInit (void);

/**
 * General handler function for low-priority interrupts.
 * 
 * Handles interrupts by looking up which functionality caused
 * the interrupt.
 */
void interrupt low_priority low_interrupt (void);

#ifdef __cplusplus
}
#endif

#endif /* EGGTIMER_INTERRUPT_H */
/** @} */
