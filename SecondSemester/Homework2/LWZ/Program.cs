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

        /// <summary>
        /// This function returns squeezed by LWZ algorithm string
        /// </summary>
        /// <returns></returns>
        public static void CompressString(string path)
        {
            var file = new System.IO.StreamReader(path);
            string input = file.ReadLine();
            file.Close();
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
            WriteInFile(path, result);
        }

        private static void WriteInFile(string pathToFile, string result)
        {
            string resultPath = pathToFile + ".zipped";
            using (StreamWriter sw = new StreamWriter(resultPath, false, System.Text.Encoding.Default))
            {
                sw.WriteLine(result);
            }
        }

        /// <summary>
        /// This function returns decompessed by LWZ algorithm string, but requires the alphabet of the old string
        /// </summary>
        /// <returns></returns>
        public static void Decompress(string path, string alphabet)
        {
            var file = new System.IO.StreamReader(path);
            string squeezedStr = file.ReadLine();
            file.Close();
            var words = new Dictionary<int, string>();
            int counter = 0;
            string result = "";
            for (int i = 0; i < alphabet.Length; i++)
            {
                words.Add(counter, alphabet.Substring(i, 1));
                counter++;
            }
            for (int i = 0; i < squeezedStr.Length; i++)
            {
                int key = Int32.Parse(squeezedStr.Substring(i,1));
                result += words[key];
                if (i != squeezedStr.Length - 1)
                {
                    var nextKey = Int32.Parse(squeezedStr.Substring(i + 1, 1));
                    var newWord = words[key] + words[nextKey].Substring(0, 1);
                    words.Add(counter, newWord);
                    counter++;
                }
            }
            writeInFileDecompress(path, result);
        }

        private static void writeInFileDecompress(string path, string oldString)
        {
            var resultPath = path.Substring(0, path.Length - 7);
            using (StreamWriter sw = new StreamWriter(resultPath, false, System.Text.Encoding.Default))
            {
                sw.WriteLine(oldString);
            }
        }

        static void Main(string[] args)
        {
            string pathToString = @"C:\Users\Aser_Pc\Desktop\Си\Homework\SecondSemester\Homework2\LWZ\Text.txt";
            string pathToCompressedString = pathToString + ".zipped";
            System.IO.StreamReader file = new System.IO.StreamReader(pathToString);
            string str = file.ReadLine();
            file.Close();
            string alphabet = GetAlphabetString(str);
            Console.WriteLine("Choose: 1 --> compress string in file");
            Console.WriteLine("Choose: 2 --> decompress string");
            string chosenOption = Console.ReadLine();
            int option = Convert.ToInt32(chosenOption);
            if(option == 1)
            {
                CompressString(pathToString);
            }
            else if (option == 2)
            {
                Decompress(pathToCompressedString, alphabet);
            }
            else
            {
                Console.WriteLine("invalid input");
            }
        }
    }
}
