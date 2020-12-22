#pragma once
#include <stdbool.h>

// This structure consists of elments and pointers on next element
struct List;

// This function returns pointerf on a new list
struct List* createList();

// This function returnes list length
int listLength(struct List* list);

// This structure adds value in list
void addValue(struct List* list, int value);

// this function returns value in actual position 
int returnValue(struct List* list, int positionNumber);

// This function compares lists
bool compareLists(struct List* list1, struct List* list2);

// This function dletes lists
void deleteList(struct List* list);

// This funtion check whether the list is symmetric or not
bool isSymmetric(struct List* list);
