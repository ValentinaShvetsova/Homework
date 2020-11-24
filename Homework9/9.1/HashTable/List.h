#pragma once
#include <stdbool.h>

// This structure consist pointers to next and previous element, its own element
struct List;

// This function create list
struct List* createList();

// This function add node in the list
bool addNewValueToList(struct List* list, char* value, int amount);

// This function check if the list is empty
bool isEmpty(struct List* list);

// This function delete list
void deleteList(struct List* list);

// This function print list
void printList(struct List* list);

// This function return value
char* returnValueFromHead(struct List* list);

// This function check whether value is in the list or not
bool contains(struct List* list, char* value);

// This function gets value from head
int quantityOfValuesFromHead(struct List* list);

// This function returns
char* returnValueFromHead(struct List* list);

// This function deletes head value
void deleteValueFromHead(struct List* list, int value);