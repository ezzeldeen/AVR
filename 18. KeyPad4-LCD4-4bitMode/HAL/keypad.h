
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "MemMap32.h"
#include "std_types.h"
#include "micro_config.h"
#include "macros.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define N_col 4
#define N_row 4

#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_DIR DDRA
#define KEYPAD_PORT_IN PINA

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 Keypad_getkey(void);

#endif /* KEYPAD_H_ */
