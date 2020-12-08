#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
	}

	struct List* list = createList();
	while (true) {
		char value[20] = {0};
		if (fscanf(file, "%s", &value) != EOF) {
			addValue(value, list);
		}
		else {
			break;
		}
	}
	struct List* newList = deleteRepeatingValues(list);
	printf("New list: ");
	printList(newList);
	return 0;
}