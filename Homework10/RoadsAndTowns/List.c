#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include <stdlib.h>

struct Node {
	int value;
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

void addValue(int value, struct List* list) {
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		return;
	}
	newNode->value = value;
	if (!isEmpty(list)) {
		list->tail->next = newNode;
		list->tail = list->tail->next;
		return;
	}
	list->head = newNode;
	list->tail = list->head;
}

bool isEmpty(struct List* list) {
	return list->head == NULL;
}

void deleteValue(struct List* list, int value) {
	struct Node* current = list->head;
	struct Node* previous = NULL;
	while (current != NULL && current->value != value) {
		previous = current;
		current = current->next;
	}
	if (current->value != value) {
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
	list->tail->next = NULL;
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->next;
	}
}

int returnValue(struct List* list, int positionNumber) {
	struct Node* current = list->head;
	for (int i = 1; i < positionNumber; ++i) {
		current = current->next;
	}
	return current->value;
}

bool compareLists(struct List* list1, struct List* list2) {
	struct Node* current1 = list1->head;
	struct Node* current2 = list2->head;
	while (current1 != NULL && current2 != NULL) {
		if (current1->value != current2->value) {
			return false;
		}
		current1 = current1->next;
		current2 = current2->next;
	}
	return current1 == NULL && current2 == NULL;
}