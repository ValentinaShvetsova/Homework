#include <stdio.h>
#include "Stack.h"
#include <stdbool.h>

bool arePushAndPopWorking() {
	struct Stack* stack = createStack();
	push(stack, 3);
	if (pop(stack) != 3) {
		deleteStack(&stack);
		return false;
	}
	deleteStack(&stack);
	return true;
}

bool areAllFunctionWorking() {
	struct Stack* stack = createStack();
	push(stack, 3);
	push(stack, 5);
	push(stack, 7);
	if (pop(stack) != 7) {
		deleteStack(&stack);
		return false;
	}
	deleteStack(&stack);
	return true;
}

bool isDeleteWorking() {
	struct Stack* stack = createStack();
	deleteStack(&stack);
	return isEmpty(stack);
}

int main() {
	if (!test1() || !test2() || !test3()) {
		printf("Tests failed.\n");
		return 1;
	}
	return 0;
}