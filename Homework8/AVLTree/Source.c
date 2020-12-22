#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "AVLTree.h"

bool functionsWorking() {
	struct Tree* tree = createTree();
	char key1[] = "11";
	char key2[] = "12";
	char key3[] = "13";
	char value1[] = "right";
	char value2[] = "root";
	char value3[] = "left";

	addValue(tree, key1, value1);
	addValue(tree, key2, value2);
	addValue(tree, key3, value3);

	if (strcmp(getValue(tree, 12), value2) != 0) {
		return false;
	}
	if (!contains(tree, key3) || !contains(tree, key2) || !contains(tree, key1)) {
		return false;
	}
	if (strcmp(getRootValue, value2) != 0) {
		return false;
	}
	deleteValue(tree, key3);
	if (contains(tree, key3)) {
		return false;
	}
	deleteTree(tree);
	return true;
}

int main() {
	if (!functionsWorking()) {
		return 1;
	}
	int command = 0;
	bool shouldGoOut = false;
	struct Tree* tree = createTree();

	while (!shouldGoOut) {
		printf("Choose the command:\n0) Exit\n1)Add value by key\n2)Get value by key\n");
		printf("3)Check whether the key is in the dictionary or not\n4)Delete key and value\n");
		scanf("%d", &command);
		char key[50] = { 0 };
		switch (command) {
		case 0:
			shouldGoOut = true;
			break;
		case 1: {
			char value[100] = { 0 };

			printf("Enter the key: ");
			scanf("%s", &key);

			printf("Enter value: ");
			scanf("%s", &value);

			addValue(tree, key, value);
			break;
		}
		case 2: {
			printf("Enter the key: ");
			scanf("%s", &key);

			char* result = getValue(tree, key);
			if (result == NULL) {
				printf("Value for this key wasn't found\n");
			}
			else {
				printf("%s", result);
			}
			break;
		}
		case 3: {
			printf("Enter the key: ");
			scanf("%s", &key);

			if (contains(tree, key)) {
				printf("The key is in the dictionary");
			}
			else {
				printf("The key is not in the dictionary");
			}
			break;
		}
		case 4: {
			printf("Enter the key: ");
			scanf("%s", &key);

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
