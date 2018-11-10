/*
 * functions.h
 *
 *  Created on: Oct 23, 2018
 *      Author: uros
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "doubly_linked_list.h"

boolean odd_or_even(const struct double_linked_data_t* element);
/* MISRA violation 16.3 */
void check(struct double_linked_list_t* list_c, boolean (*parity)(struct double_linked_data_t*));
void main(void);

#endif /* FUNCTIONS_H_ */
