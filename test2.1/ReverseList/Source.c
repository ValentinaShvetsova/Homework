#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include <stdlib.h>

bool test() {
	struct List* list = createList();
	addValue(2, list);
	addValue(5, list);
	addValue(3, list);
	addValue(7, list);
	int tailValue = returnValue(list, 4);
	reverse(list);
	int headValue = returnValue(list, 1);
	return tailValue == headValue;
	deleteList(list);
}

int main() {
	if (!test()) {
		return 1;
	}
	FILE* file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
	}

	struct List* list = createList();
	while (true)
	{
		int number = 0;
		if (fscanf(file, "%d", &number) != EOF)
		{
			addValue(number, list);
		}
		else
		{
			break;
		}
	}
	reverse(list);
	printList(list);
	deleteList(list);
	return 0;
}