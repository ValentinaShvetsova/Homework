using System;

namespace BubbleSort
{
    class Program
    {
        public static void BubbleSort(int[] array)
        {
            for (int i = 0; i < array.Length - 1; ++i)
            {
                for (int j = 0; j < array.Length - i - 1; ++j)
                {
                    if (array[j + 1] < array[j])
                    {
                        int temp = array[j + 1];
                        array[j + 1] = array[j];
                        array[j] = temp;
                    }
                }
            }
        }

        public static bool Test1()
        {
            var array = new int[] { 13, 7, 5, 1, 27 };
            var sortedArray = new int[] { 1, 5, 7, 13, 27 };
            BubbleSort(array);
            for (int i = 0; i < array.Length; ++i)
            {
                if (sortedArray[i] != array[i])
                {
                    return false;
                }
            }
            return true;
        }

        public static bool Test2()
        {
            var array = new int[] { 1, 1, 1, 1, 1, 1 };
            BubbleSort(array);
            for (int i = 0; i < array.Length; ++i)
            {
                if (array[i] != 1)
                {
                    return false;
                }
            }
            return true;
        }

        static void Main(string[] args)
        {
            if (!Test1() || !Test2())
            {
                Console.WriteLine("Tests failed ");
                return;
            }
            var array = new int[] { 1, 3, 5, 7, 9 };
            BubbleSort(array);
            for(int i = 0; i < array.Length; ++i)
            {
                Console.WriteLine(array[i]);
            }
        }
    }
}
