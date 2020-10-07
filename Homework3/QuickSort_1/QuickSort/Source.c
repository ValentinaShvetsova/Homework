#include <stdio.h>

void InsertionSort(int leftCounter, int rightCounter, int array[])
{
	int newElement, location;

	for (int i = leftCounter; i <= rightCounter; i++)
	{
		newElement = array[i];
		location = i - 1;
		while (location >= 0 && array[location] > newElement)
		{
			array[location + 1] = array[location];
			location = location - 1;
		}
		array[location + 1] = newElement;
	}
}

int borderIndexfinding(int array[], int abuttingElement, int leftBorder, int rightBorder) {
	int borderIndex = 0;
	for (int i = leftBorder; i < rightBorder; ++i) {
		if (array[i] >= abuttingElement) {
			borderIndex = i;
			break;
		}
	}
	return borderIndex;
}

void QuickSort(int a[], int leftCounter, int rightCounter) {
	int size = rightCounter - leftCounter + 1;
	if (size <= 10) {
		InsertionSort(leftCounter, rightCounter, a);
		return;
	}
	int leftBorder = leftCounter;
	int rightBorder = rightCounter;

	int abuttingElementIndex = (size - 1) / 2;
	int abuttingElement = a[abuttingElementIndex];

	while (leftCounter < rightCounter)
	{
		if (a[leftCounter] >= abuttingElement)
		{
			if (a[rightCounter] < abuttingElement)
			{
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
	abuttingElementIndex = borderIndexfinding(a, abuttingElement, leftBorder, rightBorder);
	QuickSort(a, leftBorder, abuttingElementIndex - 1);
	QuickSort(a, abuttingElementIndex, rightBorder);
}

int sortTest(int array[], int size) {
	for (int i = 1; i < size; ++i) {
		if (array[i - 1] > array[i]) {
			return 0;
		}
	}
	return 1;
}

int test1() {
	int array[] = { 1, 3, 4, 2, 6, 5, 2, 34, 8 };
	int size = 9;
	QuickSort(array, 0, size - 1);
	return sortTest(array, size);
}

int test2() {
	int array[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int size = 21;
	QuickSort(array, 0, size - 1);
	return sortTest(array, size);
}

int test3() {
	int array[] = {0};
	int size = 1;
	QuickSort(array, 0, size - 1);
	return sortTest(array, size);
}


int main() {
	if (test1 == 0 || test2 == 0 || test3 == 0) {
		printf("Test failed\n");
		return 0;
	}
	int size = 19;

	int array[19] = { 1, 3, 6, 5, 3, 5, 10, 65, 1, 23, 5, 8765, 9, 1, 2, 3, 54, 3, 5 };

	QuickSort(array, 0, size - 1);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}