
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "micro_config.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define N_col 3
#define N_row 4

#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_DIR DDRA
#define KEYPAD_PORT_IN PINA

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 KeyPad_getPressedKey(void);

#endif /* KEYPAD_H_ */
