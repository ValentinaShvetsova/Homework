using System;
using System.Collections.Generic;
using System.Text;

namespace Test1
{
    public class PriorityQueue<TValue>
    {
        private int size = 0;

        private Node<TValue> head;
        private class Node<TValue>
        {
            public TValue Value { get; set; }
            public int Priority { get; set; }
            public Node<TValue> Next { get; set; }

            /// <summary>
            /// Initialize new Node in queue
            /// </summary>
            /// <param name="value">nodes value</param>
            /// <param name="priority">nodes priority</param>
            /// <param name="next">next queue element</param>
            public Node(TValue value, int priority, Node<TValue> next)
            {
                Value = value;
                Priority = priority;
                Next = next;
            }
        }

        /// <summary>
        /// Checks whether the queue is empty or not.
        /// </summary>
        public bool IsEmpty
            => size == 0;

        /// <summary>
        /// Add new element in the queue based on its priority
        /// </summary>
        /// <param name="value"></param>
        /// <param name="priority"></param>
        public void Enqueue(TValue value, int priority)
        {
            size++;
            if (size == 1 || head.Priority < priority)
            {
                head = new Node<TValue>(value, priority, head);
                return;
            }
            var currentElement = head;
            while(currentElement.Next != null || currentElement.Next.Priority >= priority)
            {
                currentElement = currentElement.Next;
            }
            var newElement = new Node<TValue>(value, priority, currentElement.Next);
            currentElement.Next = newElement;
        }

        /// <summary>
        /// Dequeues the first element in queue, returns its value
        /// </summary>
        /// <returns></returns>
        public TValue Dequeue()
        {
            if (IsEmpty)
            {
                throw new EmtyQueueException();
            }
            size--;
            var firstInQueue = head.Value;
            head = head.Next;
            return firstInQueue;
        }
    }
}
