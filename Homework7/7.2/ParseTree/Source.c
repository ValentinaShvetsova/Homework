#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tree.h"

bool tests() {
	char string1[] = "(*(+3 7)9)";
	char string2[] = "(/(+3 7)5)";
	int answer1 = 90;
	int answer2 = 2;

	struct Tree* tree1 = buildTree(string1);
	struct Tree* tree2 = buildTree(string2);

	int result1 = calculate(tree1);
	int result2 = calculate(tree2);

	deleteTree(tree1);
	deleteTree(tree2);

	return answer1 == result1 && answer2 == result2;
}

int main() {
	if (!tests()) {
		printf("Tests failed\n");
		return 1;
	}
	FILE* file = fopen("data.txt", "r");
	if (!file) {
		printf("File not found");
		return 1;
	}
	char prefix[1000] = { 0 };
	fgets(prefix, 1000, file);
	fclose(file);

	struct Tree* tree = buildTree(prefix);
	printf("Result: %d\n", calculate(tree));

	deleteTree(tree);
	return 0;
}