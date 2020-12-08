#pragma once
#include <stdbool.h>

// This structure puts element on head and take it from head
struct Stack;

//This function create stack
struct Stack* createStack();

//This function get the element from the top of the stack
char pop(struct Stack* stack);

//This function check whether the stack is empty or not
bool isEmpty(struct Stack* stack);

//This function delete stack
void deleteStack(struct Stack** stack);

//This function push new element at the top of the stack
void push(struct Stack* stack, char element);