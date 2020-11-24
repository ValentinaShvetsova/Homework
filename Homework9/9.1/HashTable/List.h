#pragma once

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

bool contains(struct List* list, char* value);

int quantityOfValuesFromHead(struct List* list);

char* returnValueFromHead(struct List* list);

void deleteValueFromHead(struct List* list, int value);