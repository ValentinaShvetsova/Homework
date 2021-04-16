using System;

namespace BTree
{
    class Program
    {
        static void Main(string[] args)
        {
            var tree = new Tree(3);
            tree.AddValue("1", "sun");
            tree.AddValue("2", "moon");
            tree.AddValue("3", "back");
            tree.AddValue("3", "Jupiter");
            tree.AddValue("4", "Venus");
            tree.AddValue("5", "Mercury");
            tree.FindValue("5");
        }
    }
}
