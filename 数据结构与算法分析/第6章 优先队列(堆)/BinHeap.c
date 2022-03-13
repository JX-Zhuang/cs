#include <stdlib.h>
#include "BinHeap.h"

#define MinData -100
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