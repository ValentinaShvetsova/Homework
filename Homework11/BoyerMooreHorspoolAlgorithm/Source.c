#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

int searchingSubstring(char* string, char* substring) {
	int offsetTable[256] = { 0 };
	const int stringLength = strlen(string);
	const int substringLength = strlen(substring);
	for (int i = 0; i < 256; ++i) {
		offsetTable[i] = strlen(substring);
	}
	for (int i = substringLength - 2; i >= 0; i--) {
		if (offsetTable[substring[i]] == substringLength) {
			offsetTable[substring[i]] =substringLength - i - 1;
		}
	}
	for (int stringPosition = 0; stringPosition <= stringLength - substringLength; ++stringPosition) {
		int substringPosition = substringLength - 1;
		while (substring[substringPosition] == string[substringPosition + stringPosition]) {
			if (substringPosition == 0) {
				return stringPosition;
			}
			substringPosition--;
		}
		if (substringPosition != substringLength - 1) {
			stringPosition += offsetTable[substring[substringLength - 1]] - 1;
		}
		else {
			stringPosition += offsetTable[string[substringPosition + stringPosition]] - 1;
		}
	}
	return -1;
}

int main() {
	char string[] = {0};
	char substring[] = {0};
	FILE* file = fopen("input.txt", "r");
	if (!file) {
		printf("File reading error\n");
		return 1;
	}
	fscanf(file, "%s", &string);
	fclose(file);
	printf("Input substring: ");
	scanf("%s", &substring);
	const int result = searchingSubstring(string, substring);
	if (result == -1) {
		printf("String does not contain such substring\n");
	}
	else {
		printf("The first substring's enetry is at %d\n", result);
	}
	return 0;
}