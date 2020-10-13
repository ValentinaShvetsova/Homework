#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

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
