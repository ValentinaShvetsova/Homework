using System;
using System.Collections.Generic;
using System.Text;

namespace Game
{
    public class SuperGame
    {
        public Map GameMap { get; }
        private readonly Action<int, int> setCursor;

        public SuperGame(string filename)
            : this(filename, (width, height) => Console.SetCursorPosition(width, height))
        {
        }

        public SuperGame(string filename, Action<int, int> setCursor)
        {
            GameMap = new Map(filename);
            this.setCursor = setCursor;
            GameMap.Print();
        }

        private void Move(int stepSide, int stepUp)
        {
            var (oldWidth, oldHeight) = GameMap.CharacterPosition;

            if (!GameMap.SetCharacterPosition(oldWidth - stepSide, oldHeight - stepUp))
            {
                return;
            }

            setCursor(oldWidth, oldHeight);
            Console.Write(' ');
            setCursor(GameMap.CharacterPosition.width, GameMap.CharacterPosition.height);
            Console.Write(Map.characterSymbol);
        }

        public void OnLeft(object sender, EventArgs args) => Move(-1, 0);

        public void OnRight(object sender, EventArgs args) => Move(1, 0);

        public void Up(object sender, EventArgs args) => Move(0, 1);

        public void Down(object sender, EventArgs args) => Move(0, -1);
    }
}
