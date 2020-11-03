#pragma once

struct List;

struct List* createList();

//This function check whether the list empty or not
bool isEmpty(struct List* list);

//this function add entry in list
void addEntry(struct List* list, char name[], char phone[]);

//This function print list
void printList(struct List* list);

//This function delete list
void deleteList(struct List* list);

//This function delete head of list
void deleteHead(struct List* list);

//This function gets the name from head of list
char* returnNameFromHead(struct List* list);

//This function gets the phone from head of list
char* returnPhoneFromHead(struct List* list);

//This function gets the length of list
int listLength(struct List* list);
