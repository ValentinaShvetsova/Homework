using Microsoft.VisualStudio.TestTools.UnitTesting;
using UniqueList;

namespace ListTests
{
    [TestClass]
    public class ListTests
    {
        [TestMethod]
        public void AddValueTest()
        {
            var list = new List();
            Assert.IsTrue(list.IsEmpty);
            list.AddValue(15, 0);
            list.AddValue(32, 1);

            Assert.IsFalse(list.IsEmpty);
            Assert.AreEqual(2, list.Size);
        }

        [TestMethod]
        public void DeleteValueTest()
        {
            var list = new List();
            list.AddValue(15, 0);
            list.AddValue(32, 1);

            list.DeleteValue(1);
            list.DeleteValue(0);

            Assert.AreEqual(0, list.Size);
            Assert.IsTrue(list.IsEmpty);
        }

        [TestMethod]
        public void SetValueTest()
        {
            var list = new List();
            list.AddValue(2345, 0);
            list.SetValue(1, 0);
            Assert.AreEqual(1, list.GetValue(0));
        }

        [TestMethod]
        public void GetValueTest()
        {
            var list = new List();
            list.AddValue(34, 0);
            list.AddValue(143, 0);
            Assert.AreEqual(34, list.GetValue(1));
        }

        [TestMethod]
        public void ContainsTest()
        {
            var list = new List();
            list.AddValue(34, 0);
            list.AddValue(143, 0);
            Assert.IsTrue(list.Contains(143));
            Assert.IsFalse(list.Contains(1));
        }

        [TestMethod]
        public void GetPositionTest()
        {
            var list = new List();
            list.AddValue(34, 0);
            list.AddValue(143, 0);
            Assert.AreEqual(1, list.GetPosition(34));
            Assert.AreEqual(-1, list.GetPosition(1));
        }

        [TestMethod]
        public void AddByInvalidPositionTest()
        {
            var list = new List();
            Assert.ThrowsException<InvalidPositionException>(() => list.AddValue(0, 7));
            Assert.ThrowsException<InvalidPositionException>(() => list.AddValue(0, -1));
        }

        [TestMethod]
        public void DeleteByInvalidPositionTest()
        {
            var list = new List();
            Assert.ThrowsException<InvalidPositionException>(() => list.DeleteValue(7));
            Assert.ThrowsException<InvalidPositionException>(() => list.DeleteValue(-1));
        }
    }

    [TestClass]
    public class UniqueListTests
    {
        [TestMethod]
        public void AddValueTest()
        {
            var list = new SuperUniqueList();
            list.AddValue(0, 0);
            list.AddValue(1, 1);
            Assert.ThrowsException<AddingExistingElementException>(() => list.AddValue(1, 1));
        }

        [TestMethod]
        public void SetValueTest()
        {
            var list = new SuperUniqueList();
            list.AddValue(15, 0);
            list.AddValue(32, 1);
            list.SetValue(32, 1);
            Assert.ThrowsException<AddingExistingElementException>(() => list.SetValue(32, 0));
        }
    }
}
