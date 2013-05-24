/** @defgroup init PIC18F4580 Init functions
 *  This module contains functions to set up our PIC.
 *  It disables unneeded functionality which could also 
 *  eventually cause problems.
 *  @{
 */
/**
 * @file
 * @author Juergen Schuele
 * @version 1.0
 * @date 2013-05-24
 * @brief PIC18F4580 Init functions
 */
/* Copyright (C) 
 * 2013 - Juergen Schuele
 */
#ifndef PIC18INIT_H
#define	PIC18INIT_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 * PIC18F4580 Init function.
 * 
 * Sets up the PIC by disabling unneeded functionality.
 */
void hw_init (void);

#ifdef	__cplusplus
}
#endif

#endif	/* PIC18INIT_H */
/** @} */
