using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    /// <summary>
    /// Node in the parse tree
    /// </summary>
    public abstract class Operation : INode
    {
        public INode LeftChild { get; set; }

        public INode RightChild { get; set; }

        /// <summary>
        /// Calculates the subtree
        /// </summary>
        public abstract int Calculate();

        /// <summary>
        /// Prints subtree
        /// </summary>
        public virtual void Print()
        {
            LeftChild?.Print();
            RightChild?.Print();
        }
    }
}
