using System;
using System.Collections.Generic;
using System.Text;

namespace SparceVector
{
    public class LinkedList
    {
        private Node head;

        private class Node
        {
            public Node(int position, int value, Node next)
            {
                this.position = position;
                this.value = value;
                this.next = next;
            }

            public int position;
            public int value;
            public Node next;
        }

        public int Size { get; private set; }

        public bool IsEmpty { get; private set; } = true;

        public bool AddValue(int position, int value, int number)
        {
            if (number < 0 || number > Size)
            {
                return false;
            }

            Node previous = null;
            var current = head;
            for (var i = 0; i < number; ++i)
            {
                previous = current;
                current = current.next;
            }

            if (previous == null)
            {
                head = new Node(position, value, head);
            }
            else
            {
                previous.next = new Node(position, value, current);
            }
            Size++;
            IsEmpty = false;
            return true;
        }

        public bool DeleteValue(int position)
        {
            if (position < 0 || position > Size - 1)
            {
                return false;
            }

            Node previous = null;
            var current = head;
            for (var i = 0; i < position; ++i)
            {
                previous = current;
                current = current.next;
            }

            if (previous == null)
            {
                head = current.next;
            }
            else
            {
                previous.next = current.next;
            }
            Size--;
            IsEmpty = Size == 0;
            return true;
        }

        public (bool, int, int) GetValue(int number)
        {
            if (number < 0 || number > Size - 1)
            {
                return (false, 0, 0);
            }

            var current = head;
            for (var i = 0; i < number; ++i)
            {
                current = current.next;
            }
            return (true, current.value, current.position);
        }

        public (bool, int) GetValueByPosition (int position)
        {
            if (position < 0)
            {
                return (false, 0);
            }
            var current = head;
            while ((current.position < position) && (current != null))
            {
                current = current.next;
            }

            if(current.position == position)
            {
                return (true, current.value);
            }
            else
            {
                return (false, 0);
            }
        }

        public bool SetValue(int value, int position, int number)
        {
            if (number < 0 || number > Size - 1)
            {
                return false;
            }

            var current = head;
            for (var i = 0; i < number; ++i)
            {
                current = current.next;
            }
            current.value = value;
            current.position = position;
            return true;
        }

        public void Print()
        {
            var current = head;
            for (var i = 0; i < Size; ++i)
            {
                Console.Write($"{current.value} ");
                current = current.next;
            }
        }

        public void Clear()
        {
            head = null;
            Size = 0;
            IsEmpty = true;
        }
    }
}
