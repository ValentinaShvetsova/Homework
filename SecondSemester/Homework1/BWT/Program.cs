using System;

namespace BWT
{
    class Program
    {
        public static void SwapStrings(char[,] transpositionTable, int size, int i, int j)
        {
            char temp;
            for (int t = 0; t < size; ++t)
            {
                temp = transpositionTable[i, t];
                transpositionTable[i, t] = transpositionTable[j, t];
                transpositionTable[j, t] = temp;
            }
        }

        public static int CompareStrings(char[,] transpositionTable, int size, int i, int j)
        {
            for(int t = 0; t < size; ++t)
            {
                if(transpositionTable[i, t].CompareTo(transpositionTable[j, t]) < 0)
                {
                    return 1;
                } else if (transpositionTable[i, t].CompareTo(transpositionTable[j, t]) > 0)
                {
                    return -1;
                }
            }
            return 1;
        }
        public static void Sort(char[,] transpositionTable, int size)
        {
            for(int i = 0; i < size; i++)
            {
                for(int j = size - 1; j > i; j--)
                {
                    if(CompareStrings(transpositionTable, size, i, j) == -1)
                    {
                        SwapStrings(transpositionTable, size, i, j);
                    }
                }
            }
        }
        public static char[] BWT(string line)
        {
            int size = line.Length + 1;
            char[,] transpositionTable = new char[size, size];
            var result = new char[size];
            for(int i = 0; i < size - 1; ++i)
            {
                transpositionTable[0,i] = line[i];
            }
            transpositionTable[0, size - 1] = '$';
            for (int i = 1; i < size; i++)
            {
                transpositionTable[i, 0] = transpositionTable[i - 1, size - 1];
                for (int j = 1; j < size; j++)
                {
                    transpositionTable[i, j] = transpositionTable[i - 1, j - 1];
                }
            }
            Sort(transpositionTable, size);
            for(int i = 0; i < size; ++i)
            {
                result[i] = transpositionTable[i, size - 1];
            }
            return result;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Enter the string: ");
            string line = Console.ReadLine();
            var result = BWT(line);
            for (int i = 0; i < line.Length + 1; ++i)
            {
                Console.Write(result[i]);
            }
        }
    }
}
