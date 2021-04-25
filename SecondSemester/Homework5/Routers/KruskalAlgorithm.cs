using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Routers
{
    public class KruskalAlgorithm
    {
        private static void DepthFirstWalk(int vertex, int[,] graph, ref bool[] used)
        {
            if (used[vertex])
            {
                return;
            }

            used[vertex] = true;
            for (int i = 0; i < used.Length; i++)
            {
                if (graph[vertex, i] == 1)
                {
                    DepthFirstWalk(i, graph, ref used);
                }
            }
        }

        public static bool CheckConnection(int[,] graph)
        {
            int countOfVertices = graph.Length;
            var used = new bool[countOfVertices];
            DepthFirstWalk(0, graph, ref used);

            for (int i = 0; i < used.Length; i++)
            {
                if (!used[i])
                {
                    return false;
                }
            }
            return true;
        }
        private static bool UtilitySycleCheck(int currentVertex, bool[] visited, int parent, List<int>[] adjacencyList)
        {
            visited[currentVertex] = true;

            foreach (var nextVertex in adjacencyList[currentVertex])
            {
                if (!visited[nextVertex])
                {
                    if (UtilitySycleCheck(nextVertex, visited, currentVertex, adjacencyList))
                    {
                        return true;
                    }
                }
                else if (nextVertex != parent)
                {
                    return true;
                }
            }
            return false;
        }

        private static bool CycleCheck(int size, List<int>[] adjacencyList)
        {
            bool[] visited = new bool[size];

            for (int currentVertex = 0; currentVertex < size; currentVertex++)
            {
                if (!visited[currentVertex])
                {
                    if (UtilitySycleCheck(currentVertex, visited, -1, adjacencyList))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        /// <summary>
        /// Finds and writes in matrix form minimal spanning tree
        /// </summary>
        /// <param name="matrix"></param>
        /// <returns></returns>
        public static int[,] KruskalsAlgorithm(int[,] matrix)
        {
            if (!CheckConnection(matrix))
            {
                throw new DisconnectedNetworkException("Disconnected network!");
            }

            IEnumerable<(int firstVertex, int secondVertex, int weight)> weightsArray = SortByWeights(matrix);
            var sizeOfMatrix = matrix.GetLength(0);
            var resultMatrix = new int[sizeOfMatrix, sizeOfMatrix];
            var adjacencyList = new List<int>[sizeOfMatrix];
            var setVertices = new Set(sizeOfMatrix);

            for (int i = 0; i < sizeOfMatrix; ++i)
            {
                adjacencyList[i] = new List<int>();
            }

            foreach (var item in weightsArray)
            {
                resultMatrix[item.firstVertex, item.secondVertex] = item.weight;
                resultMatrix[item.secondVertex, item.firstVertex] = item.weight;
                adjacencyList[item.firstVertex].Add(item.secondVertex);
                adjacencyList[item.secondVertex].Add(item.firstVertex);

                if (CycleCheck(sizeOfMatrix, adjacencyList))
                {
                    resultMatrix[item.firstVertex, item.secondVertex] = 0;
                    resultMatrix[item.secondVertex, item.firstVertex] = 0;
                    adjacencyList[item.firstVertex].Remove(item.secondVertex);
                    adjacencyList[item.secondVertex].Remove(item.firstVertex);
                    continue;
                }

                setVertices.Unite(item.firstVertex, item.secondVertex);
            }
            return resultMatrix;
        }
        private static IEnumerable<(int firstVertex, int secondVertex, int weight)> SortByWeights(int[,] matrix)
        {
            var length = matrix.GetLength(0);
            var listToSort = new List<(int firstVertex, int secondVertex, int weight)>();

            for (int i = 0; i < length - 1; i++)
            {
                for (int j = i + 1; j < length; j++)
                {
                    if (matrix[i, j] != 0)
                    {
                        listToSort.Add((i, j, matrix[i, j]));
                    }
                }
            }
            return listToSort.OrderByDescending(x => x.weight).ToList();
        }

    }
}
