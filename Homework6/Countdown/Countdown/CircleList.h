#pragma once
#include <stdbool.h>

struct List;

struct List* createList();

//This function check whether the list empty or not
bool isEmpty(struct List* list);

//This function add value in list
void addValue(struct List* list, int value);

//This function delete value from list
void deleteValue(struct List* list, int positionNumber);

//This function delete the whole list
void deleteList(struct List* list);

//This function check whether the stack consist of 1 element or not
bool headIsTail(struct List* list);

//This function return head value
int headValue(struct List* list);