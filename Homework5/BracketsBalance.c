#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Stack/Stack.h"

bool chekBalance(char string[]) {
	struct Stack* stack = createStack();
	const int length = strlen(string);
	for (int i = 0; i < length; i++) {

		switch (string[i]) {
		case '(':
		case '{':
		case '[':
			push(stack, string[i]);
			break;

		case ')':
			if (isEmpty(stack))
			{
				deleteStack(&stack);
				return false;
			}
			else if (pop(stack) != '(')
			{
				deleteStack(&stack);
				return false;
			}
			break;

		case '}':
			if (isEmpty(stack))
			{
				deleteStack(&stack);
				return false;
			}
			else if (pop(stack) != '{')
			{
				deleteStack(&stack);
				return false;
			}
			break;

		case ']':
			if (isEmpty(stack))
			{
				deleteStack(&stack);
				return false;
			}
			else if (pop(stack) != '[')
			{
				deleteStack(&stack);
				return false;
			}
			break;

		}
	}
	const bool stringBalanced = isEmpty(stack);
	deleteStack(&stack);
	return stringBalanced;
}

int main() {
	printf("Enter the string: ");
	char string[100];
	scanf("%s", string);
	if (!chekBalance(string)) {
		printf("Not balanced\n");
	}
	else {
		printf("Balanced\n");
	}
	return 0;
}