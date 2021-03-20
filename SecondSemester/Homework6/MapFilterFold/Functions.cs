using System;
using System.Collections.Generic;
using System.Text;

namespace MapFilterFold
{
    class Functions
    {
        public static List<int> Map(List<int> list, Func<int, int> func)
        {
            var newList = new List<int>();
            foreach(var element in list)
            {
                newList.Add(func(element));
            }
            return newList;
        }

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
