#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "SortedList.h"

int main() {
	FILE* file = fopen("Test.txt", "r");
	if (!file) {
		printf("File not found\n");
		return 1;
	}

	struct List* list = createList();

	while (true) {
		char value[] = { 0 };
		if (fscanf(file, "%s", &value) != EOF) {
			addValue(value, list);
		}
		else {
			break;
		}
	}
	fclose(file);

	printListInNewFile(list);
	deleteList(list);
	return 0;
}