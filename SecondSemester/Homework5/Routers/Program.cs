using System;

namespace Routers
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                FileFunctions.WriteResultInFile(KruskalAlgorithm.KruskalsAlgorithm(FileFunctions.CreateGraph(args[0])), args[1]);
            }
            catch (DisconnectedNetworkException error)
            {
                Console.Error.WriteLine(error.Message);
                Environment.Exit(-1);
            }
        }
    }
}
