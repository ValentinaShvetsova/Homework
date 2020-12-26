#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Stack/Stack.h"

void performOperation(char operation, struct Stack *stack) {
	const int firstElement = pop(stack);
	const int secondElement = pop(stack);
	int result = 0;
	switch (operation) {
	case '+':
		result = firstElement + secondElement;
		break;
	case '-':
		result = secondElement - firstElement;
		break;
	case '*':
		result = firstElement * secondElement;
		break;
	case '/':
		result = secondElement / firstElement;
		break;
	}
	push(stack, result);
}

void getResult(struct Stack* stack, int *result) {
	*result = pop(stack);
}

bool calculateSolution(char postfixExpression[], int *result) {
	struct Stack* stack = createStack();
	const int length = strlen(postfixExpression);
	for (int i = 0; i < length; ++i) {
		if (postfixExpression[i] >= '0' && postfixExpression[i] < '9') {
			push(stack, postfixExpression[i] - '0');
		}
		else switch (postfixExpression[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
			if (!isEmpty(stack)) {
				int firstElement = top(stack);
				if (!(postfixExpression[i] == '/' && firstElement == 0)) {
					performOperation(postfixExpression[i], stack);
				}
				else {
					deleteStack(stack);
					return false;
				}
			}
			else {
				deleteStack(stack);
				return false;
			}
			break;
		}
	}
	bool resultExist = false;
	if (!isEmpty(stack)){
		*result = pop(stack);
		if (isEmpty(stack)) {
			resultExist = true;
		} else {
			deleteStack(stack);
			resultExist = false;
		}
	}
	return resultExist;
}

bool test() {
	char string1[] = "23+4";
	int result1 = 0;

	char string2[] = "5+1";
	int result2 = 0;

	char string3[] = "+65";
	int result3 = 0;

	char string4[] = "23+4-";
	int result4 = 0;

	if (calculateSolution(string1, &result1) || calculateSolution(string2, &result2) || calculateSolution(string3, &result3)) {
		return false;
	}
	if (!calculateSolution(string4, &result4) || (result4 != 1)) {
		return false;
	}
	return true;
}

int main() {
	if (!test()) {
		printf("Tests ain't passed\n");
		return 1;
	}
	printf("Enter postfix expression: ");
	char string[100];
	scanf("%s", string);
	int result = 0;
	if (!calculateSolution(string, &result)) {
		printf("The expression can not be resolved\n");
	}
	else {
		printf("Answer: %d\n", result);
	}
	return 0;
}