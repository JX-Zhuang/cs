#include <stdio.h>
#define LeftChild(i) (2 * (i) + 1)

typedef int ElementType;

void Swap(ElementType *A, ElementType *B)
{
    ElementType Tmp = *A;
    *A = *B;
    *B = Tmp;
}
void PercDown(ElementType A[], int i, int N)
{
    int Child;
    ElementType Tmp;
    for (Tmp = A[i]; LeftChild(i) < N; i = Child)
    {
        Child = LeftChild(i);
        if (Child != N - 1 && A[Child + 1] > A[Child])
            Child++;
        if (Tmp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = Tmp;
}
void Heapsort(ElementType A[], int N)
{
    int i;
    for (i = N / 2; i >= 0; i--)
    {
        PercDown(A, i, N);
    }
    for (i = N - 1; i > 0; i--)
    {
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}
int main()
{
    ElementType A[] = {4, 5, 3, 1, 6};
    Heapsort(A, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", A[i]);
    }
    return 0;
}