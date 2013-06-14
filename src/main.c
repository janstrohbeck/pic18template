/** @defgroup main Main Program
 *  This module contains the main function. Wanted functionality can
 *  be enabled using defines (see source code).
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

/// Use Eggtimer Module
#define EGGTIMER 1
/// Use a timer as a time source (0: None, 1: Polling, 2: Interrupts)
#define TICKER_TIME_SOURCE 2
/// Implement some blinking LEDs
#define BLINK 0
/// Implement the Traffic Light
#define AMPEL 0

#if TICKER_TIME_SOURCE == 2
#include "ms_interrupt.h"
#endif

/// Millisecond Counter
volatile uint32_t u32msTicker = 0;

#if EGGTIMER || TICKER_TIME_SOURCE == 1
#include "eggtimer.h"
#endif

#if AMPEL
#include "ampel.h"
#if TICKER_TIME_SOURCE == 0
#include <delays.h>
#endif
#endif

/**
 * Main Function.
 * 
 * This is the entry point for our program.
 */
void main (void)
{
    // Initialize PIC
    hw_init ();

#if EGGTIMER || TICKER_TIME_SOURCE == 1
    EggTimerInit ();
#endif
#if TICKER_TIME_SOURCE == 2
    msInterruptInit ();
#endif
#if BLINK
    LED (LEDGREEN, ENABLED);
    LED (LEDYELLOW, ENABLED);
    LED (LEDRED, ENABLED);
    LED (LEDGREEN, ON);
    LED (LEDYELLOW, OFF);
    LED (LEDRED, ON);
#endif
#if AMPEL && TICKER_TIME_SOURCE != 0
    uint32_t u32reference = 100;
#endif

    while (true)
    {
#if TICKER_TIME_SOURCE == 1
        u8UpdateMsTicker (& u32msTicker);
#endif
#if EGGTIMER
        EggTimer ((uint32_t *) (& u32msTicker));
#endif
#if BLINK
        LED (LEDGREEN, TOGGLE);
        LED (LEDYELLOW, TOGGLE);
        LED (LEDRED, TOGGLE);
#endif
#if AMPEL
#if TICKER_TIME_SOURCE != 0
        if ((int32_t)(u32msTicker - u32reference) >= 0)
        {
            ampel ();
            u32reference += 100;
        }
#else
        ampel ();
        Delay10KTCYx (100);
#endif
#endif
        // Enter other stuff here...
    }
}
/** @} */
