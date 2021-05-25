using System;
using System.Collections.Generic;
using System.Text;

namespace BTree
{
    public class Data
    {
        public Data(string key, string value)
        {
            Key = key;
            Value = value;
        }

        public Data Copy()
        {
            return new Data(Key, Value);
        }

        public string Key { get; set; }

        public string Value { get; set; }
    }
}
