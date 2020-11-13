#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tree.h"

int main() {
	FILE* file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found");
		return 1;
	}
	char prefix[1000] = { 0 };
	fgets(prefix, 1000, file);
	fclose(file);

	struct Tree* tree = build(prefix);
	printf("Result: %d\n", calculate(tree));

	deleteTree(tree);
	return 0;
}