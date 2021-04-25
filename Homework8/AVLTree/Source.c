#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "AVLTree.h"

bool functionsWorking() {
	struct Tree* tree = createTree();

	addValue(tree, "11", "right");
	addValue(tree, "12", "root");
	addValue(tree, "13", "left");

	if (strcmp(getValue(tree, "12"), "root") != 0) {
		deleteTree(tree);
		return false;
	}
	if (!contains(tree, "13") || !contains(tree, "12") || !contains(tree, "11")) {
		deleteTree(tree);
		return false;
	}
	if (strcmp(getRootValue(tree), "12") != 0) {
		deleteTree(tree);
		return false;
	}
	deleteValue(tree, "13");
	if (contains(tree, "13")) {
		deleteTree(tree);
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
