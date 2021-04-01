using System;
using System.Collections.Generic;
using System.Text;

namespace Calculator
{
    /// <summary>
    /// Thrown when there's one or none operands.
    /// </summary>
    [Serializable]
    public class MissingOperandException : Exception
    {
        public MissingOperandException() { }

        public MissingOperandException(string message) : base(message) { }

        public MissingOperandException(string message, Exception inner) : base(message, inner) { }

        protected MissingOperandException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
