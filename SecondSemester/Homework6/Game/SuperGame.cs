using System;
using System.Collections.Generic;
using System.Text;

namespace Game
{
    public class SuperGame
    {
        public Map GameMap { get; }
        private readonly Action<int, int> setCursor;

        /// <summary>
        /// Initialize new object of the game class
        /// </summary>
        public SuperGame(string filename)
            : this(filename, (width, height) => Console.SetCursorPosition(width, height))
        {
        }

        /// <summary>
        /// Initialize new object of the game class
        /// </summary>
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

        /// <summary>
        /// Moves the character left
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="args"></param>
        public void OnLeft(object sender, EventArgs args) => Move(1, 0);

        /// <summary>
        /// Moves the character right
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="args"></param>
        public void OnRight(object sender, EventArgs args) => Move(-1, 0);

        /// <summary>
        /// Moves the character up
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="args"></param>
        public void Up(object sender, EventArgs args) => Move(0, 1);

        /// <summary>
        /// Moves the character down
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="args"></param>
        public void Down(object sender, EventArgs args) => Move(0, -1);
    }
}
