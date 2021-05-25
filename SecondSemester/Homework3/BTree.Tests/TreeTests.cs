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

        [Test]
        public void ExistingTest()
        {
            tree.Add("1", "a");
            tree.Add("2", "b");
            tree.Add("3", "c");

            tree.Add("9", "d");
            tree.Add("10", "e");
            tree.Add("20", "f");

            Assert.AreEqual(true, tree.ContainsKey("2"));
            Assert.AreEqual(true, tree.ContainsKey("20"));
            Assert.AreEqual(false, tree.ContainsKey("567"));
        }

        [Test]
        public void DeleteTest()
        {
            tree.Add("1", "a");
            tree.Add("2", "b");
            tree.Add("3", "c");

            tree.Add("9", "d");
            tree.Add("10", "e");
            tree.Add("20", "f");

            tree.Remove("3");
            tree.Remove("10");

            Assert.AreEqual(false, tree.ContainsKey("3"));
            Assert.AreEqual(false, tree.ContainsKey("10"));
            Assert.AreEqual(true, tree.ContainsKey("9"));
        }

        [Test]
        public void ForEachTest()
        {
            tree.Add("1", "a");
            tree.Add("2", "b");
            tree.Add("3", "c");

            tree.Add("9", "d");
            tree.Add("10", "e");
            tree.Add("20", "f");

            foreach(var data in tree)
            {
                Assert.IsNotNull(data.Key);
                Assert.IsNotNull(data.Value);
            }
        }
    }
}