using System;
using System.Collections.Generic;
using System.Text;

namespace PostfixCalculator
{
    class Tests
    {
        private static bool Test1(IStack stack)
        {
            string expression = "1 2 3 * +";

            var (isCorrect, result) = SuperCalculator.Calculate(expression, stack);

            return (isCorrect || result == 7);
        }

        private static bool Test2(IStack stack)
        {
            string expression = "1 2 ";

            var (isCorrect, result) = SuperCalculator.Calculate(expression, stack);

            return !isCorrect;
        }

        private static bool Test3(IStack stack)
        {
            string expression = "* +";

            var (isCorrect, result) = SuperCalculator.Calculate(expression, stack);

            return !isCorrect;
        }

        public static bool Test()
        {
            IStack stack1 = new ListStack();
            IStack stack2 = new ArrayStack();

            return (Test1(stack1) && Test1(stack2) && Test2(stack1) && Test2(stack2) && Test3(stack1) && Test3(stack2));
        }
    }
}
