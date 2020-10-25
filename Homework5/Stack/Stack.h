#pragma once
#include <stdbool.h>

struct Stack;

struct Stack* createStack();

int pop(struct Stack* stack);

bool isEmpty(struct StackElement* head);

void deleteStack(struct Stack** stack);

void push(struct Stack* stack, int element);