using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace LWZ.Tests
{
    [TestClass]
    public class LWZTest
    {
        [TestMethod]
        public void TrieTests()
        {
            var trie = new Trie<int>();
            trie.Add("red", 1);
            trie.Add("blue", 2);
            trie.Add("boss", 3);
            trie.Add("roar", 4);
            Assert.IsTrue(trie.TrySearch("red", out int value1));
            Assert.IsTrue(!trie.TrySearch("blow", out int value2));
            Assert.IsTrue(trie.TrySearch("roar", out int value3));
            trie.Remove("red");
            Assert.IsTrue(!trie.TrySearch("red", out int value4));
        }

        [TestMethod]
        public void AlgorithmTests()
        {
            string str = "abacabadabacabae";
            string result;
        }
    }
}
