#pragma once
#include <stdbool.h>

struct Stack;

//This function creates stack
struct Stack* createStack();

//This function get the top element from stack
char pop(struct Stack* stack);

//This function check the emptiness of stack
bool isEmpty(struct Stack* head);

//This function deletes stack
void deleteStack(struct Stack** stack);

//This function add the element at the top of stack
void push(struct Stack* stack, char element);