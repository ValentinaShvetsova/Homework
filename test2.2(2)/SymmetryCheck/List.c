#include <stdio.h>
#include <stdbool.h>
#include "List.h"

struct Node
{
	int value;
	struct Node* next;
};

struct List
{
	struct Node* head;
	struct Node* tail;
	int length;
};

struct List* createList()
{
	struct List* newList = calloc(1, sizeof(struct List));
	return newList;
}

int listLength(struct List* list)
{
	return list->length;
}

bool isEmpty(struct List* list)
{
	return list->head == NULL;
}

void addValue(struct List* list, int value)
{
	list->length++;
	struct Node* newNode = calloc(1, sizeof(struct Node));
	newNode->value = value;
	newNode->next = NULL;
	if (!isEmpty(list))
	{
		list->tail->next = newNode;
		list->tail = list->tail->next;
		return;
	}
	list->head = newNode;
	list->tail = list->head;
}

int returnValue(struct List* list, int positionNumber)
{
	struct Node* current = list->head;
	for (int i = 0; i < positionNumber; ++i)
	{
		current = current->next;
	}
	if (current != NULL) {
		return current->value;
	}
	return 0;
}

bool compareLists(struct List* list1, struct List* list2)
{
	if (list1->length != list2->length)
	{
		return false;
	}
	struct Node* current1 = list1->head;
	struct Node* current2 = list2->head;
	while (current1 != NULL)
	{
		if (current1->value != current2->value)
		{
			return false;
		}
		current1 = current1->next;
		current2 = current2->next;
	}
	return true;
}

void deleteList(struct List* list)
{
	while (!isEmpty(list))
	{
		struct Node* temp = list->head->next;
		free(list->head);
		list->head = temp;
	}
	free(list);
}

struct List* reverse(struct List* list)
{
	struct List* reverseList = createList();
	const int length = listLength(list);
	for (int i = length - 1; i >= 0; --i)
	{
		const int value = returnValue(list, i);
		addValue(reverseList, value);
	}
	return reverseList;
}

bool isSymmetric(struct List* list)
{
	struct List* reverseList = reverse(list);
	const bool isSymmetric = compareLists(list, reverseList);
	deleteList(reverseList);
	return isSymmetric;
}