#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include <stdlib.h>

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
	newList->head = NULL;
	return newList;
}

bool addNewValueToList(struct List* list, char* value, int amount) {
	struct Node* current = list->head;
	struct Node* previous = NULL;
	while (current != NULL && strcmp(current->word, value) != 0) {
		previous = current;
		current = current->next;
	}
	if (current == NULL) {
		list->length++;
		char* newValue = calloc(1, sizeof(char*));
		struct Node* newNode = malloc(sizeof(struct Node));
		strcpy(newValue, value);
		if (previous == NULL) {
			list->head = newNode;
		} else {
			previous->next = newNode;
		}
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

int listLength(struct List* list)
{
	return list->length;
}