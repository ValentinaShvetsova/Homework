using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Routers
{
    /// <summary>
    /// Functions that reading from file, writing in file, creating a graph from file
    /// </summary>
    public static class FileFunctions
    {
        /// <summary>
        /// Returns a adjacency table
        /// </summary>
        /// <param name="pathToGraph">Path to file</param>
        public static int[,] CreateGraph(string pathToGraph)
        {
            int countsVertices = GetAmountOfVertices(pathToGraph);
            var graph = new int[countsVertices + 1, countsVertices + 1];

            using (StreamReader stream = File.OpenText(pathToGraph))
            {
                string readString;
                var symbols = new char[] { ' ', '(', ')', ':', ',' };
                while ((readString = stream.ReadLine()) != null)
                {
                    var numbers = readString.Split(symbols, StringSplitOptions.RemoveEmptyEntries);
                    var start = int.Parse(numbers[0]);

                    int i = 2;
    
                    while (i < numbers.Length)
                    {
                        int length = Int32.Parse(numbers[i]);
                        int secondVertex = Int32.Parse(numbers[i - 1]);
                        graph[start, secondVertex] = length;
                        graph[secondVertex, start] = length;
                        i += 2;
                    }
                }
            }
            return graph;
        }

        /// <summary>
        /// Gets amount of graph's vertices
        /// </summary>
        /// <param name="pathToGraph">path to file</param>
        public static int GetAmountOfVertices(string pathToGraph)
        {
            string[] stringsArray = File.ReadAllLines(pathToGraph);
            int lines = stringsArray.Length;

            int maxVertice = 0;
            var symbols = new char[] { ' ', '(', ')', ':', ',' };
            for (int i = 0; i < lines; i++)
            {
                var numbers = stringsArray[i].Split(symbols, StringSplitOptions.RemoveEmptyEntries);
                var intNumbers = new int[numbers.Length];
                for (int j = 0; j < numbers.Length; j++)
                {
                    var number =  Int32.Parse(numbers[j]);
                    intNumbers[j] = number;
                }
                if (intNumbers[0] > maxVertice)
                {
                    maxVertice = intNumbers[0];
                }
                for (int j = 1; j < intNumbers.Length; j += 2)
                {
                    if (intNumbers[j] > maxVertice)
                    {
                        maxVertice = intNumbers[j];
                    }
                }
            }

            return maxVertice;
        }

        /// <summary>
        /// Writes an spanning tree in needed form
        /// </summary>
        public static void WriteResultInFile(int[,] matrix, string newPath)
        {
            var fileOut = new FileInfo(newPath);

            if (fileOut.Exists)
            {
                fileOut.Delete();
            }

            using var currentFile = new FileStream(newPath, FileMode.Create);
            using var writer = new StreamWriter(currentFile);

            for (int i = 0; i < matrix.GetLength(0) - 1; i++)
            {
                var resultLine = $"{i + 1}: ";

                for (int j = i + 1; j < matrix.GetLength(0); j++)
                {
                    if (matrix[i, j] != 0)
                    {
                        resultLine += $"{j + 1} ({matrix[i, j]}), ";
                    }
                }

                if (resultLine != $"{i + 1}: ")
                {
                    writer.WriteLine(resultLine.Substring(0, resultLine.Length - 2));
                }
            }

            writer.Close();

            if (fileOut.Exists)
            {
                fileOut.MoveTo(newPath);
            }
        }
    }
}
