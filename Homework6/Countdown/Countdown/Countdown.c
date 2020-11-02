#include <stdio.h>
#include <stdlib.h>
#include "CircleList.h"
#include <string.h>


int survivorPosition(int numberOfWarriors, int killingPeriodicity) {
	struct List* list = createList();
	for (int i = 1; i <= numberOfWarriors; ++i)
	{
		addValue(list, i);
	}
	while (!(headIsTail(list))) {
		deleteValue(list, killingPeriodicity);
	}
	const int survivedWarrior = headValue(list);
	deleteList(list);
	return survivedWarrior;
}

int main() {
	printf("Enter the number of warriors: ");
	int numberOfWarriors = 0;
	scanf("%d", &numberOfWarriors);

	printf("Enter killing periodicity: ");
	int periodicity = 0;
	scanf("%d", &periodicity);

	const int survivedWarrior = survivorPosition(numberOfWarriors, periodicity);
	printf("Position number of survived warrior: %d\n", survivedWarrior);
	return 0;
}