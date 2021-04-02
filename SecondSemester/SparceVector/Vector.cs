using System;
using System.Collections.Generic;
using System.Text;

namespace SparceVector
{
    public class Vector
    {
        public LinkedList vector;
        public LinkedList InitializeNewVector(int[] array)
        {
            var newList = new LinkedList();
            int position = 0;
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] != 0)
                {
                    newList.AddValue(i, array[i], position);
                    position++;
                }
            }
            return newList;
        }
    }
}
