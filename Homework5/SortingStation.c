#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Stack/Stack.h"

int priority(char operation)
{
	int priority = 0;
	switch (operation)
	{
	case '*':
	case '/':
		priority = 3;
		break;
	case '+':
	case '-':
		priority = 2;
		break;
	case '(':
		priority = 1;
		break;
	}
	return priority;
}

void convertToPostfix(char infixExpression[], char postfixExpression[]) {
	struct Stack* stack = createStack();
	int infixExpressionLength = strlen(infixExpression);
	int postfixPosition = 0;
	for (int i = 0; i < infixExpressionLength; i++) {
		if (infixExpression[i] >= '0' && infixExpression[i] <= '9') {
			postfixExpression[postfixPosition] = infixExpression[i];
			postfixPosition++;
		}
		else switch (infixExpression[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
		{
			bool shouldCheckPriority = true;
			while (shouldCheckPriority && !isEmpty(stack)) {
				char topOperation = pop(stack);
				if (priority(topOperation) >= priority(infixExpression[i])) {
					postfixExpression[postfixPosition] = topOperation;
					postfixPosition++;
				}
				else {
					push(stack, topOperation);
					shouldCheckPriority = false;
				}
			}
			push(stack, infixExpression[i]);
			break;
		}
		case '(':
			push(stack, infixExpression[i]);
			break;
		case ')': {
			char topOperation = pop(stack);
			while (topOperation != '(') {
				postfixExpression[postfixPosition] = topOperation;
				postfixPosition++;
				topOperation = pop(stack);
			}
			break;
		}
		}
	}
	while (!isEmpty(stack)) {
		char operation = pop(stack);
		postfixExpression[postfixPosition] = operation;
		postfixPosition++;
	}
	deleteStack(stack);
}
int main() {
	printf("Enter an infix expression: ");
	char inputString[100] = {0};
	scanf("%s", inputString);
	char outputString[100] = {0};
	convertToPostfix(inputString, outputString);
	printf("Result in infix Form: %s\n", outputString);
	return 0;
}