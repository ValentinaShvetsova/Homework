using System;
using System.Collections.Generic;
using System.Text;

namespace UniqueList
{
    /// <summary>
    /// Thrown when position is out of range of list or just invalid
    /// </summary>
    [Serializable]
    public class InvalidPositionException : Exception
    {
        public InvalidPositionException() { }

        public InvalidPositionException(string message) : base(message) { }

        public InvalidPositionException(string message, Exception inner) : base(message, inner) { }
    }
}
