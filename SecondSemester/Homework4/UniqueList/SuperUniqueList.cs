using System;
using System.Collections.Generic;
using System.Text;

namespace UniqueList
{
    /// <summary>
    /// The List that doesn't contain duplicate values
    /// </summary>
    public class SuperUniqueList : List
    {
        /// <summary>
        /// Adds element only if it is not currently on the list
        /// </summary>
        /// <param name="value"></param>
        /// <param name="position"></param>
        public override void AddValue(int value, int position)
        {
            if (Contains(value))
            {
                throw new AddingExistingElementException();
            }

            base.AddValue(value, position);
        }

        /// <summary>
        /// Sets the value of element by position only if it's not on the list or current value on this position and new value are equal
        /// </summary>
        /// <param name="value"></param>
        /// <param name="position"></param>
        public override void SetValue(int value, int position)
        {
            if (Contains(value))
            {
                if (GetPosition(value) == position)
                {
                    return;
                }
                throw new AddingExistingElementException();
            }

            base.SetValue(value, position);
        }
    }
}
