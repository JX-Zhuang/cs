#include <stdio.h>
#include "List.h"
struct Node
{
    ElementType Element;
    Position Next;
};
int IsEmpty(List L)
{
    return L->Next == NULL;
}
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}
Position Find(ElementType X, List L)
{
    Position P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;
    return P;
}