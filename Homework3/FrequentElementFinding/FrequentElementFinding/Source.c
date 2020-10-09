#include <stdio.h>
#include <stdbool.h>

void insertionSort(int leftCounter, int rightCounter, int array[])
{

	for (int i = leftCounter; i <= rightCounter; i++)
	{
		int newElement = array[i];
		int location = i - 1;
		while (location >= 0 && array[location] > newElement)
		{
			array[location + 1] = array[location];
			location = location - 1;
		}
		array[location + 1] = newElement;
	}
}

int findBorderIndex(int array[], int borderElement, int leftBorder, int rightBorder) {
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
	int size = rightCounter - leftCounter + 1;
	if (size <= 10) {
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

int findFrequentElement(int array[], int size) {
	int previous = array[0];
	int count = 1;
	int memorized = previous;
	int maxCount = 1;
	for (int i = 1; i < size; ++i) {
		if (array[i] == previous) {
			++count;
		}
		else
		{
			if (maxCount < count)
			{
				maxCount = count;
				memorized = previous;
			}
			previous = array[i];
			count = 1;
		}
	}
	if (maxCount < count)
	{
		maxCount = count;
		memorized = previous;
	}
	return memorized;
}
bool firstTest()
{
	int array[5] = { 3, 7, 2, 8, 1 };
	return findFrequentElement(array, 5) == 3;
}

bool secondTest()
{
	int array[4] = { 7, 7, 7, 7 };
	return findFrequentElement(array, 4) == 7;
}

bool thirdTest()
{
	int array[10] = { 3, 9, 15, 7, 8, 4, 7, 3, 2, 4 };
	return findFrequentElement(array, 10) == 3;
}

int main() {
	
	if (firstTest() == false || secondTest() == false || thirdTest() == false) {
		printf("Test failed\n");
		return 1;
	}
	int size = 19;

	int array[19] = { 1, 3, 6, 5, 3, 5, 10, 65, 1, 23, 5, 8765, 9, 1, 2, 3, 54, 3, 5 };

	quickSort(array, 0, size - 1);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	int element = findFrequentElement(array, size);

	printf("\nElement %d is the most frequent\n", element);
	return 0;
}
