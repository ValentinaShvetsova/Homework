#pragma once

// This structure represents linked list with constant complexity operations of adding element and removing element
struct List;

// This function creates List
struct List* createList();

// This function checks whether the list empty or not
bool isEmpty(struct List* list);

// This function adds entry in list
void addEntry(struct List* list, const char name[], const char phone[]);

// This function prints list
void printList(struct List* list);

// This function deletes list
void deleteList(struct List* list);

// This function deletes head of list
void deleteHead(struct List* list);

// This function gets the name from head of list, no need to free memory after
char* returnNameFromHead(struct List* list);

// This function gets the phone from head of list, no need to free memory after
char* returnPhoneFromHead(struct List* list);

// This function gets the length of list
int listLength(struct List* list);
