#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Sort.h"

int findFrequentElement(int array[], const int size)
{
	int previous = array[0];
	int count = 1;
	int memorized = previous;
	int maxCount = 1;
	for (int i = 1; i < size; ++i)
	{
		if (array[i] == previous)
		{
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

int main()
{
	FILE* file = fopen("data.txt", "r");
	if (file == NULL) 
	{
		printf("File can not be opened.\n");
		return 0;
	}
	int size = 0;
	fscanf(file, "%d", &size);

	int* array = malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i) 
	{
		fscanf(file, "%d", &array[i]);
	}

	quickSort(array, 0, size - 1);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

	int element = findFrequentElement(array, size);

	printf("\nElement %d is the most frequent\n", element);
	
	free(array);
	fclose(file);
	return 0;
}