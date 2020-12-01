#pragma once

// This structure points on next and previous elements, has its own value
struct List;

// This structure creates List
struct List* createList();

// This function checks whether the list empty or not
bool isEmpty(struct List* list);

// This function adds entry in list
void addEntry(struct List* list, char name[], char phone[]);

// This function prints list
void printList(struct List* list);

// This function deletes list
void deleteList(struct List* list);

// This function deletes head of list
void deleteHead(struct List* list);

// This function gets the name from head of list
char* returnNameFromHead(struct List* list);

//This function gets the phone from head of list
char* returnPhoneFromHead(struct List* list);

// This function gets the length of list
int listLength(struct List* list);
