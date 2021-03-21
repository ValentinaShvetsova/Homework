using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Game
{
    public class Map
    {
        private List<List<char>> walls;

        public (int width, int height) CharacterPosition { get; private set; } = (-1, -1);

        public const char characterSymbol = '@';

        public Map(string filename)
        {
            walls = new List<List<char>>();

            FillMap(filename);

            if (CharacterPosition == (-1, -1))
            {
                throw new CharacterNotFoundException();
            }
        }

        public bool SetCharacterPosition(int width, int height)
        {
            if (width < 0 || height < 0 || height >= walls.Count || width >= walls[height].Count)
            {
                return false;
            }

            if (walls[height][width] != ' ' || CharacterPosition == (width, height))
            {
                return false;
            }

            CharacterPosition = (width, height);
            return true;
        }

        private void FillMap(string fileName)
        {
            using var streamReader = new StreamReader(fileName);
            var currentLine = 0;
            walls.Add(new List<char>());

            while (!streamReader.EndOfStream)
            {
                var currentSymbol = streamReader.Read();

                if (currentSymbol == '\r')
                    continue;

                if (currentSymbol == '\n')
                {
                    walls.Add(new List<char>());
                    currentLine++;
                    continue;
                }

                if (currentSymbol == characterSymbol)
                {
                    if (CharacterPosition != (-1, -1))
                        throw new MoreThanOneCharacterException();

                    CharacterPosition = (walls[currentLine].Count, currentLine);
                    currentSymbol = ' ';
                }

                walls[currentLine].Add((char)currentSymbol);
            }
        }

        public void Print()
        {
            walls[CharacterPosition.height][CharacterPosition.width] = '@';
            foreach (var line in walls)
            {
                foreach (var symbol in line)
                {
                    Console.Write(symbol);
                }
                Console.WriteLine();
            }
            walls[CharacterPosition.height][CharacterPosition.width] = ' ';
        }
    }
}
