using System;
using System.IO;
using System.Collections.Generic;

namespace LWZ
{
    public class Program
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

        public static string Decompress(string squeezedStr, string alphabet)
        {
            var words =new Dictionary<int, string>();
            int counter = 0;
            string result = "";
            for(int i = 0; i < alphabet.Length; i++)
            {
                words.Add(counter, alphabet.Substring(i, 1));
                counter++;
            }
            for(int i = 0; i < squeezedStr.Length; i++)
            {
                int key = Int32.Parse(squeezedStr.Substring(i,1));
                result += words[key];
                if(i != squeezedStr.Length - 1)
                {
                    var nextKey = Int32.Parse(squeezedStr.Substring(i + 1, 1));
                    var newWord = words[key] + words[nextKey].Substring(0, 1);
                    words.Add(counter, newWord);
                    counter++;
                }
            }
            return result;
        }

        static void Main(string[] args)
        {
            string path = @"C:\Users\Aser_Pc\Desktop\Си\Homework\SecondSemester\Homework2\LWZ\Text.txt";
            System.IO.StreamReader file = new System.IO.StreamReader(path);
            string input = file.ReadLine();
            file.Close();
            string squeezedInput = SqueezeString(input);
            string alphabet = GetAlphabetString(input);
            string oldString = Decompress(squeezedInput, alphabet);
        }
    }
}
