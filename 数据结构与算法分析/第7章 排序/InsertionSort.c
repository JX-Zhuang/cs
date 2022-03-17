void InsertionSort(int A[], int N)
{
    int temp, j;
    for (int i = 1; i < N; i++)
    {
        temp = A[i];
        for (j = i; j > 0 && A[j - 1] > temp; j--)
            A[j] = A[j - 1];
        A[j] = temp;
    }
};