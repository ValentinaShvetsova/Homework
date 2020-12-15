#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "List.h"

void printCommands() {
	printf("Choose the command:\n");
	printf("0)Exit\n");
	printf("1)Add value in list\n");
	printf("2)Print list:\n");
}

int main() {
	struct List* list = createList();
	int number = -1;
	while (number != 0) {
		scanf("%d\n", &number);
		if (number != 0) {
			addValue(number, list);
		}
	}
	printList(list);
	deleteList(list);
	return 0;
}
