using System;
using System.Collections.Generic;
using System.Text;

namespace UniqueList
{
    public class List
    {
        /// <summary>
        /// The list of integer values 
        /// </summary>
        private class Node
        {
            /// <summary>
            /// Element of the list, contains value and pointer to the next node
            /// </summary>
            public Node(int value, Node next)
            {
                Value = value;
                Next = next;
            }

            public int Value { get; set; }
            public Node Next { get; set; }
        }

        private Node head;

        /// <summary>
        /// Amount of elements currently in the list
        /// </summary>
        public int Size { get; private set; }

        /// <summary>
        /// Returns true if list contains something
        /// </summary>
        public bool IsEmpty 
            => head == null;

        /// <summary>
        /// Adds element in direct position
        /// </summary>
        public void AddValue(int value, int position)
        {
            if (position < 0 || position > Size)
            {
                throw new InvalidPositionException();
            }

            Node previous = null;
            var current = head;
            for (var i = 0; i < position; ++i)
            {
                previous = current;
                current = current.Next;
            }

            if (previous == null)
            {
                head = new Node(value, head);
            }
            else
            {
                previous.Next = new Node(value, current);
            }
            Size++;
        }

        /// <summary>
        /// Deletes value from list
        /// </summary>
        public void DeleteValue(int position)
        {
            if (position < 0 || position > Size - 1)
            {
                throw new InvalidPositionException();
            }

            Node previous = null;
            var current = head;
            for (var i = 0; i < position; ++i)
            {
                previous = current;
                current = current.Next;
            }

            if (previous == null)
            {
                head = current.Next;
            }
            else
            {
                previous.Next = current.Next;
            }
            Size--;
        }

        /// <summary>
        /// Returns true if list contains this value
        /// </summary>
        /// <param name="value">Value to find</param>
        /// <returns></returns>
        public bool Contains(int value)
        {
            var current = head;
            for (var i = 0; i < Size; ++i)
            {
                if (current.Value == value)
                {
                    return true;
                }
                current = current.Next;
            }
            return false;
        }

        /// <summary>
        /// Returns value from direct position
        /// </summary>
        public int GetValue(int position)
        {
            if (position < 0 || position > Size - 1)
            {
                throw new InvalidPositionException();
            }

            var current = head;
            for (var i = 0; i < position; ++i)
            {
                current = current.Next;
            }
            return current.Value;
        }

        /// <summary>
        /// Sets new value without adding new element in list
        /// </summary>
        /// <param name="value">Value to set</param>
        /// <param name="position">Position of node, which needs change of value</param>
        public void SetValue(int value, int position)
        {
            if (position < 0 || position > Size - 1)
            {
                throw new InvalidPositionException();
            }

            var current = head;
            for (var i = 0; i < position; ++i)
            {
                current = current.Next;
            }
            current.Value = value;
        }

        /// <summary>
        /// Returns position of element by value
        /// </summary>
        /// <param name="value">Value, which position needs to be found</param>
        /// <returns></returns>
        public int GetPosition(int value)
        {
            var current = head;
            for (var i = 0; i < Size; ++i)
            {
                if (current.Value == value)
                {
                    return i;
                }
                current = current.Next;
            }
            return -1;
        }
    }
}
