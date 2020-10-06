#include <stdio.h>
#include <malloc.h>
#include <conio.h>
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
	
	int* helpingArray = (int*)malloc((max + 1) * sizeof(int));

	for (int i = 0; i < max - min + 1; ++i) {
		helpingArray[i] = 0;
	}

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

int sortCheck(int a[], int size) {
	for (int i = 0; i < size; ++i) {
		if (a[i] > a[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int firstTest() {
	int a[10000];
	for (int i = 0; i < 10000; ++i) {
		a[i] = 10000 - i - 1;
	}

	calculationSort(10000, a);
	int check = sortCheck(a, 10000);
	if (check == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int secondTest() {
	int a[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = 10;
	}

	calculationSort(10, a);
	int check = sortCheck(a, 10);
	
	if (check == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int thirdTest() {
	int a[] = { 7, 8, 3, 4, 1, 2, 6, 5, 2 };

	calculationSort(9, a);
	int check = sortCheck(a, 9);
	if (check == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int fourthTest() {
	int a[] = { 1 };
	calculationSort(1, a);
	for (int i = 0; i < 1; ++i) {
		if (a[i] != 1) {
			return 0;
		}
	}
	return 1;
}

int main() {
	if (firstTest() == 0) {
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