using System;
using System.Collections.Generic;
using System.Text;

namespace Calculator
{
    public enum Operation
    {
        None,
        Addition,
        Subtraction,
        Multiplication,
        Division
    }
    class SuperCalculator
    {
        private double? number1;
        private double? number2;
        private Operation operation;

        public void AddNumber(double number)
        {
            if (number1 == null)
            {
                number1 = number;
                return;
            }
            number2 = number;
        }

        public void AddOperation(Operation operation) => this.operation = operation;

        public void Clear()
        {
            number1 = null;
            number2 = null;
            operation = Operation.None;
        }

        public double Calculate()
        {
            if (number1 == null || number2 == null)
                throw new MissingOperandException();

            if (operation == Operation.Division && number2 == 0)
                throw new DivideByZeroException();

            var result = (double)PerformOperation();
            number1 = result;
            return result;
        }

        private double? PerformOperation() =>
            operation switch
            {
                Operation.Addition => number1 + number2,
                Operation.Subtraction => number1 - number2,
                Operation.Multiplication => number1 * number2,
                Operation.Division => number1 / number2,
                _ => throw new MissingOperationException()
            };
    }
}
