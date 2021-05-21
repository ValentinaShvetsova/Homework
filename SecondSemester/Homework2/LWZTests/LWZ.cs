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
        }

        [TestMethod]
        public void CompressTest()
        {
            string path = "../../../Text.txt";
            Program.CompressString(path);
            string resultPath = path + ".zipped";
            System.IO.StreamReader file = new System.IO.StreamReader(resultPath);
            string str = file.ReadLine();
            string result = "01025039864";
            Assert.AreEqual(result, str);
        }

        [TestMethod]
        public void DecompressTest()
        {
            string path = "../../../Text.txt.zipped";
            Program.Decompress(path, "abcde");
            string resultPath = "../../../Text.txt";
            System.IO.StreamReader file = new System.IO.StreamReader(resultPath);
            string str = file.ReadLine();
            string result = "abacabadabacabae";
            Assert.AreEqual(result, str);
        }
    }
}
