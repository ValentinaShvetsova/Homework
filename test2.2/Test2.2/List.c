#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include <stdlib.h>
#include <string.h>

struct Node {
	char* value;
	struct Node* next;
};

struct List {
	struct Node* head;
	struct Node* tail;
};

struct List* createList() {
	struct List* newList = calloc(1, sizeof(struct List));
	newList->head = NULL;
	return newList;
}

void addValue(char* value, struct List* list) {
	char* newValue = calloc(20, (sizeof(char*)));
	if (newValue == NULL) {
		return;
	}
	strcpy(newValue, value);
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		return;
	}
	newNode->value = newValue;
	if (!isEmpty(list)) {
		list->tail->next = newNode;
		list->tail = list->tail->next;
		newNode->next = NULL;
		return;
	}
	list->head = newNode;
	list->tail = list->head;
	list->head->next = NULL;
}

bool isEmpty(struct List* list) {
	return list->head == NULL;
}

void deleteValue(struct List* list, char* value) {
	struct Node* current = list->head;
	struct Node* previous = NULL;
	while (current != NULL && strcmp(current->value, value) != 0) {
		previous = current;
		current = current->next;
	}
	if (strcmp(current->value, value) != 0) {
		return;
	}
	struct Node* temp = current->next;
	free(current);
	if (previous == NULL) {
		list->head = temp;
	}
	else {
		previous->next = temp;
	}
}

void deleteList(struct List* list) {
	while (!isEmpty(list)) {
		struct Node* temp = list->head->next;
		deleteValue(list, list->head->value);
		list->head = temp;
	}
}

void printList(struct List* list) {
	struct Node* current = list->head;
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
}

int returnValue(struct List* list, int positionNumber)
{
	struct Node* current = list->head;
	for (int i = 1; i < positionNumber; ++i) {
		current = current->next;
	}
	return current->value;
}

struct List* deleteRepeatingValues(struct List* list) {
	struct List* listWithoutRepeats = createList();
	struct Node* current = list->head;
	struct Node* previous = NULL;
	
	while (current != NULL) {
		struct Node* current1 = listWithoutRepeats->head;
		struct Node* previous1 = NULL;
		while (current1 != NULL && strcmp(current->value, current1->value) != 0) {
			previous1 = current1;
			current1 = current1->next;
		}
		if (current1 == NULL) {
			addValue(current->value, listWithoutRepeats);
		}
		previous = current;
		current = current->next;
	}
	return listWithoutRepeats;
}