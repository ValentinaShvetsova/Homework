using NUnit.Framework;
using Game;

namespace Game.Tests
{
    [TestFixture()]
    public class MapTests
    {
        private Map map;

        [Test()]
        public void MapWithoutCharacterTest()
        {
            Assert.Throws<CharacterNotFoundException>(() => map = new Map("MapWithoutCharacter.txt"));
        }

        [Test()]
        public void MapWithTwoCharactersTest()
        {
            Assert.Throws<MoreThanOneCharacterException>(() => map = new Map("MapWithTwoCharacters.txt"));
        }

        [Test()]
        public void SetPosotionTest()
        {
            map = new Map("NormalMap.txt");
            Assert.IsFalse(map.SetCharacterPosition(-1, -2));
            Assert.IsFalse(map.SetCharacterPosition(2, 2));
            Assert.IsFalse(map.SetCharacterPosition(3, 1));
            Assert.IsFalse(map.SetCharacterPosition(0, 3));
            Assert.IsFalse(map.SetCharacterPosition(2, 1));
            Assert.IsTrue(map.SetCharacterPosition(1, 1));
            Assert.AreEqual((1, 1), map.CharacterPosition);
        }
    }
}