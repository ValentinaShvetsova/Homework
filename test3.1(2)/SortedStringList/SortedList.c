#include <stdio.h>
#include <stdbool.h>
#include "SortedList.h"
#include <stdlib.h>
#include <string.h>

struct Node {
	char* value;
	struct Node* next;
};

struct List {
	struct Node* head;
};

struct List* createList() {
	struct List* newList = calloc(1, sizeof(struct List));
	return newList;
}

void addValue(char* value, struct List* list) {
	struct Node* newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		return;
	}
	newNode->value = calloc(1, sizeof(char));
	char* newValue = calloc(1, sizeof(char*));
	strcpy(newValue, value);
	newNode->value = newValue;
	struct Node* current = list->head;
	struct Node* previous = NULL;
	while (current != NULL && strcmp(current->value, value) < 0) {
		previous = current;
		current = current->next;
	}
	if (current == NULL && previous == NULL) {
		list->head = newNode;
		newNode->next = NULL;
		return;
	} else if (current == NULL) {
		previous->next = newNode;
		newNode->next = current;
		return;
	}
	if (strcmp(current->value, value) == 0) {
		free(newNode->value);
		free(newNode);
		return;
	}
	if (previous == NULL) {
		newNode->next = list->head;
		list->head = newNode;
	}
	else {
		previous->next = newNode;
		newNode->next = current;
	}
}

void deleteValue(struct List* list, char* value) {
	struct Node* current = list->head;
	struct Node* previous = NULL;
	while (current != NULL && strcmp(current->value, value) < 0) {
		previous = current;
		current = current->next;
	}
	if (current == NULL) {
		return;
	}
	if (strcmp(current->value, value) != 0) {
		return;
	}
	struct Node* temp = current->next;
	free(current->value);
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
		printf("%d ", current->value);
		current = current->next;
	}
}

void printListInNewFile(struct List* list) {
	FILE* file = fopen("newFile.txt", "w");
	if (!file) {
		printf("Error\n");
		return 1;
	}
	struct Node* current = list->head;
	while (current != NULL) {
		fprintf(file, "%s ", current->value);
		current = current->next;
	}
}