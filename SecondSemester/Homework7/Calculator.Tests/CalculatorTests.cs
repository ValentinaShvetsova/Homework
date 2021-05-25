using NUnit.Framework;
using Calculator;
using System;

namespace Calculator.Tests
{
    [TestFixture()]
    public class CalculatorTests
    {
        private SuperCalculator calculator;

        [SetUp]
        public void Initialize() => calculator = new SuperCalculator();

        [Test]
        public void MissingOperandTest()
        {
            calculator.AddOperation(Operation.Addition);
            Assert.Throws<MissingOperandException>(() => calculator.Calculate());
            calculator.AddNumber(333);
            Assert.Throws<MissingOperandException>(() => calculator.Calculate());
        }

        [Test]
        public void MissingOperationTest()
        {
            calculator.AddNumber(1);
            calculator.AddNumber(2);
            Assert.Throws<MissingOperationException>(() => calculator.Calculate());
        }

        [Test]
        public void ClearTest()
        {
            calculator.AddNumber(3);
            calculator.AddNumber(9);
            calculator.AddOperation(Operation.Addition);
            Assert.DoesNotThrow(() => calculator.Calculate());

            calculator.Clear();

            calculator.AddNumber(5);
            calculator.AddNumber(10);
            Assert.Throws<MissingOperationException>(() => calculator.Calculate());

            calculator.Clear();

            calculator.AddNumber(3);
            calculator.AddOperation(Operation.Addition);
            Assert.Throws<MissingOperandException>(() => calculator.Calculate());
        }

        [Test]
        public void DivideByZeroTest()
        {
            calculator.AddNumber(1);
            calculator.AddNumber(0);
            calculator.AddOperation(Operation.Division);
            Assert.Throws<DivideByZeroException>(() => calculator.Calculate());
        }

        [TestCase(Operation.Addition, 9)]
        [TestCase(Operation.Subtraction, 3)]
        [TestCase(Operation.Multiplication, 18)]
        [TestCase(Operation.Division, 2)]
        public void OperationsTests(Operation operation, double expected)
        {
            calculator.AddNumber(6);
            calculator.AddNumber(3);
            calculator.AddOperation(operation);
            Assert.AreEqual(expected, calculator.Calculate());
        }
    }
}