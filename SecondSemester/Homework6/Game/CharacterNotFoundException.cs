using System;
using System.Collections.Generic;
using System.Text;

namespace Game
{
    /// <summary>
    /// Thrown when the map doesn't contain the character symbol
    /// </summary>
    [Serializable]
    public class CharacterNotFoundException : Exception
    {
        public CharacterNotFoundException() { }

        public CharacterNotFoundException(string message) : base(message) { }

        public CharacterNotFoundException(string message, Exception inner) : base(message, inner) { }

        protected CharacterNotFoundException(
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context) : base(info, context) { }
    }
}
