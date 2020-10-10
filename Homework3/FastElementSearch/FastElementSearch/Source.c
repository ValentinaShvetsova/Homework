#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool binSearch(int array[], const int size, const int element)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		const int middle = (left + right) / 2;
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
			return true;
		}
	}
	return false;
}

void insertionSort(const int leftCounter, const int rightCounter, int array[])
{
	for (int i = leftCounter; i <= rightCounter; i++)
	{
		int newElement = array[i];
		int location = i - 1;
		while (location >= 0 && array[location] > newElement)
		{
			array[location + 1] = array[location];
			location--;
		}
		array[location + 1] = newElement;
	}
}

int findBorderIndex(int array[], int borderElement, const int leftBorder, const int rightBorder) 
{
	int borderIndex = 0;
	for (int i = leftBorder; i < rightBorder; ++i) 
	{
		if (array[i] >= borderElement) 
		{
			borderIndex = i;
			break;
		}
	}
	return borderIndex;
}

void quickSort(int a[], int leftCounter, int rightCounter) 
{
	const int size = rightCounter - leftCounter + 1;
	if (size <= 10) 
	{
		insertionSort(leftCounter, rightCounter, a);
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
	abuttingElementIndex = findBorderIndex(a, abuttingElement, leftBorder, rightBorder);
	quickSort(a, leftBorder, abuttingElementIndex - 1);
	quickSort(a, abuttingElementIndex, rightBorder);
}

bool testWithElementInArray() 
{
	int array[] = { 1, 2, 3, 3, 5, 6, 7, 8, 3, 1, 0, 8, 3, 9, 1 };
	int size = 15;
	quickSort(array, 0, size - 1);
	return binSearch(array, size, 5);
}

bool testWithoutElementInArray() 
{
	int array[] = { 1, 2, 3, 3, 5, 6, 7, 8, 3, 1, 0, 8, 3, 9, 1 };
	int size = 15;
	quickSort(array, 0, size - 1);
	return binSearch(array, size, 12);
}

int main() 
{
	if (!testWithElementInArray() || testWithoutElementInArray())
	{
		printf("Test failed");
		return 1;
	}
	printf("Input n: ");
	int n = 0;
	scanf("%d", &n);

	printf("Input k: ");
	int k = 0;
	scanf("%d", &k);

	int *array = (int*)malloc(n * sizeof(int));
	printf("Final array: ");

	for (int i = 0; i < n; i++) 
	{
		array[i] = rand() % 100;
		printf("%d ", array[i]);
	}
	
	quickSort(array, 0, n - 1);

	int *numbers = (int*)malloc(k * sizeof(int));
	printf("Numbers: ");

	for (int i = 0; i < k; i++) 
	{
		numbers[i] = rand() % 100;
		printf("%d ", numbers[i]);
	}

	printf("\nNumbers found in array: ");
	for (int i = 0; i < k; i++)
	{
		if (binSearch(array, n, numbers[i]))
		{
			printf("%d ", numbers[i]);
		}
	}
	free(array);
	free(numbers);
	return 0;
}