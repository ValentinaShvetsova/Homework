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

        public int Find(int currentVertex)
        {
            if (currentVertex == arraySets[currentVertex])
            {
                return currentVertex;
            }

            return Find(arraySets[currentVertex]);
        }

        public bool IsOnlySet()
        {
            for (int i = 0; i < arraySets.Length; i++)
            {
                if (Find(0) != Find(i))
                {
                    return false;
                }
            }

            return true;
        }

        public void Unite(int firstVertex, int secondVertex)
        {
            int firstElement = Find(firstVertex);
            int secondElement = Find(secondVertex);

            if (firstElement != secondElement)
            {
                arraySets[secondElement] = firstElement;
            }
        }
    }
}
