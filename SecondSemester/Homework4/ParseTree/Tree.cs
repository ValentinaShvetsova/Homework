using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    public class Tree
    {
        private INode root;

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
                } else if(symbols[position] == "-")
                {
                    newNode = new Subtraction();
                } else if(symbols[position] == "*")
                {
                    newNode = new Multiplication();
                } else if(symbols[position] == "/")
                {
                    newNode = new Division();
                }

                newNode.LeftChild = NewNode();
                newNode.RightChild = NewNode();
                return newNode;
            }
        }

        public void Print() => root?.Print();

        public int Calculate() => root.Calculate();
    }
}
