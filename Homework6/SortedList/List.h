#pragma once

struct List;

struct List* createList();

//This function add node in the list
void addValue(int value, struct List* list);

//This function delete node of list
void deleteValue(struct List* list, int value);

//This function check if the list is empty
bool isEmpty(struct List* list);

//This function delete list
void deleteList(struct List* list);

//This function print list
void printList(struct List* list);
