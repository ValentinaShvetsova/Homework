using System;
using System.IO;

namespace Game
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.CursorVisible = false;
            try
            {
                var eventLoop = new EventLoop();
                var game = new SuperGame("map.txt");

                eventLoop.LeftHandler += game.OnLeft;
                eventLoop.RightHandler += game.OnRight;
                eventLoop.UpHandler += game.Up;
                eventLoop.DownHandler += game.Down;

                eventLoop.Run();
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine("Map file not found");
            }
        }
    }
}
