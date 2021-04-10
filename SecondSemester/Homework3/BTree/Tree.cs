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

            private Data FindByKey(string key)
            {
                if (IsLeaf)
                {
                    for(int i = 0; i < currentSize; ++i)
                    {
                        if (key.CompareTo(values[i].Key) == 0)
                        {
                            return values[i];
                        }
                    }
                    throw new ArgumentOutOfRangeException("Value have not been found");
                }

                for (int i = 0; i < currentSize; i++)
                {
                    if (key.CompareTo(values[i].Key) == 0)
                    {
                        return values[i];
                    } 
                    else if (key.CompareTo(values[i].Key) == -1)
                    {
                        return children[i].FindByKey(key);
                    }
                }
                if (key.CompareTo(values[currentSize - 1].Key) == 1)
                {
                    return children[currentSize].FindByKey(key);
                }
                throw new ArgumentOutOfRangeException("Value have not been found");
            }

            private void InsertCell(int index, Data data)
            {
                values[currentSize] = new Data("", "");
                for (int i = currentSize - 1; i >= index; i--)
                {
                    values[i + 1].Key = values[i].Key;
                    values[i + 1].Value = values[i].Value;
                }
                values[index] = data;
                currentSize++;
            }

            private void TrySplit(int treeDegree)
            {
                if (currentSize == 2 * treeDegree - 1)
                {
                    var left = new Node(treeDegree, this);
                    for(int i = 0; i < treeDegree; i++)
                    {
                        if (i != treeDegree - 1)
                        {
                            left.values[i] = values[i].Copy();
                        }
                        if (children[i] != null)
                        {
                            children[i].parent = left;
                            left.IsLeaf = false;
                        }
                        left.children[i] = children[i];
                    }
                    left.currentSize = treeDegree - 1;

                    var right = new Node(treeDegree, this);
                    for(int i = 0; i < treeDegree; i++)
                    {
                        if (i != treeDegree - 1)
                        {
                            right.values[i] = values[treeDegree + i].Copy();
                        }
                        if (children[treeDegree + i] != null)
                        {
                            children[treeDegree + i].parent = right;
                            right.IsLeaf = false;
                        }
                        right.children[i] = children[treeDegree + i];
                    }
                    right.currentSize = treeDegree - 1;

                    Data middle = values[(2 * treeDegree - 1) / 2].Copy();
                    if (parent == null)
                    {
                        Array.Clear(values, 0, values.Length);
                        Array.Clear(children, 0, children.Length);
                        currentSize = 1;
                        values[0] = middle;
                        children[0] = left;
                        children[1] = right;
                        return;
                    }
                    IsLeaf = false;
                    left.parent = parent;
                    right.parent = parent;

                    for (int i = 0; i < parent.currentSize; i++)
                    {
                        if (middle.Key.CompareTo(parent.values[i].Key) == -1)
                        {
                            for (int j = parent.currentSize - 1; j >= i; j--)
                            {
                                parent.values[j + 1] = parent.values[j].Copy();
                            }
                            parent.values[i].Key = middle.Key;
                            parent.values[i].Value = middle.Value;

                            for (int j = parent.currentSize + 1; j > i; j--)
                            {
                                parent.children[j] = parent.children[j - 1];
                            }
                            parent.children[i] = left;
                            parent.children[i + 1] = right;
                            parent.currentSize++;
                            parent.TrySplit(treeDegree);
                            return;
                        }
                    }
                    parent.children[parent.currentSize] = left;
                    parent.children[parent.currentSize + 1] = right;
                    parent.values[parent.currentSize] = middle;
                    parent.currentSize++;
                    parent.TrySplit(treeDegree);
                    return;
                }
            }
        }
    }
}
