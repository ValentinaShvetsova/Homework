using System;

namespace PostfixCalculator
{
    class Program
    {
        static void Main(string[] args)
        {
            if (!Tests.Test())
            {
                Console.WriteLine("Tests failed");
                return;
            }
            Console.WriteLine("Choose: ");
            Console.WriteLine("Print 1 for list stack, print 2 for array stack ");

            var input = Console.ReadLine();
            if (!int.TryParse(input, out int choice))
            {
                Console.WriteLine("Invalid input");
                return;
            }

            IStack stack = choice switch
            {
                1 => new ListStack(),
                2 => new ArrayStack(),
                _ => null
            };

            Console.WriteLine("Enter postfix expression: ");
            string expression = Console.ReadLine();

            var (isCorrect, result) = SuperCalculator.Calculate(expression, stack);

            if (!isCorrect)
            {
                Console.WriteLine("Invalid postfix expression");
                return;
            }

            Console.WriteLine("Result: " + result);
        }
    }
}
