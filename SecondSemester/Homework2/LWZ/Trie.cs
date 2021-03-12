using System;
using System.Collections.Generic;
using System.Text;

namespace LWZ
{
    public class Trie<T>
    {
        private Node<T> root;
        public int count { get; set; }
        public Trie()
        {
            root = new Node<T> ('\0', default(T), "");
            count = 1;
        }
        /// <summary>
        /// Adds node in the trie, sets its components
        /// </summary>
        /// <param name="key">The node's key</param>
        /// <param name="data">The node's data</param>
        public void Add(string key, T data)
        {
            AddNode(key, data, root);
        }
        private void AddNode(string key, T data, Node<T> node)
        {
            if (string.IsNullOrEmpty(key))
            {
                if (!node.IsWord)
                {
                    node.Data = data;
                    node.IsWord = true;
                }
            }
            else
            {
                var symbol = key[0];
                var subnode = node.TryFind(symbol);
                if (subnode != null)
                {
                    AddNode(key.Substring(1), data, subnode);
                }
                else
                {
                    var newNode = new Node<T>(key[0], data, node.Prefix + key[0]);
                    node.SubNodes.Add(key[0], newNode);
                    AddNode(key.Substring(1), data, newNode);
                }
            }
        }

        /// <summary>
        /// Returns true if such node with such key exists.
        /// </summary>
        /// <param name="key">Key of node to be found</param>
        /// <param name="value">Data of node, if such node exists</param>
        /// <returns></returns>
        public bool TrySearch (string key, out T value)
        {
            return SearchNode(key, root, out value);
        }

        private bool SearchNode(string key, Node<T> node, out T value)
        {
            value = default(T);
            var result = false;
            if (string.IsNullOrEmpty(key))
            {
                if (node.IsWord)
                {
                    value = node.Data;
                    result = true;
                }
            }
            else
            {
                var subnode = node.TryFind(key[0]);
                if (subnode != null)
                {
                   result = SearchNode(key.Substring(1), subnode, out value);
                }
            }
            return result;
        }
    }
}
