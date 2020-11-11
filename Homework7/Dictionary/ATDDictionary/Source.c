#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Tree.h"

int main() {
	int command = 0;
	bool shouldGoOut = false;
	struct Tree* tree = createTree();

	while (!shouldGoOut) {
		printf("Choose the command:\n0) Exit\n1)Add value by key\n2)Get value by key\n");
		printf("3)Check whether the key is in the dictionary or not\n4)Delete key and value\n");
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
				printf("Value for this key wasn't find\n");
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