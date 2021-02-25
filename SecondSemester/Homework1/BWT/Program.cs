using System;
using System.Linq;

namespace BWT
{
    class Program
    {
        private static void SwapStrings(char[,] transpositionTable, int i, int j)
        {
            int size = transpositionTable.GetLength(0);
            for (int t = 0; t < size; ++t)
            {
                char temp = transpositionTable[i, t];
                transpositionTable[i, t] = transpositionTable[j, t];
                transpositionTable[j, t] = temp;
            }
        }

        private static int CompareStrings(char[,] transpositionTable, int i, int j)
        {
            int size = transpositionTable.GetLength(0);
            for (int t = 0; t < size; ++t)
            {
                if (transpositionTable[i, t].CompareTo(transpositionTable[j, t]) < 0)
                {
                    return 1;
                } else if (transpositionTable[i, t].CompareTo(transpositionTable[j, t]) > 0)
                {
                    return -1;
                }
            }
            return 1;
        }

        private static void Sort(char[,] transpositionTable)
        {
            int size = transpositionTable.GetLength(0);
            for (int i = 0; i < size; i++)
            {
                for (int j = size - 1; j > i; j--)
                {
                    if (CompareStrings(transpositionTable, i, j) == -1)
                    {
                        SwapStrings(transpositionTable, i, j);
                    }
                }
            }
        }

        public static Tuple<char[], int> BWT(string line, char[,] transpositionTable)
        {
            int size = line.Length + 1;
            var result = new char[size];
            for (int i = 0; i < size - 1; ++i)
            {
                transpositionTable[0, i] = line[i];
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
            Sort(transpositionTable);
            
            int numberOfString = 0;
            for (int i = 0; i < line.Length; i++)
            {
                if (transpositionTable[i, line.Length] == '$')
                {
                    numberOfString = i;
                }
            }

            for (int i = 0; i < size; ++i)
            {
                result[i] = transpositionTable[i, size - 1];
            }
            return new Tuple<char[], int>(result, numberOfString);
        }

        private static char[] GetAlphabetString(char[] line)
        {
            string result = "";
            for (int i = 0; i < line.Length; i++)
            {
                if (!result.Contains(line[i]))
                {
                    result += line[i];
                }
            }
            char[] alphabetArray = result.ToCharArray();
            Array.Sort(alphabetArray);
            return alphabetArray;
        }

        private static int[] GetSymbolsCount(char[] line)
        {
            char[] alphabetOfString = GetAlphabetString(line);
            var countOfSymbols = new int[alphabetOfString.Length];
            for (int i = 0; i < countOfSymbols.Length; i++)
            {
                countOfSymbols[i] = line.Where(x => x == alphabetOfString[i]).Count();
            }
            return countOfSymbols;
        }

        public static char[] ReverseBWT(char[] line, int numberOfString)
        {
            int length = line.Length;
            int[] countOfSymbols = GetSymbolsCount(line);
            int sum = 0;
            for (int i = 0; i < countOfSymbols.Length; i++)
            {
                sum += countOfSymbols[i];
                countOfSymbols[i] = sum - countOfSymbols[i];
            }
            char[] alphabetOfString = GetAlphabetString(line);
            var temp = new int[line.Length];
            for (int i = 0; i < line.Length; i++)
            {
                for (int j = 0; j < alphabetOfString.Length; j++)
                {
                    if (line[i] == alphabetOfString[j])
                    {
                        temp[i] = countOfSymbols[j];
                        countOfSymbols[j]++;
                    }
                }
            }
            
            var answer = new char[line.Length]; 
            for (int i = line.Length - 1; i > -1; i--)
            {
                answer[i] = line[numberOfString];
                numberOfString = temp[numberOfString];
            }
            return answer;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Enter the string: ");
            string line = Console.ReadLine();
            int size = line.Length + 1;
            char[,] transpositionTable = new char[size, size];

            var result = BWT(line, transpositionTable).Item1;
            var numberOfString = BWT(line, transpositionTable).Item2;
            var resultString = new String(result);

            Console.WriteLine("Resulting string: " + resultString);

            char[] res2 = ReverseBWT(result, numberOfString);
            var resultString2 = new String(res2);
            Console.WriteLine("Old string: " + resultString2.Remove(line.Length));
        }
    }
}
