using System;
using System.Collections.Generic;
using System.Text;

namespace MapFilterFold
{
    /// <summary>
    /// Functions for list of integers
    /// </summary>
    public class Functions
    {
        /// <summary>
        /// Apply function to each element of the list, creates and returns new list with those values.
        /// </summary>
        /// <param name="list">Input list</param>
        /// <param name="func">Function that changes values in list</param>
        public static List<int> Map(List<int> list, Func<int, int> func)
        {
            var newList = new List<int>();

            foreach(var element in list)
            {
                newList.Add(func(element));
            }

            return newList;
        }

        /// <summary>
        /// Creates and returns list with values, which have been approved by transmitted function
        /// </summary>
        /// <param name="list">Input list</param>
        /// <param name="func">Function that checks each value in the list</param>
        public static List<int> Filter(List<int> list, Func<int, bool> func)
        {
            var newList = new List<int>();

            foreach (var element in list)
            {
                if (func(element))
                {
                    newList.Add(element);
                }
            }

            return newList;
        }

        /// <summary>
        /// Returns accumulated integer, counted with transmitted function
        /// </summary>
        /// <param name="list">Input list</param>
        /// <param name="initial">Start value</param>
        /// <param name="func">Function that returns the next accumulated value for the current value and element</param>
        public static int Fold(List<int> list, int initial, Func<int, int, int> func)
        {
            var accumulated = initial;

            foreach (var elem in list)
            {
                accumulated = func(accumulated, elem);
            }

            return accumulated;
        }
    }
}
