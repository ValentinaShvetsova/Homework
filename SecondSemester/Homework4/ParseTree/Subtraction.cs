using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    /// <summary>
    /// Operation of the subtraction
    /// </summary>
    public class Subtraction : Operation
    {
        /// <summary>
        /// Calculates the subtree
        /// </summary>
        /// <returns></returns>
        public override int Calculate() => LeftChild.Calculate() - RightChild.Calculate();

        /// <summary>
        /// Prints sons and operation
        /// </summary>
        public override void Print()
        {
            Console.Write("- ");
            base.Print();
        }
    }
}
