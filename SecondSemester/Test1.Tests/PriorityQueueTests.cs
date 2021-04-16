using NUnit.Framework;
using Test1;

namespace Test1.Tests
{
    public class Tests
    {
        private PriorityQueue<int> queue;

        [SetUp]
        public void Setup()
        {
            queue = new();
        }

        [Test]
        public void DeletingFromEmtyQueue()
        {
            Assert.Throws<EmtyQueueException>(() => queue.Dequeue());
        }

        [Test]
        public void AdditionTest()
        {
            queue.Enqueue(99, 1);
            queue.Enqueue(96, 2);
            queue.Enqueue(1, 3);
            queue.Enqueue(3, 2);
            queue.Enqueue(9, 4);

            Assert.AreEqual(queue.Dequeue(), 9);
            Assert.AreEqual(queue.Dequeue(), 1);
            Assert.AreEqual(queue.Dequeue(), 96);
            Assert.AreEqual(queue.Dequeue(), 3);
            Assert.AreEqual(queue.Dequeue(), 99);
        }

        [Test]
        public void DeletingTest()
        {
            queue.Enqueue(99, 1);
            queue.Dequeue();
            Assert.Throws<EmtyQueueException>(() => queue.Dequeue());
        }

        [Test]
        public void SizeCheck()
        {
            queue.Enqueue(3, 1);
            Assert.AreEqual(1, queue.Size);
        }
    }
}