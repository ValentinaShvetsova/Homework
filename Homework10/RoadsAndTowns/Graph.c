#include <stdio.h>
#include <stdbool.h>
#include "List.h"
#include "Graph.h"
#include <stdlib.h>

void fillGraph(char* fileName) {
	FILE* file = fopen(fileName, "r");
	if (!file)
	{
		return;
	}

	int size = 0;
	int numberOfRoads = 0;
	fscanf(file, "%d %d", &size, &numberOfRoads);

	int** graph = (int**)malloc(size * size * sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		graph[i] = calloc(size, sizeof(int));
	}

	for (int i = 0; i < numberOfRoads; ++i)
	{
		int firstCityNumber = 0;
		fscanf(file, "%d", &firstCityNumber);
		int secondCityNumber = 0;
		fscanf(file, "%d", &secondCityNumber);
		int length = 0;
		fscanf(file, "%d", &length);
		graph[firstCityNumber][secondCityNumber] = length;
		graph[secondCityNumber][firstCityNumber] = length;
	}

	int numberOfCapitals = 0;
	fscanf(file, "%d", &numberOfCapitals);

	int* capitals = (int*)malloc(numberOfCapitals * sizeof(int));

	struct List** towns = (int*)malloc(numberOfCapitals * sizeof(struct List*));
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		int capitalNumber = 0;
		fscanf(file, "%d", &capitalNumber);
		capitals[i] = capitalNumber;
		towns[i] = createList();
	}
	fclose(file);
}

void deleteGraph(int** graph, int size) {
	for (int i = 0; i < size; ++i)
	{
		free(graph[i]);
	}
	free(graph);
}
