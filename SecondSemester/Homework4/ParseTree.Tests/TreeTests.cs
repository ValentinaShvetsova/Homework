using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ParseTree.Tests
{
    [TestClass]
    public class TreeTests
    {
        [TestMethod]
        public void CalculationTestStandart()
        {
            var Tree = new Tree("(* (+ 1 1) 2)");
            Assert.AreEqual(4, Tree.Calculate());
        }

        [TestMethod]
        public void CalculationTestWithMultiDigitNimbers()
        {
            var Tree = new Tree("(/ (+ 10 15) 5)");
            Assert.AreEqual(5, Tree.Calculate());
        }

        [TestMethod]
        public void CalculationTestWithComplexStructure()
        {
            var Tree = new Tree("(/ (+ 72 (+ 53 67)) (- 36 32))");
            Assert.AreEqual(48, Tree.Calculate());
        }
    }
}
