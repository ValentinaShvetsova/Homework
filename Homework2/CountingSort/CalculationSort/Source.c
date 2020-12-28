#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>

void calculationSort(int size, int a[])
{    
	int max = 0;
	int min = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	
	int* helpingArray = calloc((max + 1), sizeof(int));

	for (int i = 0; i < size; ++i) {
		helpingArray[a[i] - min]++;
	}
	int i = 0;
	for (int j = 0; j < max - min + 1; j++) {
		while (helpingArray[j] != 0) {
			a[i] = j + min;
			helpingArray[j]--;
			i++;
		}
	}
	free(helpingArray);
}

bool sortCheck(int a[], int size) {
	for (int i = 0; i < size - 1; ++i) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}

int firstTest() {
	int a[1000];
	for (int i = 0; i < 1000; ++i) {
		a[i] = 1000 - i - 1;
	}

	calculationSort(1000, a);
	return sortCheck(a, 1000);
}

int secondTest() {
	int a[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = 10;
	}

	calculationSort(10, a);
	return sortCheck(a, 10);
}

int thirdTest() {
	int a[] = { 7, 8, 3, 4, 1, 2, 6, 5, 2 };

	calculationSort(9, a);
	return sortCheck(a, 9);
}

int fourthTest() {
	int a[] = { 1 };
	calculationSort(1, a);
	for (int i = 0; i < 1; ++i) {
		if (a[i] != 1) {
			return false;
		}
	}
	return true;
}

int main() {
	if (!firstTest() || !secondTest() || !thirdTest() || !fourthTest()) {
		printf("Test failed\n");
		return 0;
	}

	int size = 0;
	printf("Input size of array: ");
	scanf("%d", &size);

	int *mass = (int*)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++) {
		mass[i] = size - i - 1;
	}
	
	clock_t start = clock();
	calculationSort(size, mass);
	clock_t stop =  clock();
	int time = (stop - start) / CLK_TCK;
	printf("Time of working: %d\n", time);

	printf("Sorted array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", mass[i]);
	}
	free(mass);

	return 0;
}