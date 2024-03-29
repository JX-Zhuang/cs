#include <stdlib.h>
typedef int ElementType;
void Merge(ElementType A[], ElementType TmpArray[], int Lpos, int Rpos, int RightEnd)
{
    int TmpPos = Lpos, LeftEnd = Rpos - 1, i = 0, NumElements = RightEnd - Lpos + 1;
    while (Lpos <= LeftEnd && Rpos <= RightEnd)
        if (A[Lpos] <= A[Rpos])
            TmpArray[TmpPos++] = A[Lpos++];
        else
            TmpArray[TmpPos++] = A[Rpos++];
    while (Lpos <= LeftEnd)
        TmpArray[TmpPos++] = A[Lpos++];
    while (Rpos <= RightEnd)
        TmpArray[TmpPos++] = A[Rpos++];
    for (; i < NumElements; i++, RightEnd--)
        A[RightEnd] = TmpArray[RightEnd];
}
void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
    int Center;
    if (Left < Right)
    {
        Center = (Left + Right) / 2;
        MSort(A, TmpArray, Left, Center);
        MSort(A, TmpArray, Center + 1, Right);
        Merge(A, TmpArray, Left, Center + 1, Right);
    }
}
void Mergesort(ElementType A[], int N)
{
    ElementType *TmpArray;
    TmpArray = malloc(N * sizeof(ElementType));
    if (TmpArray == NULL)
    {
        //
    }
    else
    {
        MSort(A, TmpArray, 0, N - 1);
        free(TmpArray);
    }
}