#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

int main() {
	struct List* list = createList();
	bool shouldGoOut = false;
	while (!shouldGoOut) {
		printf("Choose the command:\n 0)Exit\n 1)Add value in list\n 2)Delete value from list\n 3)Print list\n");
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