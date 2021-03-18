using NUnit.Framework;
using PostfixCalculator;
using System;
using System.Collections.Generic;

namespace StackCalculatorModified.Tests
{
    [TestFixture]
    public class StackTests
    {
        [TestCaseSource(nameof(Stacks))]
        public void PushTest(IStack stack)
        {
            stack.Push(333);
            Assert.IsFalse(stack.IsEmpty());
        }

        [TestCaseSource(nameof(Stacks))]
        public void PopTest(IStack stack)
        {
            stack.Push(345);
            stack.Push(123);
            stack.Push(999);
            Assert.AreEqual(999, stack.Pop());
        }

        [TestCaseSource(nameof(Stacks))]
        public void PopedNumberShouldBeDeleted(IStack stack)
        {
            stack.Push(33);
            stack.Pop();
            Assert.IsTrue(stack.IsEmpty());
            stack.Push(66);
            Assert.AreEqual(66, stack.Pop());
        }
        private static IEnumerable<TestCaseData> Stacks
            => new TestCaseData[]
            {
                new TestCaseData(new ArrayStack()),
                new TestCaseData(new ListStack()),
            };
    }
}