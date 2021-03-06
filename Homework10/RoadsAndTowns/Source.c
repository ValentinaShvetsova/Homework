#include "List.h"
#include "Graph.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void useCity(int** graph, int size, int capitalNumber, int* distance, bool* used, struct List* towns, int* numberOfLeftoverCities) {
	if (*numberOfLeftoverCities == 0) {
		return;
	}
	int minimumDistance = INT_MAX;
	int currentVertex = -1;
	for (int i = 0; i < size; ++i)
	{
		if (!used[i] && distance[i] < minimumDistance)
		{
			minimumDistance = distance[i];
			currentVertex = i;
		}
	}
	if (currentVertex == -1)
	{
		return;
	}
	for (int i = 0; i < size; ++i)
	{
		if (graph[currentVertex][i] != 0 && !used[i] && distance[currentVertex] + graph[currentVertex][i] < distance[i])
		{
			distance[i] = distance[currentVertex] + graph[currentVertex][i];
		}
	}
	used[currentVertex] = true;
	addValue(currentVertex, towns);
	(*numberOfLeftoverCities) -= 1;
}

void distributeCities(int** graph, int size, int* capitals, int numberOfCapitals, struct List** towns) {
	bool* used = calloc(size, sizeof(bool));
	int** distance = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		distance[i] = calloc(size, sizeof(int));
		for (int j = 0; j < size; ++j)
		{
			distance[i][j] = INT_MAX;
		}
		distance[i][capitals[i]] = 0;
	}

	int amountOfLeftoverCities = size;
	while ((amountOfLeftoverCities) > 0)
	{
		for (int i = 0; i < numberOfCapitals; ++i)
		{
			useCity(graph, size, capitals[i], distance[i], used, towns[i], &amountOfLeftoverCities);
		}
	}
	free(used);
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		free(distance[i]);
	}
	free(distance);
}

bool tests() {
	FILE* file = fopen("test.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
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
	distributeCities(graph, size, capitals, numberOfCapitals, towns);
	deleteGraph(graph, size);

	free(capitals);

	struct List* answer1 = createList();
	addValue(0, answer1);
	addValue(4, answer1);
	addValue(3, answer1);

	struct List* answer2 = createList();
	addValue(1, answer2);
	addValue(2, answer2);

	bool testPassed = (compareLists(answer1, towns[0]) && compareLists(answer2, towns[1]));
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		deleteList(towns[i]);
	}
	free(towns);
	deleteList(answer1);
	deleteList(answer2);
	return testPassed;
}

int main() {
	if (!tests()) {
		return 1;
	}

	FILE* file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
	}

	int size = 0;
	int numberOfRoads = 0;
	fscanf(file, "%d %d", &size, &numberOfRoads);

	int** graph = (int*)malloc(size * size * sizeof(int));
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
	distributeCities(graph, size, capitals, numberOfCapitals, towns);
	deleteGraph(graph, size);

	free(capitals);

	for (int i = 0; i < numberOfCapitals; ++i)
	{
		printf("Cities of state %d: ", i + 1);
		printList(towns[i]);
		printf("\n");
	}
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		deleteList(towns[i]);
	}
	free(towns);
	return 0;
}