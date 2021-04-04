using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Routers
{
    public class FileFunctions
    {
        public static int[,] CreateGraph(string pathToGraph)
        {
            int countsVertices = GetAmountOfVertices(pathToGraph);
            var graph = new int[countsVertices, countsVertices];

            int lines = File.ReadAllLines(pathToGraph).Length;
            string[] stringsArray = File.ReadAllLines(pathToGraph);

            for (int i = 0; i < stringsArray.Length; i++)
            {
                stringsArray[i] = stringsArray[i].Replace(',', ' ');

                string[] currentLine = stringsArray[i].Split(" ", StringSplitOptions.RemoveEmptyEntries);

                var currentVertex = Int32.Parse(currentLine[0].Substring(0, currentLine[0].Length - 1)) - 1;

                for (int j = 0; j < currentLine.Length / 2; j++)
                {
                    var secondVertex = Int32.Parse(currentLine[2 * j + 1]) - 1;

                    var distance = Int32.Parse(currentLine[2 * j + 2].Substring(1, currentLine[2 * j + 2].Length - 2));

                    graph[currentVertex, secondVertex] = distance;
                    graph[secondVertex, currentVertex] = distance;
                }
            }

            return graph;
        }

        public static int GetAmountOfVertices(string pathToGraph)
        {
            var maxVertix = 1;
            string[] stringsArray = File.ReadAllLines(pathToGraph);
            int lines = stringsArray.Length;

            for (int i = 0; i < lines; i++)
            {
                stringsArray[i] = stringsArray[i].Replace(',', ' ');

                string[] currentLine = stringsArray[i].Split(" ", StringSplitOptions.RemoveEmptyEntries);

                var currentVertex = Int32.Parse(currentLine[0].Substring(0, currentLine[0].Length - 1));

                maxVertix = Math.Max(currentVertex, maxVertix);

                for (int j = 0; j < currentLine.Length / 2; j++)
                {
                    var secondVertex = Int32.Parse(currentLine[2 * j + 1]);

                    maxVertix = Math.Max(secondVertex, maxVertix);
                }
            }

            return maxVertix;
        }

        public static void WriteResultInFile(int[,] matrix, string newPath)
        {
            FileInfo fileOut = new FileInfo(newPath);

            if (fileOut.Exists)
            {
                fileOut.Delete();
            }

            FileStream currentFile = new FileStream(newPath, FileMode.Create);
            StreamWriter writer = new StreamWriter(currentFile);

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
