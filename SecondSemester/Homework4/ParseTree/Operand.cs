using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    /// <summary>
    /// Leaf in the parse tree
    /// </summary>
    public class Operand : INode
    {
        public int Value { get; set; }

        /// <summary>
        /// Calculates operand
        /// </summary>
        public int Calculate() => Value;

        /// <summary>
        /// Prints the value of the operand
        /// </summary>
        public void Print()
        {
            Console.Write($"{Value} ");
        }
    }
}
