/** @defgroup eggtimer Egg Timer Module
 *  This module contains functions to create an egg timer using timers.
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-29
 * @brief Egg Timer
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
#ifndef EGGTIMER_H
#define EGGTIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

/**
 * Handles incrementing a given Millisecond Ticker.
 * 
 * Increments the Millisecond Ticker using Timer1 as a time source.
 * Expects Timer1 to be set up so that it is incremented every 100ns.
 *                                                                      
 * @param pu32ticker A pointer to the Millisecond Ticker
 * @return 1 if the Ticker has been incremented, else 0.
 */
uint8_t u8UpdateMsTicker (uint32_t *pu32ticker);

/**
 * Implements an Egg Timer.
 * 
 * Imitates an Egg Timer using the LEDs. Turns the LEDs on according
 * to the value of the given Millisecond Ticker. The sequence is started
 * by pressing a button connected to RB4. During the first minute, 
 * it toggles the green LED every second and turns yellow and red on. During the second
 * minute, it turns green off, toggles yellow and turns red on. During the third
 * minute, it turns off green and yellow, and toggles red every second. Lastly,
 * all LEDs flash for a minute (Egg Timer has expired).
 * 
 * @param pu32ticker A pointer to the Millisecond Ticker
 */
void EggTimer (uint32_t *pu32ticker);

/**
 * Egg Timer Initialization.
 *
 * Initializes the PIC for the Egg Timer function.
 */
void EggTimerInit (void);

#ifdef __cplusplus
}
#endif

#endif /* EGGTIMER_H */
/** @} */
