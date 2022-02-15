#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include <string.h>
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
    Position Tmp = malloc(sizeof(struct Node));
    if (Tmp == NULL)
    {
        //error
    }
    Tmp->Element = X;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}
void DeleteList(List L)
{
    Position P = L->Next, Tmp;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}
void PrintList(List L)
{
    Position P = L->Next;
    while (P != NULL)
    {
        printf("List Node Element:%d\n", P->Element);
        P = P->Next;
    }
}
List MakeEmpty(List L)
{
    if (L != NULL)
    {
        DeleteList(L);
    }
    L = (List)malloc(sizeof(struct Node));
    L->Next = NULL;
    return L;
}
int main()
{
    List L = MakeEmpty(NULL);
    Insert(1, L, L);
    Insert(2, L, L);
    Insert(3, L, L);
    Insert(4, L, L);
    Insert(5, L, L);
    Delete(3, L);
    PrintList(L);
    Position P = Find(2, L);
    if (P != NULL)
    {
        P->Element = 222;
    }
    PrintList(L);
    return 0;
}