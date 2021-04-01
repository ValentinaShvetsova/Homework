using System;
using System.Collections.Generic;
using System.Text;

namespace Calculator
{
    /// <summary>
    /// All possible operations
    /// </summary>
    public enum Operation
    {
        None,
        Addition,
        Subtraction,
        Multiplication,
        Division
    }

    /// <summary>
    /// Allows to perform operations on two double type numbers
    /// </summary>
    public class SuperCalculator
    {
        private double? number1;
        private double? number2;
        private Operation operation;

        /// <summary>
        /// Adds number.
        /// </summary>
        /// <param name="operation">Operation to add</param>
        public void AddNumber(double number)
        {
            if (number1 == null)
            {
                number1 = number;
                return;
            }
            number2 = number;
        }

        /// <summary>
        /// Adds or changes an operation
        /// </summary>
        /// <param name="operation"></param>
        public void AddOperation(Operation operation) => this.operation = operation;

        /// <summary>
        /// Clear everything
        /// </summary>
        public void Clear()
        {
            number1 = null;
            number2 = null;
            operation = Operation.None;
        }

        /// <summary>
        /// Calculates 2 double numbers and sets the result in the first number value
        /// </summary>
        /// <returns></returns>
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
