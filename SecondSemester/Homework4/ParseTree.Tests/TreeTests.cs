using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ParseTree.Tests
{
    [TestClass]
    public class TreeTests
    {
        [TestMethod]
        public void CalculationTest()
        {
            var Tree = new Tree("(* (+ 1 1) 2)");
            Assert.AreEqual(4, Tree.Calculate());
        }
    }
}
