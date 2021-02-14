using System;

namespace BubbleSort
{
    class Program
    {
        public static int[] bubbleSort (int[] array)
        {
            for (int i = 0; i < array.Length - 1; ++i)
            {
                for (int j = 0; j < array.Length - i - 1; ++j)
                {
                    if (array[j+1] < array[j])
                    {
                        int temp = array[j + 1];
                        array[j + 1] = array[j];
                        array[j] = temp;
                    }
                }
            }
            return array;
        }

        public static bool test1()
        {
            int[] array = new int[] { 13, 7, 5, 1, 27 };
            int[] sortedArray = new int[] { 1, 5, 7, 13, 27 };
            int[] result = bubbleSort(array);
            for (int i = 0; i < array.Length; ++i)
            {
                if (sortedArray[i] != result[i])
                {
                    return false;
                }
            }
            return true;
        }

        public static bool test2()
        {
            int[] array = new int[] { 1 };
            int[] result = bubbleSort(array);
            if (result[0] != 1)
            {
                return false;
            }
            return true;
        }

        public static bool test3()
        {
            int[] array = new int[] { 1, 1, 1, 1, 1, 1 };
            int[] result = bubbleSort(array);
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
            if (!test1() || !test2() || !test3())
            {
                return;
            }
            int[] array = new int[] { 1, 3, 5, 7, 9 };
            int[] sortedArray = bubbleSort(array);
            for(int i = 0; i < array.Length; ++i)
            {
                Console.WriteLine(array[i]);
            }
        }
    }
}
