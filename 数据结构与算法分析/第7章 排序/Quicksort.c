typedef int ElementType;
void Quicksort(ElementType A[], int N)
{
    Qsort(A, 0, N - 1);
}
void Qsort(ElementType A[], int Left, int Right)
{
    int i, j;
    ElementType Pivot = A[(Left + Right) / 2];

    Qsort(A, Left, i - 1);
    Qsort(A, i + 1, Right);
}