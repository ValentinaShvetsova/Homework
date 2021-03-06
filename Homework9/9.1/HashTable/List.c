#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct Node {
	char* word;
	int counter;
	struct Node* next;
};

struct List {
	int length;
	struct Node* head;
	struct Node* tail;
};

struct List* createList() {
	struct List* newList = calloc(1, sizeof(struct List));
	return newList;
}

struct Node* initializeNode(char* value, int amount) {
	char* newValue = calloc(strlen(value) + 1, sizeof(char*));
	struct Node* newNode = calloc(1, sizeof(struct Node));
	newNode->counter = 1;
	strcpy(newValue, value);
	newNode->word = newValue;
	return newNode;
}

bool addNewValueToList(struct List* list, char* value, int amount) {
	struct Node* current = list->head;
	struct Node* previous = NULL;
	if (current == NULL) {
		list->length++;
		struct Node* newNode = initializeNode(value, amount);
		list->head = newNode;
		list->head->next = NULL;
		return true;
	}
	while (current != NULL && strcmp(current->word, value) != 0) {
		previous = current;
		current = current->next;
	}
	if (current == NULL) {
		list->length++;
		struct Node* newNode = initializeNode(value, amount);
		newNode->next = NULL;
		return true;
	}
	current->counter += amount;
	return false;
}

bool isEmpty(struct List* list) {
	return list->head == NULL;
}

bool contains(struct List* list, char* value) {
	struct Node* current = list->head;
	while (current != NULL) {
		if (strcmp(current->word, value) == 0) {
			return true;
		}
		current = current->next;
	}
	return false;
}

char* returnValueFromHead(struct List* list) {
	if (isEmpty(list)) {
		return NULL;
	}
	return list->head->word;
}

int quantityOfValuesFromHead(struct List* list) {
	return list->head->counter;
}

void deleteValueFromHead(struct List* list) {
	if (isEmpty(list)) {
		return;
	}
	list->length--;
	struct Node* headNode = list->head;
	list->head = list->head->next;
	free(headNode->word);
	free(headNode);
}

void deleteList(struct List* list) {
	while (!isEmpty(list)) {
		deleteValueFromHead(list);
	}
	free(list);
}

void printList(struct List* list) {
	struct Node* current = list->head;
	while (current != NULL) {
		printf("%s(%d) ", current->word, current->counter);
		current = current->next;
	}
}

int listLength(struct List* list) {
	return list->length;
}