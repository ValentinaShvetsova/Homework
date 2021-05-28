using System;
using System.Collections.Generic;

namespace BubbleSortGeneric
{
    public class Program
    {
        /// <summary>
        /// Sort different types of data
        /// </summary>
        /// <typeparam name="T">Type of data in list</typeparam>
        /// <param name="list">List, that is needed to be sorted</param>
        /// <param name="comparer">Comparer for a particular type of data</param>
        public static void BubbleSort<T>(IList<T> list, IComparer<T> comparer)
        {
            for (var i = 0; i < list.Count; ++i)
            {
                for (var j = list.Count - 1; j > i; --j)
                {
                    if (comparer.Compare(list[j], list[j - 1]) < 0)
                    {
                        (list[j], list[j - 1]) = (list[j - 1], list[j]);
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
