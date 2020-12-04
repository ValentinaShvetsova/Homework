#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

int searchingSubstring(char* string, char* substring) {
	int offsetTable[256] = { 0 };
	for (int i = 0; i < 256; ++i) {
		offsetTable[i] = strlen(substring);
	}
	for (int i = strlen(substring)-2; i >= 0; i--) {
		if (offsetTable[substring[i]] == strlen(substring)) {
			offsetTable[substring[i]] = strlen(substring) - i - 1;
		}
	}
	for (int stringPosition = 0; stringPosition <= strlen(string) - strlen(substring); ++stringPosition) {
		int substringPosition = strlen(substring) - 1;
		while (substring[substringPosition] == string[substringPosition + stringPosition]) {
			if (substringPosition == 0) {
				return stringPosition;
			}
			substringPosition--;
		}
		if (substringPosition != strlen(substring) - 1) {
			stringPosition += offsetTable[substring[strlen(substring) - 1]] - 1;
		}
		else {
			stringPosition += offsetTable[string[substringPosition + stringPosition]] - 1;
		}
	}
	return -1;
}
int main() {
	char string[] = "Hellofriends";
	char substring[] = "end";
	int result = searchingSubstring(string, substring);
	if (result == -1) {
		printf("String do not consist such substring\n");
	}
	else {
		printf("The first substring's enetering is at %d\n", result);
	}
	return 0;
}