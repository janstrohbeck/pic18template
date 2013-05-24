/** @defgroup ampel Traffic Light Module
 *  This module creates a function which makes the LEDs of the PIC work like a Traffic light.
 *  It can also react to a button press (similar to a passenger wanting to cross the street).
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Traffic light
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
#ifndef AMPEL_H
#define AMPEL_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Traffic Light function
 * 
 * Implements traffic light functionallity. <br />
 * The default state is that only the green LED is on. <br />
 * On button press, it switches over yellow to red. <br />
 * After some time it switches over yellow/red to green. <br />
 * This sequence is implemented using a state variable iterating over the
 * following states:
 * - 0: Traffic Light is green
 * - 1: Still green, but waiting for the counter
 * - 2: Traffic Light is yellow
 * - 3: Traffic Light is red
 * - 4: Traffic Light is yellow and red
 *
 * States 1-4 all count delays to reach the next state. <br />
 * After State 4, the Traffic Light jumps to State 0 again. <br />
 * To reach state 1, One must press the button (RB4 in this case)
 * 
 * All time constants are configurable in the header file. <br />
 * This function is meant to be called periodically every 100ms. This allows
 * other code to be executed almost simultaneously.
 */
void ampel (void);

/// Ammount of time to last in the "Green" state (state 1)
/// Measured in Tenths of seconds
#define DELAYS_GREEN 50
/// Ammount of time to last in the "Yellow" state (state 2)
/// Measured in Tenths of seconds
#define DELAYS_YELLOW 10
/// Ammount of time to last in the "Red" state (state 3)
/// Measured in Tenths of seconds
#define DELAYS_RED 100
/// Ammount of time to last in the "Yellow/Red" state (state 4)
/// Measured in Tenths of seconds
#define DELAYS_YELLOWRED 10

/// The PORT Register of the button
#define INPPORT PORTB
/// Bit offset of the button to be used in the PORT register
#define INP 4

#ifdef __cplusplus
}
#endif

#endif /* AMPEL_H */
