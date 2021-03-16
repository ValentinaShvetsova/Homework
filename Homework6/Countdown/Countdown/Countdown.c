#include <stdio.h>
#include <stdlib.h>
#include "CircleList.h"
#include <string.h>

int survivorPosition(int numberOfWarriors, int killingPeriodicity) {
	struct List* list = createList();
	for (int i = 1; i <= numberOfWarriors; ++i) {
		addValue(list, i);
	}
	while (!(headIsTail(list))) {
		deleteValue(list, killingPeriodicity);
	}
	const int survivedWarrior = headValue(list);
	deleteList(list);
	return survivedWarrior;
}

bool tests() {
	return survivorPosition(3, 5) == 1 && survivorPosition(10, 2) == 5 && survivorPosition(10, 5) == 3;
}

int main() {
	if (!tests()) {
		printf("Tests failed\n");
		return 1;
	}
	printf("Enter the number of warriors: ");
	int numberOfWarriors = 0;
	scanf("%d", &numberOfWarriors);

	printf("Enter killing periodicity: ");
	int periodicity = 0;
	scanf("%d", &periodicity);

	const int survivedWarrior = survivorPosition(numberOfWarriors, periodicity);
	printf("Position of survived warrior: %d\n", survivedWarrior);
	return 0;
}