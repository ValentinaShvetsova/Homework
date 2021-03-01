using System;
using System.Collections.Generic;
using System.Text;

namespace PostfixCalculator
{
    static class SuperCalculator
    {
        public static (bool, double) Calculate(string postfixExpression, IStack stack)
        {
           string number = string.Empty;
           foreach (char symbol in postfixExpression)
            {
                if (char.IsDigit(symbol))
                {
                    number = string.Concat(number, char.ToString(symbol));
                    continue;
                }

                if (number.Length > 0)
                {
                    stack.Push(double.Parse(number));
                    number = string.Empty;
                    continue;
                }


                if (symbol == ' ')
                {
                    continue;
                }

                switch (symbol)
                {
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        if (stack.IsEmpty())
                        {
                            return (false, 0);
                        }

                        double topValue = stack.Pop();

                        if (stack.IsEmpty() || (symbol == '/' && Math.Abs(topValue - 0) < 0.00001))
                        {
                            stack.Clear();
                            return (false, 0);
                        }

                        stack.Push(topValue);
                        PerformOperation(symbol, stack);
                        break;
                    default:
                        stack.Clear();
                        return (false, 0);
                }
            }
            if (stack.IsEmpty())
            {
                return (false, 0);
            }

            var result = stack.Pop();
            if (stack.IsEmpty())
            {
                return (true, result);
            }

            stack.Clear();
            return (false, 0);
        }

        private static void PerformOperation(char operation, IStack stack)
        {
            var operand2 = stack.Pop();
            var operand1 = stack.Pop();

            switch (operation)
            {
                case '+':
                    stack.Push(operand1 + operand2);
                    break;
                case '-':
                    stack.Push(operand1 - operand2);
                    break;
                case '*':
                    stack.Push(operand1 * operand2);
                    break;
                default:
                    stack.Push(operand1 / operand2);
                    break;
            }
        }
    }
}
