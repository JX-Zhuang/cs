#include <stdlib.h>
#include "BinHeap.h"

#define MinData -100000
struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;
    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
    {
        //error
    }
    H->Elements = malloc(sizeof(ElementType) * (MaxElements + 1));
    if (H->Elements == NULL)
    {
        //error
    }
    H->Size = 0;
    H->Capacity = MaxElements;
    H->Elements[0] = MinData;
    return H;
}

int IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}
void Insert(ElementType X, PriorityQueue H)
{
    if (IsFull(H))
    {
        //error;
        return;
    }
    int i;
    for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = X;
}
int IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}
ElementType DeleteMin(PriorityQueue H)
{
    if (IsEmpty(H))
    {
        //error;
        return H->Elements[0];
    }
    int i, Child;
    ElementType MinElement = H->Elements[1],
                LastElement = H->Elements[H->Size--];
    for (i = 1; 2 * i <= H->Size; i = Child)
    {
        Child = i * 2;
        if (Child < H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        if (LastElement > H->Elements[Child])
        {
            H->Elements[i] = H->Elements[Child];
        }
        else
        {
            break;
        }
    }
    H->Elements[i] = LastElement;
    return MinElement;
}