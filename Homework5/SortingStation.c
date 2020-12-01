#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Stack/Stack.h"

int priority(char operation) {
	int priority = 0;
	switch (operation) {
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
	if (!stack) {
		return;
	}
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
		case '/': {
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
		const char operation = pop(stack);
		postfixExpression[postfixPosition] = operation;
		postfixPosition++;
	}
	deleteStack(stack);
}

bool tests() {
	char testString1[] = "1*3-1+5*3";
	char result1[10] = { 0 };
	convertToPostfix(testString1, result1);
	if (strcmp(result1, "13*1-53*+") != 0) {
		return false;
	}

	char testString2[] = "(1+1)*2";
	char result2[10] = { 0 };
	convertToPostfix(testString2, result2);
	if (strcmp(result2, "11+2*") != 0) {
		return false;
	}

	char testString3[] = "(1+2)*3-1";
	char result3[10] = { 0 };
	convertToPostfix(testString3, result3);
	if (strcmp(result3, "12+3*1-") != 0) {
		return false;
	}
	return true;
}

int main() {
	if (!tests()) {
		printf("Tests failed\n");
		return 1;
	}
	printf("Enter an infix expression: ");
	char inputString[100] = {0};
	scanf("%s", inputString);
	char outputString[100] = {0};
	convertToPostfix(inputString, outputString);
	printf("Result in infix Form: %s\n", outputString);
	return 0;
}