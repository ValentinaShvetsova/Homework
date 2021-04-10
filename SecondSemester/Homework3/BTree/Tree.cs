using System;
using System.Collections.Generic;
using System.Text;

namespace BTree
{
    public class Tree
    {
        private readonly int treeDegree;
        private Node root;

        /// <summary>
        /// Initializes new b-tree
        /// </summary>
        /// <param name="treeDegree">maximum amount of cells in node</param>
        public Tree(int treeDegree)
        {
            this.treeDegree = treeDegree;
            root = new Node(treeDegree, null);
        }
        private class Node
        {
            private int currentSize;
            private Data[] values;
            private Node[] children;
            private bool IsLeaf;
            private Node parent;

            /// <summary>
            /// Initializes new Node in tree
            /// </summary>
            /// <param name="treeDegree">maximum amount of cells in node</param>
            /// <param name="parent">previous node</param>
            public Node(int treeDegree, Node parent)
            {
                values = new Data[2 * treeDegree - 1];
                children = new Node[2 * treeDegree];
                currentSize = 0;
                IsLeaf = true;
                this.parent = parent;
            }
        }

        private class Data
        {
            public string Key { get; set; }
            public string Value { get; set; }

            /// <summary>
            /// Initializes new key-value pare for node
            /// </summary>
            public Data(string key, string value)
            {
                Key = key;
                Value = value;
            }

            /// <summary>
            /// Returns new Data with value and key of current cell
            /// </summary>
            /// <returns></returns>
            public Data Copy()
            {
                return new Data(Key, Value);
            }
        }
    }
}
