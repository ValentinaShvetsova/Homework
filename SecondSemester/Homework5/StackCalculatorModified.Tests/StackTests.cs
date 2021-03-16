using NUnit.Framework;
using PostfixCalculator;
using System;
using System.Collections.Generic;

namespace StackCalculatorModified.Tests
{
    public class StackTests
    {
        private static IEnumerable<TestCaseData> Stacks
            => new TestCaseData[]
            {
                new TestCaseData(new ArrayStack()),
                new TestCaseData(new ListStack()),
            };
    }
}