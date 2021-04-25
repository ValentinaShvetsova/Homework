using System.IO;
using NUnit.Framework;

namespace Routers.Tests
{
    public class Tests
    {
        [Test]
        public void FirstAlforthmTest()
        {
            var matrix = new int[3, 3] { { 0, 10, 5 }, { 10, 0, 1 }, { 5, 1, 0 } };
            var result = new int[3, 3] { { 0, 10, 5 }, { 10, 0, 0 }, { 5, 0, 0 } };
            Assert.AreEqual(result, KruskullAlgorithm.KruskullsAlgorithm(matrix));
        }

        [Test]
        public void TestFromFile()
        {
            var startPath = "../../../Test.txt";
            var resultPath = "../../../TestResult.txt";
            var corretAnswerPath = "../../../Answer.txt";

            FileFunctions.WriteResultInFile(KruskullAlgorithm.KruskullsAlgorithm(FileFunctions.CreateGraph(startPath)), resultPath);

            string[] stringsArray1 = File.ReadAllLines(resultPath);
            string[] stringsArray2 = File.ReadAllLines(corretAnswerPath);
            File.Delete(resultPath);
            Assert.AreEqual(stringsArray1, stringsArray2);
        }
    }
}