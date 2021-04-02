using System;
using System.Collections.Generic;
using System.Text;

namespace SparceVector
{
    public class VectorWithNormalList
    {
        /// <summary>
        /// Vector that contains pairs (position, value)
        /// </summary>
        List<(int, int)> vector;

        /// <summary>
        /// Adds to vector new value if it's not a zero
        /// </summary>
        public void AddToVector(int value)
        {
            int position = vector[vector.Count - 1].Item1;
            vector.Add((position, value));
 
        }

        /// <summary>
        /// Creates a new vetctor from array
        /// </summary>
        public void MakeSparseVector(int[] array)
        {
            var newVector = new List<(int, int)>();
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i] != 0)
                {
                    newVector.Add((i, array[i]));
                }
            }
            vector = newVector;
        }

        /// <summary>
        /// Checks whether the list is empty or not
        /// </summary>
        public bool Empty
            => vector.Count == 0;
    }
}
