#include "Sort.h"

void insertionSort(const int leftCounter, const int rightCounter, int array[])
{
	for (int i = leftCounter; i <= rightCounter; i++)
	{
		int newElement = array[i];
		int location = i - 1;
		while (location >= leftCounter && array[location] > newElement)
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
			else
			{
				rightCounter--;
			}
		}
		else
		{
			leftCounter++;
		}
	}
	abuttingElementIndex = findBorderIndex(a, abuttingElement, leftBorder, rightBorder);
	quickSort(a, leftBorder, abuttingElementIndex - 1);
	quickSort(a, abuttingElementIndex, rightBorder);
}
