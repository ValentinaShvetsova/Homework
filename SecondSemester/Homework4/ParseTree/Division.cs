using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    /// <summary>
    /// Operation of the division
    /// </summary>
    public class Division : Operation
    {
        /// <summary>
        /// Calculates the subtree
        /// </summary>
        public override int Calculate() => LeftChild.Calculate() / RightChild.Calculate();

        /// <summary>
        /// Prints sons and operation
        /// </summary>
        public override void Print()
        {
            Console.Write("/ ");
            base.Print();
        }
    }
}
