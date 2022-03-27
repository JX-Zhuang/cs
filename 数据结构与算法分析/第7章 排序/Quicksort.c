#include <stdio.h>
typedef int ElementType;
void Swap(ElementType *A, ElementType *B)
{
    ElementType Tmp = *A;
    *A = *B;
    *B = Tmp;
}
int Partition(ElementType A[], int Left, int Right)
{
    ElementType Pivot = A[Left];
    int i = Left + 1, j = Right;
    while (1)
    {
        while (A[i] <= Pivot && i <= j)
            i++;
        while (A[j] >= Pivot && i <= j)
            j--;
        if (i >= j)
            break;
        Swap(&A[i], &A[j]);
    }
    Swap(&A[Left], &A[j]);
    return j;
}
void Qsort(ElementType A[], int Left, int Right)
{
    if (Left >= Right)
        return;
    int i = Partition(A, Left, Right);
    Qsort(A, Left, i - 1);
    Qsort(A, i + 1, Right);
}
void Quicksort(ElementType A[], int N)
{
    Qsort(A, 0, N - 1);
}


int main()
{
    ElementType A[] = {6, 7, 3, 2, 5, 6, 8, 10, 4, 9, 1, 6};
    Quicksort(A, 12);
    for (int i = 0; i < 12; i++)
    {
        printf("%d\n", A[i]);
    }
    return 0;
}