/** @defgroup hwdef Hardware Definitions
 *  Defines Constants for usage in the main program.
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-24
 * @brief Definitons of hardware constants
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
#ifndef PIC18HARDWARE_H
#define	PIC18HARDWARE_H

#ifdef	__cplusplus
extern "C" {
#endif

/// Bit offset of the green LED in both TRIS and LAT registers
#define LEDGREEN 2
/// Bit offset of the yellow LED in both TRIS and LAT registers
#define LEDYELLOW 1
/// Bit offset of the red LED in both TRIS and LAT registers
#define LEDRED 0
/// The LAT register corresponding to the LEDs.
#define LEDLAT LATE
/// The TRIS register corresponding to the LEDs.
#define LEDTRIS TRISE

#ifdef	__cplusplus
}
#endif

#endif	/* PIC18HARDWARE_H */
/** @} */
