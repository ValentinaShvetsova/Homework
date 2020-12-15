#include "List.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
	FILE* file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
	}

	int size = 0;
	int edges = 0;
	fscanf(file, "%d %d", &size, &edges);

	int** graph = (int*)malloc(size * size * sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		graph[i] = calloc(size, sizeof(int));
	}
	for (int i = 0; i < edges; ++i)
	{
		int firstVertex = 0;
		fscanf(file, "%d", &firstVertex);
		int secondVertex = 0;
		fscanf(file, "%d", &secondVertex);
		
		graph[firstVertex][secondVertex] = 1;
		graph[secondVertex][firstVertex] = 1;
	}
	int* used = calloc(size, sizeof(int));
	struct List* list = createList();
	addValue(0, list);
	while (!isEmpty(list)) {
		int vertex = returnValue(list, 1);
		deleteHead(list);
		used[vertex] = 2;
		for (int j = 0; j < size; j++) {
			if (graph[vertex][j] == 1 && used[j] == 0) {
				addValue(j, list); 
				used[j] = 1;
			}
		}
		printf("%d\n", vertex);
	}
	deleteGraph(graph, size);
	free(used);
	deleteList(list);
	fclose(file);
	return 0;
}
