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
            tree.AddValue("1", "a");
            tree.AddValue("2", "b");
            tree.AddValue("3", "c");

            tree.AddValue("9", "d");
            tree.AddValue("10", "e");
            tree.AddValue("20", "f");

            Assert.AreEqual("b", tree.FindValue("2"));
            Assert.AreEqual("f", tree.FindValue("20"));
        }
    }
}