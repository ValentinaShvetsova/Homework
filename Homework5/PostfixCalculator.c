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

int getResult(struct Stack* stack) {
	int result = pop(stack);
	printf("%d ", result);
}

bool calculationPermission(char postfixExpression[]) {
	struct Stack* stack = createStack();
	const int length = strlen(postfixExpression);
	for (int i = 0; i < length; ++i) {

		if (postfixExpression[i] - '0' >= 0 && postfixExpression[i] - '0' < 10)
		{
			push(stack, postfixExpression[i] - '0');
		}
		else switch (postfixExpression[i])
		{
		case '+':
		case '-':
		case '*':
		case '/':
			if (!isEmpty(stack)) {
				int firstElement = pop(stack);
				if (!isEmpty(stack) && !(postfixExpression[i] == '/' && firstElement == 0)) {
					push(stack, firstElement);
					performOperation(postfixExpression[i], stack);
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
			break;
		}
	}
	bool resultExictence = false;
	if (!isEmpty(stack)){
		int result = pop(stack);
		if (isEmpty(stack)){
			resultExictence = true;
			push(stack, result);
			getResult(stack);
		} else {
			deleteStack(&stack);
		}
	}
	return resultExictence;
}
bool test() {
	char string1[] = "23+4";
	char string2[] = "5+";
	char string3[] = "+65";
	if (calculationPermission(string1) || calculationPermission(string2) || calculationPermission(string3)) {
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
	if (!calculationPermission(string)) {
		printf("The expression can not be resolved\n");
	}
	return 0;
}