using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Routers
{
    public class FileFunctions
    {
        /// <summary>
        /// Returns a adjacency table
        /// </summary>
        /// <param name="pathToGraph">Path to file</param>
        public static int[,] CreateGraph(string pathToGraph)
        {
            int countsVertices = GetAmountOfVertices(pathToGraph);
            var graph = new int[countsVertices, countsVertices];

            using (StreamReader stream = File.OpenText(pathToGraph))
            {
                string readString;
                var symbols = new char[] { ' ', '(', ')', ':', ',' };
                while ((readString = stream.ReadLine()) != null)
                {
                    var numbers = readString.Split(symbols, StringSplitOptions.RemoveEmptyEntries);
                    var start = int.Parse(numbers[0]);
    
                    for (int i = 2; i < numbers.Length; i += 2)
                    {
                        graph[start, i - 1] = i;
                        graph[i - 1, start] = i;
                    }
                }
            }
            return graph;
        }

        /// <summary>
        /// Gets amount of graph's vertices
        /// </summary>
        /// <param name="pathToGraph">path to file</param>
        /// <returns></returns>
        public static int GetAmountOfVertices(string pathToGraph)
        {
            string[] stringsArray = File.ReadAllLines(pathToGraph);
            int lines = stringsArray.Length;

            return lines;
        }

        /// <summary>
        /// Writes an spanning tree in needed form
        /// </summary>
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
