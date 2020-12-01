#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Tree.h"
#define SIZE 101

void printOptions() {
	printf("Choose the command:\n");
	printf("0) Exit\n");
	printf("1)Add value by key\n");
	printf("2)Get value by key\n");
	printf("3)Check whether the key is in the dictionary or not\n");
	printf("4)Delete key and value\n");
}
bool tests() {
	struct Tree* tree = createTree();
	char value[5] = "abcd";

	addValue(10, value, tree);
	addValue(7, value, tree);
	addValue(12, value, tree);

	if (!contains(tree, 10) || !contains(tree, 7) || !contains(tree, 12)) {
		deleteTree(tree);
		return false;
	}
	
	if (strcmp(getValue(tree, 7), value) != 0) {
		deleteTree(tree);
		return false;
	}

	deleteValue(tree, 12);
	if (contains(tree, 12)) {
		deleteTree(tree);
		return false;
	}
	deleteTree(tree);
	return true;
}

int main() {
	if (!tests()) {
		printf("Tests didn't pass\n");
		return 1;
	}

	int command = 0;
	bool shouldGoOut = false;
	struct Tree* tree = createTree();

	while (!shouldGoOut) {
		printOptions();
		scanf("%d", &command);
		int key = 0;
		switch (command) {
		case 0:
			shouldGoOut = true;
			break;
		case 1: {
			char value[100] = { 0 };

			printf("Enter the key: ");
			scanf("%d", &key);

			printf("Enter value: ");
			scanf("%s", &value);

			addValue(key, value, tree);
			break;
		}
		case 2: {
			printf("Enter the key: ");
			scanf("%d", &key);

			char* result = getValue(tree, key);
			if (result == NULL) {
				printf("Value for this key wasn't found\n");
			}
			else {
				printf("%s\n", result);
			}
			break;
		}
		case 3: {
			printf("Enter the key: ");
			scanf("%d", &key);

			if (contains(tree, key)) {
				printf("The key is in the dictionary\n");
			}
			else {
				printf("The key is not in the dictionary\n");
			}
			break;
		}
		case 4: {
			printf("Enter key: ");
			scanf("%d", &key);

			deleteValue(tree, key);
			break;
		}
		default:
			printf("Invalid input, try again\n");
			break;
		}
	}
	deleteTree(tree);
	return 0;
}