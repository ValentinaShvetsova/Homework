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
            tree.AddValue("1", "sun");
            tree.AddValue("2", "moon");
            tree.AddValue("3", "back");
            tree.AddValue("3", "Jupiter");
            tree.AddValue("4", "Venus");
            tree.AddValue("5", "Mercury");
            Assert.AreEqual("Mercury", tree.FindValue("5"));
            Assert.AreEqual("Jupiter", tree.FindValue("3"));
        }
    }
}