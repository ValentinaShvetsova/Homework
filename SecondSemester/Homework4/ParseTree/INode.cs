using System;
using System.Collections.Generic;
using System.Text;

namespace ParseTree
{
    public interface INode
    {
        public void Print();

        public int Calculate();
    }
}
