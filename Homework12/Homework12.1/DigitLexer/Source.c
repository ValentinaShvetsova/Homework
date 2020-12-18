#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Lexer.h"

bool tests() {
	char string1[] = "11E1";
	char string2[] = "2.1E-02";
	char string3[] = "1E3";

	char string4[] = "12E2E2";
	char string5[] = "1-3";
	char string6[] = "-E5.";

	if (!lexer(string1) || !lexer(string2) || !lexer(string3) || lexer(string4) || lexer(string5) || lexer(string6)) {
		return false;
	}
	return true;
}

int main() {
	if (!tests()) {
		printf("Tests didn't pass\n");
		return 1;
	}
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