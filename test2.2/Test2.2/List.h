#pragma once

// This structure consist pointers to next and previous element, its own element
struct List;

// This function create list
struct List* createList();

// This function add node in the list
void addValue(char* value, struct List* list);

// This function delete node of list
void deleteValue(struct List* list, char* value);

// This function check if the list is empty
bool isEmpty(struct List* list);

// This function delete list
void deleteList(struct List* list);

// This function print list
void printList(struct List* list);

// This function return value
int returnValue(struct List* list, int positionNumber);

// This function creates new list based on old list, but without repeats
struct List* deleteRepeatingValues(struct List* list);
