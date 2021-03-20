using NUnit.Framework;
using MapFilterFold;
using System.Collections.Generic;

namespace Functions.Tests
{
    [TestFixture()]
    public class FunctionsTests
    {
        private List<int> list = new List<int> { 1, 2, 3 };

        [Test()]
        public void MapTest()
        {
            Assert.AreEqual(new List<int>() { 2, 4, 6 }, Functions.Map(list, (elem) => elem * 2));
            Assert.AreEqual(new List<int>() { 17, 18, 19 }, Functions.Map(list, (elem) => 16 + elem));
        }

        [Test()]
        public void FilterTest()
        {
            Assert.AreEqual(new List<int>() { 3 }, Functions.Filter(list, (elem) => elem % 3 == 0));
            Assert.AreEqual(new List<int>() { 3 }, Functions.Filter(list, (elem) => elem > 2));
        }

        [Test()]
        public void FoldTest()
        {
            Assert.AreEqual(6, Functions.Fold(list, 1, (acc, elem) => acc * elem));
            Assert.AreEqual(6, Functions.Fold(list, 0, (acc, elem) => acc + elem));
        }
    }
}