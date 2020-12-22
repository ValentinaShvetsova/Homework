#include <stdio.h>
#include "list.h"
#include <stdbool.h>
#include <stdlib.h>

bool test1() {
	struct List* list = createList();
	addValue(list, 15);
	addValue(list, 78);
	addValue(list, 78);
	addValue(list, 15);
	const bool testPassed = isSymmetric(list);
	deleteList(list);
	return testPassed;
}

bool test2() {
	struct List* list = createList();
	addValue(list, 6);
	addValue(list, 7);
	addValue(list, 8);
	addValue(list, 7);
	addValue(list, 6);
	const bool testPassed = isSymmetric(list);
	deleteList(list);
	return testPassed;
}

bool test3() {
	struct List* list = createList();
	addValue(list, 1);
	addValue(list, 2);
	addValue(list, 3);
	addValue(list, 4);
	addValue(list, 2);
	addValue(list, 1);
	const bool testPassed = !isSymmetric(list);
	deleteList(list);
	return testPassed;
}

bool tests() {
	return test1() && test2() && test3();
}

int main() {
	if (!tests()) {
		return -1;
	}

	FILE* file = fopen("input.txt", "r");
	if (!file) {
		printf("File not found\n");
		return 1;
	}

	struct List* list = createList();
	while (true) {
		int number = 0;
		if (fscanf(file, "%d", &number) != EOF) {
			addValue(list, number);
		}
		else {
			break;
		}
	}
	fclose(file);

	if (listLength(list) == 0) {
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