using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    /// <summary>
    /// Node in the parse tree
    /// </summary>
    public interface INode
    {
        /// <summary>
        /// Prints the node and subtree
        /// </summary>
        public void Print();

        /// <summary>
        /// Prunts the result of subtrees calculation
        /// </summary>
        /// <returns></returns>
        public int Calculate();
    }
}
