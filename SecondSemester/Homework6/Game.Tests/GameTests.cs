using System;
using System.Collections.Generic;
using NUnit.Framework;
using Game;

namespace Game.Tests
{
    [TestFixture()]
    class GameTests
    {
        private SuperGame game;

        [SetUp]
        public void Initialize() 
        {
            game = new SuperGame("mapForGameTests.txt", (left, top) => { });
        }

        [Test()]
        public void OnLeftTest()
        {
            game.OnLeft(this, EventArgs.Empty);
            Assert.AreEqual((4, 2), game.GameMap.CharacterPosition);

            game.OnLeft(this, EventArgs.Empty);
            Assert.AreEqual((4, 2), game.GameMap.CharacterPosition);
        }

        [Test()]
        public void DownTest()
        {
            game.Down(this, EventArgs.Empty);
            Assert.AreEqual((5, 3), game.GameMap.CharacterPosition);

            game.Down(this, EventArgs.Empty);
            Assert.AreEqual((5, 3), game.GameMap.CharacterPosition);
        }

        [Test()]
        public void UpTest()
        {
            game.Up(this, EventArgs.Empty);
            Assert.AreEqual((5, 1), game.GameMap.CharacterPosition);

            game.Up(this, EventArgs.Empty);
            Assert.AreEqual((5, 0), game.GameMap.CharacterPosition);

            game.Up(this, EventArgs.Empty);
            Assert.AreEqual((5, 0), game.GameMap.CharacterPosition);
        }

        [Test()]
        public void OnRightTest()
        {
            game.OnRight(this, EventArgs.Empty);
            Assert.AreEqual((6, 2), game.GameMap.CharacterPosition);

            game.OnRight(this, EventArgs.Empty);
            Assert.AreEqual((7, 2), game.GameMap.CharacterPosition);
        }
    }
}
