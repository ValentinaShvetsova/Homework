using System;
using System.Collections.Generic;
using System.Text;

namespace Test1
{
    public class PriorityQueue<T>
    {
        private class Node<T>
        {
            public T Value { get; set; }
            public int Priority { get; set; }
            public Node<T> Next { get; set; }

            public Node(T value, int priority, Node<T> next)
            {
                Value = value;
                Priority = priority;
                Next = next;
            }

        }
    }
}
