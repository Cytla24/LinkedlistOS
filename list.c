// list/list.c
//
// Implementation for linked list.
//
// Aimie Ojuba

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() {
	list_t* newList = malloc(sizeof(list_t));

//	check if there was enough memory
	if (newList == NULL){
		printf("Malloc failed for head allocation\n");
		return NULL;
	}
	newList->head = NULL;
//   printf("%d",newList);
	return newList;
}

void list_free(list_t *l) {
  if (l->head == NULL){
	  return;
  }
  node_t* currNode = l->head;
  node_t* temp;
//  printf("value, %d", currNode->value);

  while(currNode != NULL){
//    printf("value, %d", currNode->value);
    temp = currNode;
    currNode = currNode->next;
	free(temp);
  }
   l->head = NULL;
   free(l);
}

void list_print(list_t *l) {
	printf("Printing linked list in order...\n");
	if (l->head == NULL){
		return;
	}
	node_t* curr = l->head;
	while (curr != NULL){
		printf("Value: %d \n", curr->value);
		curr = curr->next;
	}
	printf("Done printing.\n");
	return;
}

int list_length(list_t *l) {
	if (l->head == NULL){
		return 0;
	}
	int count = 0;
	node_t* curr = l->head;
	while (curr != NULL){
//		printf("Value: %d ,count %d \n", curr->value, count);
		curr = curr->next;
		count++;
	}
//	printf("%d",count);
	return count;
}

void list_add_to_back(list_t *l, elem value) {
	printf("adding node %d to back\n", value);
	node_t* tmp = malloc(sizeof(node_t));
	tmp->value = value;
	tmp->next = NULL;
	if (l->head == NULL){
		l->head = tmp;
		return;
	}
	node_t* curr = l->head;
	while (curr->next != NULL){
		curr = curr->next;
	}
	curr->next = tmp;
	return;
}

void list_add_to_front(list_t *l, elem value) {
	printf("adding node %d to front\n", value);
	node_t* tmp = malloc(sizeof(node_t));
	tmp->value = value;
	if (l->head == NULL){
		l->head = tmp;
		tmp->next = NULL;
		return;
	}
	tmp->next = l->head;
	l->head = tmp;
}

void list_add_at_index(list_t *l, elem value, int index) {
	printf("adding node %d at position index\n", value);
	node_t* tmp = malloc(sizeof(node_t));
	tmp->value = value;
	tmp->next = NULL;
	if (l->head == NULL){
		l->head = tmp;
		return;
	}
	int count = 0;
	node_t* curr = l->head;
	while (curr->next != NULL && count < index){
		curr = curr->next;
		count++;
	}
	if (curr->next == NULL){
		curr->next = tmp;
		return;
	}
	tmp->next = curr->next;
	curr->next = tmp;
	return;
}

elem list_remove_from_back(list_t *l) {
	printf("removing last element\n");
	node_t* curr = l->head;
	while (curr->next->next != NULL){
		curr = curr->next;
	}
	int count = curr->next->value;
//	printf("count: %d", count);
	node_t* after = curr->next;
	curr->next = NULL;
	after = NULL;
	free(after);
	return count;
}

elem list_remove_from_front(list_t *l) {
	printf("removing front element\n");
	node_t* curr = l->head;
	l->head = curr->next;
	int ele = curr->value;
	curr = NULL;
	free(curr);
	return ele;
}

elem list_remove_at_index(list_t *l, int index) {
	printf("removing element at index %d\n", index);
	if (l->head == NULL){
		return -1;
	}
	if (index == 0){
		return list_remove_from_front(l);
	}
	node_t* curr = l->head;
	int count = 0;
	while (curr->next != NULL && count < index - 1){
		curr = curr->next;
		count++;
	}
	if (curr->next == NULL){
		printf("index invalid\n");
		return -1;
	}
	node_t* temp = curr->next;
	curr->next = curr->next->next;
	int val = temp->value;
	temp = NULL;
	free(temp);
	return val;
}

bool list_is_in(list_t *l, elem value) {
	printf("checking if element %d is in the list\n", value);
	if (l->head == NULL){
		return -1;
	}
	node_t* curr = l->head;
	while (curr->next->next != NULL){
		if (curr->value == value){
			return true;
		}
		curr = curr->next;
	}
	return false;
}

elem list_get_elem_at(list_t *l, int index) {
	printf("getting element at index %d\n", index);
	if (l->head == NULL){
		return -1;
	}
	node_t* curr = l->head;
	int count = 0;
	while (curr != NULL && count < index){
		curr = curr->next;
		count++;
	}
	if (curr == NULL){
		printf("index invalid\n");
		return -1;
	}
	return curr->value;
}

int list_get_index_of(list_t *l, elem value) {
	printf("getting index of element %d\n", value);
	if (l->head == NULL){
		return -1;
	}
	node_t* curr = l->head;
	int count = 0;
	while (curr != NULL && curr->value != value){
		curr = curr->next;
		count++;
	}
	if (curr == NULL){
		printf("index invalid\n");
		return -1;
	}
	return count;
}
