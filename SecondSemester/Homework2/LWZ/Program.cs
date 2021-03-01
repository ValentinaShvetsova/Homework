using System;
using System.IO;

namespace LWZ
{
    class Program
    {
        private static string GetAlphabetString(string line)
        {
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

        public static string SqueezeString(string input)
        {
            var trie = new Trie<int>();
            string alphabet = GetAlphabetString(input);
            for (int i = 0; i < alphabet.Length; i++)
            {
                trie.Add(alphabet.Substring(i, 1), i);
            }
            int counter = alphabet.Length;
            string result = "";

            int index = 0;
            while (index < input.Length)
            {
                int length = 1;
                while ((length <= input.Length - index) && (trie.TrySearch(input.Substring(index, length), out int value)))
                {
                    length++;
                }
                trie.TrySearch(input.Substring(index, length - 1), out int number);
                string correctValue = number.ToString();
                result += correctValue;
                if(index != input.Length - 1)
                {
                    trie.Add(input.Substring(index, length), counter);
                }
                counter++;
                index += length - 1;
            }
            return result;
        }

        public static void WriteInFile(string pathToFile, string result)
        {
            string resultPath = pathToFile + ".zipped";
            using FileStream fileOut = File.OpenWrite(resultPath);
            using (StreamWriter sw = new StreamWriter(resultPath, false, System.Text.Encoding.Default))
            {
                sw.WriteLine(result);
            }
        }
        static void Main(string[] args)
        {
            string path = @"C:\Users\Aser_Pc\Desktop\Си\Homework\SecondSemester\Homework2\LWZ\Text.txt";
            System.IO.StreamReader file = new System.IO.StreamReader(path);
            string input = file.ReadLine();
            file.Close();
            string squeezedInput = SqueezeString(input);
            WriteInFile(path, squeezedInput);
        }
    }
}
