using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Text;

namespace BTree
{
    /// <summary>
    /// Realisation of b-tree structure with nodes and maximum degree
    /// </summary>
    public class Tree : IDictionary<string, string>
    {
        private readonly int treeDegree;
        private Node root;
        public int version;

        public ICollection<string> Values
        {
            get
            {
                var values = new List<string>();
                foreach (var data in new BTreeEnumerator(this).Data)
                {
                    values.Add(data.Value);
                }
                return values;
            }
        }

        public ICollection<string> Keys
        {
            get
            {
                var keys = new List<string>();
                foreach (var data in new BTreeEnumerator(this).Data)
                {
                    keys.Add(data.Key);
                }
                return keys;
            }
        }

        /// <summary>
        /// Initializes new b-tree
        /// </summary>
        /// <param name="treeDegree">maximum amount of cells in node</param>
        public Tree(int treeDegree)
        {
            this.treeDegree = treeDegree;
            root = new Node(treeDegree, null);
        }

        private class BTreeEnumerator : IEnumerator<KeyValuePair<string, string>>
        {
            public Data[] Data { get; set; }

            private int index;
            private Tree tree;
            private int currentVersion;

            public BTreeEnumerator(Tree tree)
            {
                index = -1;
                this.tree = tree;
                currentVersion = tree.version;
                Data = GetDataFromBNode(tree.root).ToArray();
            }

            public KeyValuePair<string, string> Current
                => new KeyValuePair<string, string>(Data[index].Key, Data[index].Value);

            object IEnumerator.Current
                => (Data[index].Key, Data[index].Value);

            public void Dispose() { }

            public bool MoveNext()
            {
                if (currentVersion != tree.version)
                {
                    throw new InvalidOperationException("Collection was modified");
                }
                index++;
                return index < Data.Length;
            }

            public void Reset()
            {
                if (currentVersion != tree.version)
                {
                    throw new InvalidOperationException("Collection was modified");
                }
                index = -1;
            }

            private static List<Data> GetDataFromBNode(Node node)
            {
                var data = new List<Data>();
                for (int i = 0; i < node.currentSize; i++)
                {
                    data.Add(node.values[i]);
                }
                foreach (Node child in node)
                {
                    data.AddRange(GetDataFromBNode(child));
                }
                return data;
            }
        }

        public int Count
            => new BTreeEnumerator(this).Data.Length;

        public string this[string key]
        {
            get => root.FindByKey(key).Value;
            set
            {
                root.InsertValue(key, value, treeDegree);
                version++;
            }
        }

        public bool IsReadOnly => false;

        /// <summary>
        /// Inseerts value in the tree by key
        /// </summary>
        public void Add(string key, string value)
        {
            root.InsertValue(key, value, treeDegree);
            version++;
        }

        /// <summary>
        /// Inserts value by key
        /// </summary>
        public void Add(KeyValuePair<string, string> item)
        {
            root.InsertValue(item.Key, item.Value, treeDegree);
            version++;
        }

        public bool ContainsKey(string key)
            => root.Exists(key).Item2;

        public bool Contains(KeyValuePair<string, string> item)
        {
            try
            {
                return root.FindByKey(item.Key).Value == item.Value;
            }
            catch (ArgumentOutOfRangeException)
            {
                return false;
            }
        }

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
        /// Return only existing values by their keys
        /// </summary>
        public bool TryGetValue(string key, [MaybeNullWhen(false)] out string value)
        {
            try
            {
                value = root.FindByKey(key).Value;
                return true;
            }
            catch (ArgumentOutOfRangeException)
            {
                value = string.Empty;
                return false;
            }
        }

            /// <summary>
            /// Deletes value by key
            /// </summary>
            public bool Remove(string key)
        {
            bool isExists = root.Exists(key).Item2;
            if (isExists)
            {
                version++;
            }
            root.DeleteValueByKey(key);
            return isExists;
        }

        /// <summary>
        /// Deletes value by key
        /// </summary>
        public bool Remove(KeyValuePair<string, string> item)
           => Remove(item.Key);

        public void Clear() { }

        public void CopyTo(KeyValuePair<string, string>[] array, int arrayIndex)
        {
            throw new NotImplementedException();
        }

        public IEnumerator<KeyValuePair<string, string>> GetEnumerator()
            => new BTreeEnumerator(this);

        IEnumerator IEnumerable.GetEnumerator()
            => new BTreeEnumerator(this);
    }
}
