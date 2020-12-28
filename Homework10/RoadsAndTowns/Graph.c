#include "Graph.h"
#include <stdlib.h>

void deleteGraph(int** graph, int size) {
	for (int i = 0; i < size; ++i)
	{
		free(graph[i]);
	}
	free(graph);
}
