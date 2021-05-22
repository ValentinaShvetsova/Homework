using System;
using System.Collections.Generic;
using System.Text;

namespace BTree
{
    /// <summary>
    /// Realisation of b-tree structure with nodes and maximum degree
    /// </summary>
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
            private Node[] children;
            private bool isLeaf;
            private Node parent;

            public int currentSize { get; set; }
            public Data[] values { get; set; }

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
                isLeaf = true;
                this.parent = parent;
            }

            private Data FindByKey(string key)
            {
                if (isLeaf)
                {
                    for (int i = 0; i < currentSize; ++i)
                    {
                        if (key.CompareTo(values[i].Key) == 0)
                        {
                            return values[i];
                        }
                    }
                    return null;
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
                return null;
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
                    for (int i = 0; i < treeDegree; i++)
                    {
                        if (i != treeDegree - 1)
                        {
                            left.values[i] = values[i].Copy();
                        }
                        if (children[i] != null)
                        {
                            children[i].parent = left;
                            left.isLeaf = false;
                        }
                        left.children[i] = children[i];
                    }
                    left.currentSize = treeDegree - 1;

                    var right = new Node(treeDegree, this);
                    for (int i = 0; i < treeDegree; i++)
                    {
                        if (i != treeDegree - 1)
                        {
                            right.values[i] = values[treeDegree + i].Copy();
                        }
                        if (children[treeDegree + i] != null)
                        {
                            children[treeDegree + i].parent = right;
                            right.isLeaf = false;
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
                    isLeaf = false;
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

            /// <summary>
            /// Inserts new cell in the node or lower
            /// </summary>
            public void InsertValue(string key, string value, int degree)
            {
                if (isLeaf)
                {
                    if (currentSize == 0)
                    {
                        InsertCell(0, new Data(key, value));
                        return;
                    }
                    for (int i = 0; i < currentSize; i++)
                    {
                        if (key.CompareTo(values[i].Key) == 0)
                        {
                            values[i].Value = value;
                            return;
                        }
                        else if (key.CompareTo(values[i].Key) == -1)
                        {
                            InsertCell(i, new Data(key, value));
                            TrySplit(degree);
                            return;
                        }
                    }
                    InsertCell(currentSize, new Data(key, value));
                    TrySplit(degree);
                    return;
                }
                if (key.CompareTo(values[0].Key) == -1)
                {
                    children[0].InsertValue(key, value, degree);
                    return;
                }
                if (key.CompareTo(values[currentSize - 1].Key) == -1)
                {
                    children[currentSize].InsertValue(key, value, degree);
                    return;
                }
                for (int i = 0; i < currentSize; i++)
                {
                    if (key.CompareTo(values[i].Key) == 1 && key.CompareTo(values[i + 1].Key) == -1)
                    {
                        children[i + 1].InsertValue(key, value, degree);
                        return;
                    }
                }
            }

            /// <summary>
            /// Checks whether the key is in the node or lower
            /// </summary>
            public (Data, bool) Exists(string key)
            {
                Data answer = FindByKey(key);
                if(answer != null)
                {
                    return (FindByKey(key), true);
                }
                else
                {
                    return (null, false);
                }
            }

            /// <summary>
            /// Deletes value by key
            /// </summary>
            public void DeleteValueByKey(string key)
            {
                for(int i = 0; i < currentSize; i++)
                {
                    if(key.CompareTo(values[i].Key) == 0)
                    {
                        if (isLeaf)
                        {
                            for (int j = i; j < currentSize - 1; j++)
                            {
                                values[j] = values[j + 1];
                            }
                            currentSize--;
                        }
                        else
                        {
                            if (children[i].currentSize >= 1)
                            {
                                string keyTmp = values[i].Key;
                                string valueTmp = values[i].Value;
                                values[i].Key = children[i].values[children[i].currentSize - 1].Key;
                                values[i].Value = children[i].values[children[i].currentSize - 1].Value;
                                children[i].values[children[i].currentSize - 1].Key = keyTmp;
                                children[i].values[children[i].currentSize - 1].Value = valueTmp;
                                children[i].DeleteValueByKey(key);
                            }
                        }
                        return;
                    }
                }

                if (isLeaf)
                {
                    throw new ArgumentOutOfRangeException("Value have not been found");
                }

                if (key.CompareTo(values[0].Key) == -1)
                {
                    children[0].DeleteValueByKey(key);
                    return;
                } 
                else if (key.CompareTo(values[currentSize - 1].Key) == 1)
                {
                    children[currentSize].DeleteValueByKey(key);
                    return;
                }

                for (int i = 0; i < currentSize - 1; i++)
                {
                    if (key.CompareTo(values[i].Key) == 1 && key.CompareTo(values[i + 1].Key) == -1)
                    {
                        children[i + 1].DeleteValueByKey(key);
                        return;
                    }
                }
            }
        }

        /// <summary>
        /// Inseerts value in the tree by key
        /// </summary>
        public void AddValue(string key, string value)
           => root.InsertValue(key, value, treeDegree);

        /// <summary>
        /// Finds value by key
        /// </summary>
        public string FindValue(string key)
        {
            (Data data, bool exist) = root.Exists(key);
            string answer = exist ? data.Value : null;
            return answer;
        }

        /// <summary>
        /// Deletes value by key
        /// </summary>
        public void DeleteValue(string key)
        {
            root.DeleteValueByKey(key);
        }
    }
}
