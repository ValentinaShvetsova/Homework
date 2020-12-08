#pragma once
#include <stdbool.h>

struct List;

// This function creates list
struct List* createList();

// This function checks whether the list empty or not
bool isEmpty(struct List* list);

// This function adds value in list
void addValue(struct List* list, int value);

// This function deletes value from list and move head of list to the next from deleted element
void deleteValue(struct List* list, int positionNumber);

// This function checks whether the stack consist of 1 element or not
bool headIsTail(struct List* list);

// This function returnes head value
int headValue(struct List* list);

// This function deletes list
void deleteList(struct List* list);