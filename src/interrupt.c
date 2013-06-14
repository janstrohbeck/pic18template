/** @addtogroup interrupt Interrupt Handlers
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @since 2013-06-12
 * @brief Implements Interrupt Handlers (ISR)
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
#include "interrupt.h"
#include "ms_interrupt.h"

void interrupt high_priority high_interrupt (void)
{
    #if TIMER_PRIORITY == 1
        timer_interrupt ();
    #endif
}

void interrupt low_priority low_interrupt (void)
{
    #if TIMER_PRIORITY == 0
        timer_interrupt ();
    #endif
}
/** @} */
