using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    /// <summary>
    /// Parse tree
    /// </summary>
    public class Tree
    {
        private INode root;

        /// <summary>
        /// Sets new tree
        /// </summary>
        public Tree(string input)
        {
            Build(input);
        }

        private void Build(string input)
        {
            var symbols = input.Split(new char[] { ' ', '(', ')' }, StringSplitOptions.RemoveEmptyEntries);
            var position = -1;
            root = NewNode();

            INode NewNode()
            {
                position++;
                if (char.IsDigit(symbols[position], 0))
                {
                    return new Operand() { Value = int.Parse(symbols[position]) };
                }

                Operation newNode = null;
                if (symbols[position] == "+")
                {
                    newNode = new Addition();
                } 
                else if(symbols[position] == "-")
                {
                    newNode = new Subtraction();
                } 
                else if(symbols[position] == "*")
                {
                    newNode = new Multiplication();
                } 
                else if(symbols[position] == "/")
                {
                    newNode = new Division();
                }

                newNode.LeftChild = NewNode();
                newNode.RightChild = NewNode();
                return newNode;
            }
        }

        /// <summary>
        /// Prints tree
        /// </summary>
        public void Print() => root?.Print();

        /// <summary>
        /// Calculates expression by tree
        /// </summary>
        public int Calculate() => root.Calculate();
    }
}
