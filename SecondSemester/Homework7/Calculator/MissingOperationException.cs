using System;
using System.Collections.Generic;
using System.Text;

namespace Calculator
{
    /// <summary>
    /// Thrown when there's no operation to perform
    /// </summary>
    [Serializable]
    class MissingOperationException : Exception
    {
        public MissingOperationException() { }

        public MissingOperationException(string message) : base(message) { }

        public MissingOperationException(string message, Exception inner) : base(message, inner) { }

        protected MissingOperationException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
