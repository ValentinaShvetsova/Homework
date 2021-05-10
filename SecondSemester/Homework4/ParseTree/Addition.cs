using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    /// <summary>
    /// Operation af addition
    /// </summary>
    public class Addition : Operation
    {
        /// <summary>
        /// Calculates subtree
        /// </summary>
        public override int Calculate() => LeftChild.Calculate() + RightChild.Calculate();

        /// <summary>
        /// Prints sons and operation
        /// </summary>
        public override void Print()
        {
            Console.Write("+ ");
            base.Print();
        }
    }
}
