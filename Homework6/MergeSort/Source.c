#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "List.h"
#include "MergeSort.h"

int main() {
	const char* name = "Entries.txt";
	FILE* file = fopen(name, "r");
	if (!file) {
		printf("File can not be opened\n");
		return 1;
	}
	struct List* list = createList();
	while (!feof(file)) {
		char name[20] = { 0 };
		char phone[20] = { 0 };
		fscanf(file, "%s %s", name, phone);
		addEntry(list, name, phone);
	}
	fclose(file);
	printf("Choose the type of sorting:\n 1) sort by name\n 2) sort by phone\n");
	int input = 0;
	scanf("%d", &input);
	struct List* sortedList = mergeSort(list, input);
	printf("\nSorted entries:\n");
	printList(sortedList);

	deleteList(sortedList);
	deleteList(list);
	return 0;
}