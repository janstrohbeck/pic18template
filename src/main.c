/** @defgroup main Main Program
 *  This module contains the main function.
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Main Program
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

#include <p18cxxx.h>
#include "types.h"
#include "PIC18init.h"
#include "PIC18hardware.h"
#include "utils.h"

// Set CPU Frequency to 40 Mhz
#pragma config OSC=HSPLL
// Turn off Watchdog
#pragma config WDT=OFF

// Uncomment the wanted test functionality as needed (one at a time)
//#define EGGTIMER
#define EGGTIMER_INTERRUPT
//#define BLINK
//#define AMPEL

#ifdef EGGTIMER
#include "eggtimer.h"
#elif defined EGGTIMER_INTERRUPT
#include "eggtimer.h"
#include "ms_interrupt.h"

volatile uint32_t u32msTicker = 0;

#elif defined AMPEL
#include "ampel.h"
#endif

void main (void)
{
    // Initialize PIC
    hw_init ();

#if defined EGGTIMER || defined INT_DEBUG
    // Eleapsed milliseconds
    uint32_t u32msTicker2 = 0;

    EggTimerInit ();
#elif defined EGGTIMER_INTERRUPT
    EggTimerInit ();
    msInterruptInit ();
#elif defined BLINK
    LED (LEDGREEN, ENABLED);
    LED (LEDYELLOW, ENABLED);
    LED (LEDRED, ENABLED);
    LED (LEDGREEN, ON);
    LED (LEDYELLOW, OFF);
    LED (LEDRED, ON);
#endif
    while (TRUE)
    {
#ifdef EGGTIMER
        u8UpdateMsTicker (& u32msTicker2);
        EggTimer (& u32msTicker2);
#elif defined EGGTIMER_INTERRUPT
    #ifdef INT_DEBUG
        u8UpdateMsTicker (& u32msTicker2);
    #endif
        EggTimer ((uint32_t *) (& u32msTicker));
#elif defined BLINK
        LED (LEDGREEN, TOGGLE);
        LED (LEDYELLOW, TOGGLE);
        LED (LEDRED, TOGGLE);
#elif defined AMPEL
        ampel ();
#endif
        // Do amazing stuff here...
    }
}
/** @} */
