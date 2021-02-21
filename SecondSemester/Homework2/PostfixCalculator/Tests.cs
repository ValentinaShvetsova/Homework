using System;
using System.Collections.Generic;
using System.Text;

namespace PostfixCalculator
{
    class Tests
    {
        public static bool Test1()
        {
            IStack stack = new ListStack();
            string expression = "1 2 3 * +";

            var (isCorrect, result) = SuperCalculator.Calculate(expression, stack);

            if (!isCorrect || result != 7)
            {
                return false;
            }
            return true;
        }

        public static bool Test2()
        {
            IStack stack = new ArrayStack();
            string expression = "1 2 3 * +";

            var (isCorrect, result) = SuperCalculator.Calculate(expression, stack);

            if (!isCorrect || result != 7)
            {
                return false;
            }
            return true;
        }

        public static bool Test3()
        {
            IStack stack = new ListStack();
            string expression = "1 2 ";

            var (isCorrect, result) = SuperCalculator.Calculate(expression, stack);

            if (isCorrect)
            {
                return false;
            }
            return true;
        }

        public static bool Test4()
        {
            IStack stack = new ArrayStack();
            string expression = "* +";

            var (isCorrect, result) = SuperCalculator.Calculate(expression, stack);

            if (isCorrect)
            {
                return false;
            }
            return true;
        }
    }
}
