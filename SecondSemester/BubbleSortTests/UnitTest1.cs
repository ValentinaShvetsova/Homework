using NUnit.Framework;
using BubbleSortGeneric;
using System.Collections.Generic;

namespace BubbleSortTests
{
    public class Tests
    {
        static readonly object[] Cases =
        {
            new object[] { new List<int> { 3, 4, 1, 6, 9, 13, 0, -2 }, new List<int> { -2, 0, 1, 3, 4, 6, 9, 13 } },
            new object[] { new List<int> { -1, -2, -3, -4, -5 }, new List<int> { -5, -4, -3, -2, -1 } },
            new object[] { new List<int> { 3, 3, 3, 3 }, new List<int> { 3, 3, 3, 3 } }
        };

        [TestCaseSource(nameof(Cases))]
        public void BubbleSortOnIntegersTest(List<int> listToSort, List<int> expectedResult)
        {
            var intsComparer = Comparer<int>.Default;
            Program.BubbleSort(listToSort, intsComparer);
            Assert.AreEqual(expectedResult, listToSort);
        }

        [Test]
        public void TestForStrings()
        {
            var listToSort = new List<string> { "tree", "grass", "war", "one" };
            var expectedList = new List<string> { "grass", "one", "tree", "war" };

            var stringComparer = Comparer<string>.Default;

            Program.BubbleSort(listToSort, stringComparer);
            Assert.AreEqual(expectedList, listToSort);
        }
    }
}