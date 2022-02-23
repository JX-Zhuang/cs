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
void PrintLots(List L, List P)
{
    int i = 0;
    P = P->Next;
    L = L->Next;
    while (P != NULL && L != NULL)
    {
        if (P->Element < 0)
        {
            P = P->Next;
            continue;
        }
        if (P->Element == i)
        {
            printf("%d\n", L->Element);
            P = P->Next;
        }
        else if (P->Element > i)
        {
            L = L->Next;
            i++;
        }
        else
        {
            P = P->Next;
        }
    }
}
List Unique(List L1, List L2)
{
    List L = MakeEmpty(NULL);
    Position Tmp = L,T;
    L1 = L1->Next;
    L2 = L2->Next;
    while (L1 != NULL && L2 != NULL)
    {
        if (L1->Element == L2->Element)
        {
            T = malloc(sizeof(struct Node));
            Tmp->Next = T;
            T->Element = L1->Element;
            Tmp = T;
            L1 = L1->Next;
            L2 = L2->Next;
        }
        else if (L1->Element > L2->Element)
        {
            L2 = L2->Next;
        }
        else
        {
            L1 = L1->Next;
        }
    }
    return L;
}
int main()
{
    List P = MakeEmpty(NULL);
    Insert(6, P, P);
    Insert(4, P, P);
    Insert(3, P, P);
    Insert(1, P, P);
    List L = MakeEmpty(NULL);
    Insert(5, L, L);
    Insert(4, L, L);
    Insert(3, L, L);
    Insert(2, L, L);
    Insert(1, L, L);
    List nL = Unique(L, P);
    PrintList(nL);
    return 0;
}