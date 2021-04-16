using System;

namespace Test1
{
    /// <summary>
    /// Thrown when the queue is empty
    /// </summary>
    [Serializable]
    public class EmtyQueueException : Exception
    {
        public EmtyQueueException() { }

        public EmtyQueueException(string message) : base(message) { }

        public EmtyQueueException(string message, Exception inner) : base(message, inner) { }

        protected EmtyQueueException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
