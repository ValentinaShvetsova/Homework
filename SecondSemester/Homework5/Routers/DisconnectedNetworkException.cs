using System;
using System.Collections.Generic;
using System.Text;

namespace Routers
{
    /// <summary>
    /// Thrown when network is not connected from the start
    /// </summary>
    public class DisconnectedNetworkException : Exception
    {
        public DisconnectedNetworkException()
        {
        }

        public DisconnectedNetworkException(string message)
            : base(message)
        {
        }

        public DisconnectedNetworkException(string message, Exception inner)
            : base(message, inner)
        {
        }

        protected DisconnectedNetworkException(
            System.Runtime.Serialization.SerializationInfo info,
            System.Runtime.Serialization.StreamingContext context)
            : base(info, context)
        {
        }
    }
}
