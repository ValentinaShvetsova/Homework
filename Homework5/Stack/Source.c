#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
	struct StackElement* head;
};

struct StackElement {
	char element;
	struct StackElement* next;
};

struct Stack* createStack() {
	struct Stack* newStack = calloc(1, sizeof(struct Stack));
	return newStack;
}

void push(struct Stack* stack, char element) {
	struct StackElement* newElement = malloc(sizeof(struct StackElement));
	if (newElement == NULL) {
		return;
	}
	newElement->element = element;
	newElement->next = stack->head;
	stack->head = newElement;
}

char pop(struct Stack* stack) {
	if (stack->head == NULL) {
		return 0;
	}
	char element = stack->head->element;
	struct StackElement* oldElement = stack->head;
	stack->head = stack->head->next;
	free(oldElement);
	return element;
}

bool isEmpty(struct Stack* stack) {
	return stack->head == NULL;
}

void deleteStack(struct Stack** head) {
	while (*head != NULL) {
		pop(head);
	}
}