#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"

struct Entry
{
	char name[20];
	char phone[20];
	struct Entry* next;
};

struct List {
	int length;
	struct Entry* head;
	struct Entry* tail;
};

struct List* createList() {
	struct List* newList = calloc(1, sizeof(struct List));
	return newList;
}

bool isEmpty(struct List* list)
{
	return list->head == NULL;
}

void addEntry(struct List* list, char name[], char phone[]) {
	list->length++;
	struct Entry* newEntry = malloc(sizeof(struct Entry));
	if (newEntry == NULL) {
		return;
	}
	if (isEmpty(list))
	{
		list->head = newEntry;
		list->tail = list->head;
		return;
	}
	list->tail->next = newEntry;
	list->tail = list->tail->next;
}

void printList(struct List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	struct Entry* current = list->head;
	while (current != NULL)
	{
		printf("%s - %s\n", current->name, current->phone);
		current = current->next;
	}
}

void deleteList(struct List* list) {
	while (!isEmpty(list)) {
		struct Entry* temp = list->head->next;
		free(list->head->name);
		free(list->head->phone);
		free(list->head);
		list->head = temp;
	}
}

void deleteHead(struct List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	list->length--;
	struct Entry* temp = list->head->next;
	free(list->head->name);
	free(list->head->phone);
	free(list->head);
	list->head = temp;
}

char* returnNameFromHead(struct List* list)
{
	return list->head->name;
}

char* returnPhoneFromHead(struct List* list)
{
	return list->head->phone;
}

int listLength(struct List* list)
{
	return list->length;
}