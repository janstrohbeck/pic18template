/** @defgroup types Typedefines
 *  Defines all the types we are going to need in the project.
 *  @{
 */
/**
 * @file
 * @author Jan Strohbeck
 * @version 1.0
 * @date 2013-05-23
 * @brief Defines all the types we are going to need in the project.
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
#ifndef TYPES_H
#define TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

// #include <stdint.h>
/// 8-Bit Integer (int)
typedef int int8_t;
/// 16-Bit Integer (long int)
typedef long int int16_t;
/// 32-Bit Integer (long long int)
typedef long long int int32_t;
/// unsigned 8-Bit-Integer (unsigned int)
typedef unsigned int uint8_t;
/// unsigned 16-Bit-Integer (unsigned long int)
typedef unsigned long int uint16_t;
/// unsigned 32-Bit-Integer (unsigned long int)
typedef unsigned long long int uint32_t;
/// 8-Bit character (signed char)
typedef signed char c8_t;
/* #define TRUE 1 */
/* #define FALSE 0 */
/// Boolean data type
typedef enum _bool {false=0, true=1} bool;
/// 16-Bit "Floating Point" Data Type (signed long int)
typedef int16_t fp1d15_t;

#ifdef __cplusplus
}
#endif

#endif /* TYPES_H */
/** @} */
