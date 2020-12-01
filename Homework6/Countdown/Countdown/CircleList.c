#include <stdlib.h>
#include <stdbool.h>
#include "CircleList.h"

struct Node
{
	int value;
	struct Node* next;
};

struct List
{
	struct Node* head;
	struct Node* tail;
};

struct List* createList() {
	struct List* newList = calloc(1, sizeof(struct List));
	return newList;
}

bool isEmpty(struct List* list) {
	return list->head == NULL;
}

void addValue(struct List* list, int value) {
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		return;
	}
	newNode->value = value;
	if (isEmpty(list)) {
		list->head = newNode;
		list->head->next = list->head;
		list->tail = list->head;
	}
	else {
		list->tail->next = newNode;
		list->tail = list->tail->next;
		list->tail->next = list->head;
	}
}

void deleteValue(struct List* list, int positionNumber)
{
	struct Node* current = list->head;
	struct Node* previous = list->tail;
	for (int i = 1; i < positionNumber; ++i) {
		previous = current;
		current = current->next;
	}
	if (current->next == NULL) {
		free(current->value);
		free(current);
		return;
	}
	struct Node* oldElement = current;
	list->head = current->next;
	list->tail = previous;
	previous->next = current->next;
	free(oldElement->value);
	free(oldElement);
}

bool headIsTail(struct List* list) {
	return list->head == list->tail;
}

int headValue(struct List* list) {
	if (list->head->value != NULL) {
		return list->head->value;
	}
	return NULL;
}