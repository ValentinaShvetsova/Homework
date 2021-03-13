using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    public class Operand : INode
    {
        public int Value { get; set; }

        public int Calculate() => Value;

        public void Print()
        {
            Console.Write($"{Value} ");
        }
    }
}
