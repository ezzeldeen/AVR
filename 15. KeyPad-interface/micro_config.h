/*
 * micro_config.h
 *
 *  Created on: Mar 15, 2022
 *      Author: Ezz Eldeen
 */

#ifndef MICRO_CONFIG_H_
#define MICRO_CONFIG_H_

#ifndef F_CPU
#define F_CPU 1000000UL //1MHz Clock frequency
#endif

//#include <avr/io.h>
//#include <avr/interrupt.h>
#include <util/delay.h>

#include "MemMap32.h"
#include "std_types.h"
#include "macros.h"

#endif /* MICRO_CONFIG_H_ */
