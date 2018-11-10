/*
 * functions.c
 *
 *  Created on: Oct 23, 2018
 *      Author: uros
 */

#include "functions.h"
#include <stdlib.h>
boolean odd_or_even(const double_linked_data* element)
{
	boolean ret_val = 0;
	if ((element->data % 2) == 0)
	{
		ret_val = 1;
	}
	else
	{
		ret_val = 0;
	}
	return ret_val;
}

void check(double_linked_list* list_c, boolean (*parity)(double_linked_data*))
{
	double_linked_data* current = list_c->head;
	while (current != NULL)
	{
		if (parity(current) == 1)
		{
			remove_element(list_c, current);
		}

		current = current->next;
	}
}
