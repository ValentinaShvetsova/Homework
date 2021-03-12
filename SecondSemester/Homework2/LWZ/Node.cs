﻿using System;
using System.Collections.Generic;
using System.Text;

namespace LWZ
{
    class Node<T>
    {
        public char Symbol { get; set; }

        public T Data { get; set; }

        public bool IsWord { get; set; }

        public string Prefix { get; set; }

        public Dictionary<char, Node<T>> SubNodes { get; }

        public Node(char symbol, T data, string prefix)
        {
            Symbol = symbol;
            Data = data;
            SubNodes = new Dictionary<char, Node<T>>();
            Prefix = prefix;
        }

        public override string ToString()
            => Data.ToString();

        public Node<T> TryFind(char symbol)
        {
            if (SubNodes.TryGetValue(symbol, out Node<T> value))
            {
                return value;
            }
            return null;
        }

        public override bool Equals(object obj)
            => obj is Node<T> item ? Data.Equals(item) : false;
    }
}
