/*
 * Аутор: Урош Радујко РА 179-2015
 *
 * 41. Написати функцију која представља двоструко спрегнуту листу. Модул извести као
 * статичку библиотеку. Направити функцију која избацује из листе све елементе који
 * не испуњавају задати услов. Функција као параметар прима показивач на функцију
 * за проверу услова за један елемент.
 *
 * Задатак је реализован помоћу 2 одвојена модула, од којих један садржи оне функције и
 * структуре које су стриктно везане само за двоструко спрегнуту листу док друга садржи
 * оне функције које су биле дефинисане задатком.
 *
 * Први модул - статичка библиотека - у себи садржи две структуре (једну за тип података
 * а другу за саму листу) и шест функција (иницијализовање празне листе, брисање листе,
 * уметање елемента у листу, уклањање елемента из листе, пражњење целе листе и штампање
 * свих елемената листе на конзоли).
 *
 * Други модул - садржи функцију за проверавање валидности једног елемента, и функцију
 * која све елементе који нису валидни избацује из листе, а као параметар прима
 * функцију која проверава један елемент. У прототипе функција је убачен и прототип
 * функције main, ради правила MISRA стандарда који каже да свака функција мора имати
 * прототип.
 *
 * Кључном речју typedef је олакшана измена кода и његово проверавање за више
 * различитих типова.
 *
 * Унутар функције main позване су функције дефинисане модулима, направљена је
 * двоструко спрегнута листа и демонстриране све функције из датих модула.
 *
 * MISRA стандард је прекршен на више места, али је на сваком месту означен прописном
 * ознаком, са бројем правила које је прекршено, тачно изнад линије кода која га крши.
 * У питању су правила:
 * 9.1 променљива коришћена пре доделе вредности
 * 10.1 имплицитна конверзија
 * 12.2 проблем са инкрементом
 * 14.7 није једнозначно одређено место где се завршава програм
 * 16.3 фале параметри у прототипу функције
 * 20.4 динамичко заузимање меморије
 * 20.9 коришћење исписа на конзолу
 */



#include "doubly_linked_list.h"
#include "functions.h"

/* #pragma CHECK_MISRA("none"); */
#include <stdio.h>
/* #pragma RESET_MISRA("all"); */

/*
#pragma CHECK_MISRA("-16.3")
#pragma CHECK_MISRA("-9.1")
#pragma CHECK_MISRA("-12.2")
#pragma CHECK_MISRA("-10.1")
#pragma CHECK_MISRA("-20.9")
*/

void main(void)
{
	struct double_linked_list_t list;

	/* MISRA violation 16.3 and 9.1, "list" used before it is initialized  */
	create_list(&list);

	/* MISRA violation 12.2, 10.1 in insert_element */
	insert_element(&list, NULL, 17);
	insert_element(&list, list.tail, 58);
	insert_element(&list, list.tail, 23);
	insert_element(&list, list.tail, 985);
	insert_element(&list, list.tail, 108);
	insert_element(&list, list.head, 245);
	insert_element(&list, list.tail, 876);
	insert_element(&list, list.tail, 4735);
	insert_element(&list, list.tail, 921);
	insert_element(&list, list.tail, 844);
	insert_element(&list, list.head, -250);
	insert_element(&list, list.head, -45);
	insert_element(&list, list.head, 11);
	insert_element(&list, list.tail, 30325);

	remove_element(&list, list.head);
	remove_element(&list, list.tail);

	print_list(&list);
	/* MISRA violation 20.9 */
	printf("\n\n");
	boolean (*parity_ptr)(double_linked_data*) = &odd_or_even;

	check(&list, parity_ptr);
	print_list(&list);

	empty_list(&list);
	delete_list(&list);

	return;
}
