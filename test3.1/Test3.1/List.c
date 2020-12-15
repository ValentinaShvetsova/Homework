#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include <stdlib.h>

struct Node {
	int value;
	int count;
	struct Node* next;
};

struct List {
	struct Node* head;
	struct Node* tail;
};

struct List* createList() {
	struct List* newList = calloc(1, sizeof(struct List));
	return newList;
}

void addValue(int value, struct List* list) {
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		return;
	}
	newNode->value = value;
	struct Node* current = list->head;
	struct Node* previous = NULL;
	while (current != NULL && current->value < value) {
		previous = current;
		current = current->next;
	}
	if (current != NULL && current->value == value) {
		current->count += 1;
		free(newNode);
	}
	else if (previous == NULL) {
		newNode->next = list->head;
		newNode->count = 1;
		list->head = newNode;
		list->tail = list->head;
		list->tail->next = NULL;
	}
	else {
		current = newNode;
		newNode->count = 1;
		newNode->next = NULL;
		list->tail = newNode;
	}
}

void deleteValue(struct List* list, int value) {
	struct Node* current = list->head;
	struct Node* previous = NULL;
	while (current != NULL && current->value < value) {
		previous = current;
		current = current->next;
	}
	if (current == NULL) {
		return;
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

bool isEmpty(struct List* list) {
	return list->head == NULL;
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
		printf("%d %d\n", current->value, current->count);
		current = current->next;
	}
}