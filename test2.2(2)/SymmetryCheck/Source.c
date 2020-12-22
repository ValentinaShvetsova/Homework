#include <stdio.h>
#include "list.h"
#include <stdbool.h>
#include <stdlib.h>

int main() {
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
			addValue(list, number);
		}
		else
		{
			break;
		}
	}
	fclose(file);

	if (listLength(list) == 0)
	{
		printf("Zero list length\n");
		deleteList(list);
		return 1;
	}

	printf("The list is ");
	if (isSymmetric(list)) {
		printf("symmetric\n");
	}
	else {
		printf("asymmetric\n");
	}
	deleteList(list);
	return 0;
}