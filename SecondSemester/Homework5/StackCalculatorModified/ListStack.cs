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
            public double _value;
            public StackElement _next;

            public StackElement(double value, StackElement next)
            {
                _value = value;
                _next = next;
            }
        }

        public bool IsEmpty()
             => top == null;

        public void Push(double value)
            => top = new StackElement(value, top);

        public double Pop()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException();
            }
            double value = top._value;
            top = top._next;
            return value;
        }

        public void Clear()
        {
            top = null;
        }
    }
}
