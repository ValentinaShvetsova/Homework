using System;
using System.Collections.Generic;
using System.Text;

namespace UniqueList
{
    /// <summary>
    /// Thrown if someone trying to add value, which already exists in list
    /// </summary>
    [Serializable]
    class AddingExistingElementException : Exception
    {
        public AddingExistingElementException() { }

        public AddingExistingElementException(string message) : base(message) { }

        public AddingExistingElementException(string message, Exception inner) : base(message, inner) { }
    }
}
