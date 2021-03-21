using System;
using System.Collections.Generic;
using System.Text;

namespace Game
{
    /// <summary>
    /// Thrown when there's 2 or more charater symbols on the map
    /// </summary>
    [Serializable]
    class MoreThanOneCharacterException : Exception
    {
        public MoreThanOneCharacterException() { }

        public MoreThanOneCharacterException(string message) : base(message) { }

        public MoreThanOneCharacterException(string message, Exception inner) : base(message, inner) { }

        protected MoreThanOneCharacterException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
