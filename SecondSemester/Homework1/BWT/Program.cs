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
                if (transpositionTable[i, t] < (transpositionTable[j, t]))
                {
                    return 1;
                } else if (transpositionTable[i, t] > (transpositionTable[j, t]))
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

        public static Tuple<string, int> BWT(string line)
        {
            int size = line.Length + 1;
            char[,] transpositionTable = new char[size, size];
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
            var res = new String(result);
            return new Tuple<string, int>(res, numberOfString);
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

        public static string ReverseBWT(string str, int numberOfString)
        {
            char[] line = str.ToCharArray(0, str.Length);
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
            var result = new String(answer);
            result = result.Substring(0, result.Length - 1);
            return result;
        }

        public static bool Tests()
        {
            string string1 = "banana";
            var (result, numberOfString) = BWT(string1);
            if (result != "annb$aa")
            {
                return false;
            }
            
            string oldString1 = ReverseBWT("annb$aa", numberOfString);
            
            return (oldString1 == string1);
        }

        static void Main(string[] args)
        {
            if (!Tests())
            {
                return;
            }
            Console.WriteLine("Enter the string: ");
            string line = Console.ReadLine();

            var (result, numberOfString) = BWT(line);

            Console.WriteLine("Resulting string: " + result);

            string res2 = ReverseBWT(result, numberOfString);
            Console.WriteLine("Old string: " + res2);
        }
    }
}
