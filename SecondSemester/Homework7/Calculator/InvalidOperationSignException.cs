using System;
using System.Collections.Generic;
using System.Text;

namespace Calculator
{
    /// <summary>
    /// Thrown when the sign doesn't match operation
    /// </summary>
    [Serializable]
    public class InvalidOperationSignException : Exception
    {
        public InvalidOperationSignException() { }

        public InvalidOperationSignException(string message) : base(message) { }

        public InvalidOperationSignException(string message, Exception inner) : base(message, inner) { }

        protected InvalidOperationSignException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
