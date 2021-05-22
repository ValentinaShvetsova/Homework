using System;
using System.Collections.Generic;
using PostfixCalculator;
using NUnit.Framework;
using StackCalculatorModified;

namespace StackCalculatorModified.Tests
{
    [TestFixture]
    class CalculatorTests
    {
        [TestCase("15 19 +", 34, ExpectedResult = true)]
        [TestCase("55 10 /", 5.5, ExpectedResult = true)]
        [TestCase("3 4 + 6 7 + *", 91, ExpectedResult = true)]
        public bool CalculationTest(string expression, double result)
        {
            bool testResult1 = Math.Abs(SuperCalculator.Calculate(expression, new ArrayStack()).Item2 - result) < 0.0001;
            bool testResult2 = Math.Abs(SuperCalculator.Calculate(expression, new ListStack()).Item2 - result) < 0.0001;
            return testResult1 && testResult2;
        }

        [TestCase("5 5 5", ExpectedResult = false)]
        [TestCase("34 *", ExpectedResult = false)]
        [TestCase("5 3 + -", ExpectedResult = false)]
        [TestCase("x y +", ExpectedResult = false)]
        public bool IncorrectExpressionTest(string expression)
            => SuperCalculator.Calculate(expression, new ArrayStack()).Item1 && SuperCalculator.Calculate(expression, new ListStack()).Item1;
    }
}
