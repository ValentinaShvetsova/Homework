#include <stdio.h>
#include <time.h>

void bubbleSort(int* array, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = (size - 1); j > i; --j) {
			if (array[j - 1] > array[j]) {
				int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

int firstTest() {
	int a[10000];
	for (int i = 0; i < 10000; ++i) {
		a[i] = 10000 - i - 1;
	}
	bubbleSort(a, 10000);
	for (int i = 0; i < 9999; ++i) {
		if (a[i] > a[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int secondTest() {
	int a[10];
	for (int i = 0; i < 10; ++i) {
		a[i] = 10;
	}
	bubbleSort(a, 10);
	for (int i = 0; i < 9; ++i) {
		if (a[i] > a[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int thirdTest() {
	int a[] = {7, 8, 3, 4, 1, 2, 6, 5, 2};
	
	bubbleSort(a, 9);
	for (int i = 0; i < 8; ++i) {
		if (a[i] > a[i + 1]) {
			return 0;
		}
	}
	return 1;
}

int fourthTest() {
	int a[] = {1};
	bubbleSort(a, 1);
	for (int i = 0; i < 1; ++i) {
		if (a[i] != 1) {
			return 0;
		}
	}
	return 1;
}

int main() {
	if (firstTest() == 0 || secondTest() == 0 || thirdTest() == 0 || fourthTest() == 0) {
		printf("Test failed\n");
		return 0;
	}

	int size = 100000;
	int a[100000];
	for (int i = 0; i < size; ++i) {
		a[i] = size - i - 1;
	}
	
	clock_t start;
	start = clock();
	bubbleSort(a, size);
	clock_t stop;
	stop = clock();
	int time = (stop - start) / CLK_TCK;
	printf("Time of working: %d\n", time);

	for (int i = 0; i < size; ++i) {
		printf("%d ", a[i]);
	}
	return 0;
}