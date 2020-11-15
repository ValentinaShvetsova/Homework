#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

void commandVariation() {
	printf("Choose the command:\n");
	printf("0)Exit\n");
	printf("1)Add value in list\n");
	printf("2)Delete value from list\n");
	printf(" 3)Print list:\n");
}

bool tests() {
	struct List* list = createList();
	addValue(10, list);
	if (isEmpty(list)) {
		return false;
	}
	deleteValue(list, 10);
	if (!isEmpty(list)) {
		return false;
	}
	deleteList(list);
	return true;
}

int main() {
	if (!tests()) {
		return 1;
	}
	struct List* list = createList();
	bool shouldGoOut = false;
	while (!shouldGoOut) {
		commandVariation();
		int command = 0;
		scanf("%d", &command);
		switch (command) {
		case 0:
			shouldGoOut = true;
			break;
		case 1: {
			printf("Enter value: ");
			int value = 0;
			scanf("%d", &value);
			addValue(value, list);
			break;
		}
		case 2: {
			printf("Enter value to delete: ");
			int value = 0;
			scanf("%d", &value);
			deleteValue(list, value);
			break;
		}
		case 3: {
			printList(list);
			break;
		}
		default: {
			printf("Invalid input, try again\n");
			break;
		}
		}
	}
	deleteList(list);
	return 0;
}