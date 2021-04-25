using System;
using System.Collections.Generic;
using System.Text;

namespace Routers
{
    public class Set
    {
        private int[] arraySets;

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="countsVertices">Number of vertices in the graph</param>
        public Set(int countsVertices)
        {
            arraySets = new int[countsVertices];

            for (int i = 0; i < countsVertices; i++)
            {
                arraySets[i] = i;
            }
        }

        /// <summary>
        /// Returns the minimal element in the set
        /// </summary>
        /// <param name="currentVertex"></param>
        /// <returns></returns>
        public int SearchForMinimum(int currentVertex)
        {
            if (currentVertex == arraySets[currentVertex])
            {
                return currentVertex;
            }

            return SearchForMinimum(arraySets[currentVertex]);
        }

        /// <summary>
        /// Unite sets
        /// </summary>
        /// <param name="firstVertex"></param>
        /// <param name="secondVertex"></param>
        public void Unite(int firstVertex, int secondVertex)
        {
            int firstElement = SearchForMinimum(firstVertex);
            int secondElement = SearchForMinimum(secondVertex);

            if (firstElement != secondElement)
            {
                arraySets[secondElement] = firstElement;
            }
        }
    }
}
