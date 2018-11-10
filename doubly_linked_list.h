/*
 * doubly_linked_list.h
 *
 *  Created on: Oct 23, 2018
 *      Author: uros
 */

#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_


/*
#pragma CHECK_MISRA("none")
#pragma CHECK_MISRA("-20.4")
#pragma CHECK_MISRA("-14.7")
#pragma CHECK_MISRA("-17.6")
 */
#include <stdint.h>
#include <inttypes.h>

/*
#pragma RESET_MISRA("all")
*/

typedef uint_least8_t boolean;
typedef int_least32_t type;

typedef struct double_linked_data_t
{
	type data;
	struct double_linked_data_t* next;
	struct double_linked_data_t* prev;
} double_linked_data;

typedef struct double_linked_list_t
{
	struct double_linked_data_t* head;
	struct double_linked_data_t* tail;
} double_linked_list;

void create_list(double_linked_list* list_c);
void delete_list(double_linked_list* list_d);
boolean insert_element(double_linked_list* list_ie, double_linked_data* location_ie, const type data_ie);
boolean remove_element(double_linked_list* list_r, double_linked_data* location_r);
boolean empty_list(const double_linked_list* list_em);
void print_list(const double_linked_list* list_p);

#endif /* DOUBLY_LINKED_LIST_H_ */
