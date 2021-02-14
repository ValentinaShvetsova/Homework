using System;

namespace BubbleSort
{
    class Program
    {
        public static int[] BubbleSort (int[] array)
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
            return array;
        }

        public static bool Test1()
        {
            var array = new int[] { 13, 7, 5, 1, 27 };
            var sortedArray = new int[] { 1, 5, 7, 13, 27 };
            int[] result = BubbleSort(array);
            for (int i = 0; i < array.Length; ++i)
            {
                if (sortedArray[i] != result[i])
                {
                    return false;
                }
            }
            return true;
        }

        public static bool Test2()
        {
            var array = new int[] { 1 };
            int[] result = BubbleSort(array);
            return result[0] == 1;
            return true;
        }

        public static bool Test3()
        {
            var array = new int[] { 1, 1, 1, 1, 1, 1 };
            int[] result = BubbleSort(array);
            for (int i = 0; i < result.Length; ++i)
            {
                if (result[i] != 1)
                {
                    return false;
                }
            }
            return true;
        }

        static void Main(string[] args)
        {
            if (!Test1() || !Test2() || !Test3())
            {
                Console.WriteLine("Tests failed ");
                return;
            }
            var array = new int[] { 1, 3, 5, 7, 9 };
            int[] sortedArray = BubbleSort(array);
            for(int i = 0; i < array.Length; ++i)
            {
                Console.WriteLine(array[i]);
            }
        }
    }
}
