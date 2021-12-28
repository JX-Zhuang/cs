int even(int n)
{
    if (n % 2 == 0)
        return 1;
    return 0;
}
int OddSum(int List[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (even(List[i]) == 0)
        {
            sum += List[i];
        }
    }
    return sum;
}