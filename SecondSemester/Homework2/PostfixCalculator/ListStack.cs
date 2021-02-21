using System;
using System.Collections.Generic;
using System.Text;

namespace PostfixCalculator
{
    public class ListStack : IStack
    {
        private StackElement top;

        private class StackElement
        {
            public double Value;
            public StackElement Next;

            public StackElement(double value, StackElement next)
            {
                Value = value;
                Next = next;
            }
        }

        public bool IsEmpty()
        {
            return top == null;
        }

        public void Push(double value)
        {
            top = new StackElement(value, top);
        }

        public double Pop()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException();
            }
            double value = top.Value;
            top = top.Next;
            return value;
        }

        public void Delete()
        {
            top = null;
        }
    }
}
