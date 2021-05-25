using NUnit.Framework;
using BTree;
using System;

namespace BTree.Tests
{
    [TestFixture()]
    public class TreeTests
    {
        private Tree tree;

        [SetUp]
        public void Initialize()
        {
            tree = new Tree(3);
        }

        [Test]
        public void AdditionTest()
        {
            tree.Add("1", "a");
            tree.Add("2", "b");
            tree.Add("3", "c");

            tree.Add("9", "d");
            tree.Add("10", "e");
            tree.Add("20", "f");

            Assert.AreEqual("b", tree["2"]);
            Assert.AreEqual("f", tree["20"]);
        }
    }
}