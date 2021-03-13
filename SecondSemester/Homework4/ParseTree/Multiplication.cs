using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    public class Multiplication : Operation
    {
        public override int Calculate() => LeftChild.Calculate() * RightChild.Calculate();

        public override void Print()
        {
            Console.Write("* ");
            base.Print();
        }
    }
}
