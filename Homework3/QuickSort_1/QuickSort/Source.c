#include <stdio.h>
#include <stdbool.h>

void insertionSort(const int leftCounter, const int rightCounter, int array[]){
	for (int i = leftCounter; i <= rightCounter; i++) {
		int newElement = array[i];
		int location = i - 1;
		while (location >= 0 && array[location] > newElement) {
			array[location + 1] = array[location];
			location --;
		}
		array[location + 1] = newElement;
	}
}

int findBorderIndex(int array[], int borderElement, const int leftBorder, const int rightBorder) {
	int borderIndex = 0;
	for (int i = leftBorder; i < rightBorder; ++i) {
		if (array[i] >= borderElement) {
			borderIndex = i;
			break;
		}
	}
	return borderIndex;
}

void quickSort(int a[], int leftCounter, int rightCounter) {
	const int size = rightCounter - leftCounter + 1;
	if (size <= 10) {
		insertionSort(leftCounter, rightCounter, a);
		return;
	}
	int leftBorder = leftCounter;
	int rightBorder = rightCounter;

	int abuttingElementIndex = (size - 1) / 2;
	int abuttingElement = a[abuttingElementIndex];

	while (leftCounter < rightCounter) {
		if (a[leftCounter] >= abuttingElement) {
			if (a[rightCounter] < abuttingElement) {
				int temp = a[rightCounter];
				a[rightCounter] = a[leftCounter];
				a[leftCounter] = temp;
				leftCounter++;
				rightCounter--;
			}
			else {
				rightCounter--;
			}
		}
		else {
			leftCounter++;
		}
	}
	int border = findBorderIndex(a, abuttingElement, leftBorder, rightBorder);
	quickSort(a, leftBorder, border - 1);
	quickSort(a, border, rightBorder);
}

bool sortTest(int array[], const int size) {
	for (int i = 1; i < size; ++i) {
		if (array[i - 1] > array[i]) {
			return false;
		}
	}
	return true;
}

bool testWithStandartArray() {
	int array[] = { 1, 3, 4, 2, 6, 5, 2, 34, 8, 12, 14, 2, 5, 7, 8, 1, 56, 3, 78, 7 };
	int size = 20;
	quickSort(array, 0, size - 1);
	return sortTest(array, size);
}

bool testWithArrayOfEqualElements() {
	int array[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int size = 10;
	quickSort(array, 0, size - 1);
	return sortTest(array, size);
}

bool testWithArrayOfOneElement() {
	int array[] = {0};
	int size = 1;
	quickSort(array, 0, size - 1);
	return sortTest(array, size);
}

int main() {
	if (!testWithStandartArray() || !testWithArrayOfEqualElements() || !testWithArrayOfOneElement()) {
		printf("Test failed\n");
		return 1;
	}
	
	int array[19] = { 1, 3, 6, 5, 3, 5, 10, 65, 1, 23, 5, 8765, 9, 1, 2, 3, 54, 3, 5 };

	quickSort(array, 0, 18);
	for (int i = 0; i < 19; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}