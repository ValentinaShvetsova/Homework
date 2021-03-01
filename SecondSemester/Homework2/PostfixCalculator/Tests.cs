using System;
using System.Collections.Generic;
using System.Text;

namespace PostfixCalculator
{
    class Tests
    {
        public static bool Test1()
        {
            IStack stack1 = new ListStack();
            IStack stack2 = new ListStack();

            string expression = "1 2 3 * +";

            var (isCorrect1, result1) = SuperCalculator.Calculate(expression, stack1);
            var (isCorrect2, result2) = SuperCalculator.Calculate(expression, stack2);

            return (isCorrect1 || isCorrect2 || result1 == 7 || result2 == 7);
        }

        public static bool Test2()
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

        public static bool Test3()
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
