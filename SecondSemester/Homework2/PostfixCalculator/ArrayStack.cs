using System;
using System.Collections.Generic;
using System.Text;

namespace PostfixCalculator
{
    public class ArrayStack : IStack
    {
        private double[] stackElements;
        private int counter;

        public ArrayStack()
        {
            stackElements = new double[10];
        }

        public bool IsEmpty()
        {
            return counter == 0;
        }

        public void Push(double value)
        {
            if (counter == stackElements.Length)
            {
                Array.Resize(ref stackElements, stackElements.Length * 2);
            }
            stackElements[counter] = value;
            counter++;
        }

        public double Pop()
        {
            if (IsEmpty())
            {
                throw new InvalidOperationException();
            }
            counter--;
            double value = stackElements[counter];
            return value;
        }

        public void Clear()
        {
            stackElements = new double[10];
            counter = 0;
        }
    }
}
