#pragma once

// This structure points on next and previous element, has value of its own element
struct List;

// This function creates list
struct List* createList();

// This function adds node in the list
void addValue(char* value, struct List* list);

// This function deletes node of list
void deleteValue(struct List* list, char* value);

// This function checks if the list is empty
bool isEmpty(struct List* list);

// This function deletes list
void deleteList(struct List* list);

// This function prints list
void printList(struct List* list);

// This function creates a new file and prints list in there
void printListInNewFile(struct List* list);