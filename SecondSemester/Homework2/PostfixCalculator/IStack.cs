using System;
using System.Collections.Generic;
using System.Text;

namespace PostfixCalculator
{
    interface IStack
    {
        bool IsEmpty();

        void Push(double value);

        double Pop();

        void Delete();
    }
}
