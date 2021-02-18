using System;
using System.Linq;

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
        public static char[] BWT(string line, char[,] transpositionTable)
        {
            int size = line.Length + 1;
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

        public static string GetAlphabetString(char[] line)
        {
            int alphabetSymbols = line.Distinct().Count();
            string result = "";
            for (int i = 0; i < line.Length; i++)
            {
                if (!result.Contains(line[i]))
                {
                    result += line[i];
                }
            }
            return result;
        }

        public static int[] GetSymbolsCount(char[] line)
        {
            string alphabetOfString = GetAlphabetString(line);
            var countOfSymbols = new int[alphabetOfString.Length];
            for (int i = 0; i < countOfSymbols.Length; i++)
            {
                countOfSymbols[i] = line.Where(x => x == alphabetOfString[i]).Count();
            }
            return countOfSymbols;
        }

        public static char[] ReverseBWT(char[] line, char[,] transpositionTable)
        {
            int length = line.Length;
            int[] countOfSymbols = GetSymbolsCount(line);
            int sum = 0;
            for(int i = 0; i < countOfSymbols.Length; i++)
            {
                sum = sum + countOfSymbols[i];
                countOfSymbols[i] = sum - countOfSymbols[i];
            }
            string alphabetOfString = GetAlphabetString(line);
            var temp = new int[line.Length];
            for (int i = 0; i < line.Length; i++)
            {
                for (int j = 0; j < alphabetOfString.Length; j++)
                {
                    if (line[i] == alphabetOfString[j])
                    {
                        temp[countOfSymbols[j]] = i;
                        countOfSymbols[j]++;
                    }
                }
            }
            int numberOfString = 0;
            for (int i = 0; i < line.Length; i++)
            {
                if(transpositionTable[i, line.Length - 1] == '$')
                {
                    numberOfString = i;
                }
            }
            int help = temp[numberOfString];
            var answer = new char[line.Length]; 
            for(int i = 0; i < line.Length; i++)
            {
                answer[i] = line[help];
                help = temp[help];
            }
            return answer;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Enter the string: ");
            string line = Console.ReadLine();
            int size = line.Length + 1;
            char[,] transpositionTable = new char[size, size];
            var result = BWT(line, transpositionTable);
            for (int i = 0; i < line.Length + 1; ++i)
            {
                Console.Write(result[i]);
            }
            char[] res2 = ReverseBWT(result, transpositionTable);
            Console.WriteLine();
            for (int i = 0; i < line.Length + 1; ++i)
            {
                Console.Write(res2[i]);
            }
        }
    }
}
