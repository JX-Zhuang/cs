#include <stdio.h>
#include <stdlib.h>
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
void Delete(ElementType X, List L)
{
    Position P = FindPrevious(X, L), Tmp;
    if (!IsLast(P, L))
    {
        Tmp = P->Next;
        P->Next = Tmp->Next;
        free(Tmp);
    }
}
Position FindPrevious(ElementType X, List L)
{
    Position P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}
void Insert(ElementType X, List L, Position P)
{
    Position Node = malloc(sizeof(Node));
    if (Node == NULL)
    {
        //error
    }
    Node->Element = X;
    Node->Next = P->Next;
    P->Next = Node;
}