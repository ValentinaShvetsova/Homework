using NUnit.Framework;
using System;
using System.Collections.Generic;
//using StackCalculatorModified;

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