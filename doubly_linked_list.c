/*
 * doubly_linked_list.c
 *
 *  Created on: Oct 19, 2018
 *      Author: uros
 */

#include "doubly_linked_list.h"

/*
#pragma CHECK_MISRA("none")
 */
#include <stdio.h>
#include <stdlib.h>
/*
#pragma RESET_MISRA("all")
 */

void create_list(double_linked_list* list_c)
{
	list_c->head = (double_linked_data*) NULL;
	list_c->tail = (double_linked_data*) NULL;
}

void delete_list(double_linked_list* list_d)
{
	if (list_d->head == NULL)
	{
		/* MISRA violation 14.7 */
		return;
	}


	double_linked_data* current = list_d->tail;
	while (current != list_d->head)
	{
		current = current->prev;
		/* MISRA violation here 20.4 */
		free(current->next);
	}

	/* MISRA violation here 20.4 */
	free(current);
	list_d->head = (double_linked_data*) NULL;
	list_d->tail = (double_linked_data*) NULL;
}

boolean insert_element(double_linked_list* list_ie, double_linked_data* location_ie, const type data_ie)
{
	/* MISRA violation here 20.4 */
	double_linked_data* element = malloc(sizeof(double_linked_data));
	element->data = data_ie;

	if (location_ie == NULL)
	{
		element->next = list_ie->head;
		element->prev = (double_linked_data*) NULL;
		list_ie->head = element;
	}
	else
	{
		element->next = location_ie->next;
		/* MISRA violation here 17.6 */
		element->prev = location_ie;
		location_ie->next = element;
	}
	if (element->next != NULL)
	{
		element->next->prev = element;
	}
	else
	{
		list_ie->tail = element;
	}
	return (boolean) 1;
}

boolean remove_element(double_linked_list* list_r, double_linked_data* location_r)
{
	if (location_r == (double_linked_data*) NULL)
	{
		/* MISRA violation 14.7 */
		return (boolean) 0;
	}

	if (location_r == list_r->head)
	{
		list_r->head = location_r->next;
	}
	else
	{
		location_r->prev->next = location_r->next;
	}

	if (location_r == list_r->tail)
	{
		list_r->tail = location_r->prev;
	}
	else
	{
		location_r->next->prev = location_r->prev;
	}

	/* MISRA violation 20.4 */
	free(location_r);
	return (boolean) 1;
}

boolean empty_list(const double_linked_list* list_em)
{
	boolean ret_val = 0;
	if (list_em->head == NULL)
	{
		ret_val = 1
	}
	else
	{
		ret_val = 0;
	}

	return ret_val;
}

void print_list(const double_linked_list* list_p)
{
	int8_t i = 0;
	double_linked_data* current_p = list_p->head;
	while (current_p != NULL)
	{
		/* MISRA violation 20.9 */
		printf("Element[%d] = %d\n", i, current_p->data);
		current_p = current_p->next;
		i++;
	}
}
