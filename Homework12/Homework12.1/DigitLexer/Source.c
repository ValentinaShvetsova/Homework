#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Lexer.h"

int main() {
	FILE* file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
	}
	char number[50] = { 0 };
	fscanf(file, "%s", number);
	fclose(file);

	if (lexer(number)) {
		printf("The number is real\n");
	}
	else {
		printf("The number isn't real\n");
	}
	return 0;
}