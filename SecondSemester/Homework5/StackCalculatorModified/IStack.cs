namespace PostfixCalculator
{
    public interface IStack
    {
        bool IsEmpty();

        void Push(double value);

        double Pop();

        void Clear();
    }
}