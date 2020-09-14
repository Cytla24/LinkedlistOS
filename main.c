/*
 ============================================================================
 Name        : LinkedListOS.c
 Author      : Aimie Ojuba
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#include "list.h"

int main() {
	list_t* hi = list_alloc();
	node_t* tmp;
	tmp->value = 5;
	hi->head = tmp;
	node_t* tmp2;
	tmp2 = malloc(sizeof(node_t));
	tmp2->value = 25;
	node_t* tmp3;
	tmp3 = malloc(sizeof(node_t));
	tmp3->value = 35;
	tmp3->next = NULL;
	tmp->next = tmp2;
	tmp2->next = tmp3;
	node_t* tmp4;
	tmp4 = malloc(sizeof(node_t));
	tmp4->value = 45;
	tmp4->next = NULL;
	list_print(hi);
	printf("length of list is %d\n",list_length(hi));
	list_add_to_back(hi, 55);
	list_print(hi);
	printf("length of list is %d\n",list_length(hi));
	list_add_at_index(hi, 99, 1);
	printf("\n");
	list_print(hi);
	list_add_at_index(hi, 997, 5);
	list_print(hi);
	printf("\n");
	list_add_to_front(hi, 002);
	list_print(hi);
	list_remove_from_back(hi);
	printf("\n");
	printf("\n");
	list_remove_from_front(hi);
	list_print(hi);
	printf("\n");
	printf("\n");
	list_remove_at_index(hi, 2);
	list_remove_at_index(hi, 0);
	list_print(hi);
	printf("\n");
	printf("%s",list_is_in(hi, 35));
	printf("\n");
	printf("elem = %d", list_get_elem_at(hi, 2));
	printf("\n");
	printf("\n");
	list_add_to_back(hi, 55);
	printf("index = %d", list_get_index_of(hi, 55));
	printf("\n");
	list_print(hi);
	list_free(hi);
  return 0;
}
