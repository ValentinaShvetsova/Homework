#include <stdio.h>

int binSearch(int array[], int size, int element)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (element < array[middle])
		{
			right = middle - 1;
		}
		else if (element > array[middle])
		{
			left = middle + 1;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

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

int test1() {
	int array[] = { 1, 2, 3, 3, 5, 6, 7, 8, 3, 1, 0, 8, 3, 9, 1 };
	int size = 15;
	QuickSort(array, 0, size - 1);
	return binSearch(array, size, 5);
}

int test2() {
	int array[] = { 1, 2, 3, 3, 5, 6, 7, 8, 3, 1, 0, 8, 3, 9, 1 };
	int size = 15;
	QuickSort(array, 0, size - 1);
	return binSearch(array, size, 12);
}

int main() {
	if (test1() == 0 || test2 == 1) {
		printf("Test failed");
		return 0;
	}
	printf("Input n: ");
	int n = 0;
	scanf("%d", &n);

	printf("Input k: ");
	int k = 0;
	scanf("%d", &k);

	int* mass = (int*)malloc(n * sizeof(int));
	printf("Final array: ");

	for (int i = 0; i < n; i++) {
		mass[i] = rand() % 100;
		printf("%d ", mass[i]);
	}
	
	QuickSort(mass, 0, n - 1);

	int* numbers = (int*)malloc(k * sizeof(int));
	printf("Numbers: ");

	for (int i = 0; i < k; i++) {
		numbers[i] = rand() % 100;
		printf("%d ", numbers[i]);
	}

	printf("\nNumbers found in array: ");
	for (int i = 0; i < k; i++)
	{
		if (binSearch(mass, n, numbers[i]) == 1)
		{
			printf("%d ", numbers[i]);
		}
	}
	free(mass);
	free(numbers);
	return 0;
}