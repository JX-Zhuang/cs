#include "ListStack.h"
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    ElementType Element;
    PtrToNode Next;
};
int IsEmpty(Stack S)
{
    return S->Next == NULL;
}
Stack CreateStack(void)
{
    Stack S = malloc(sizeof(struct Node));
    if (S == NULL)
    {
        //error
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}
void MakeEmpty(Stack S)
{
    if (S == NULL)
    {
        //
    }
    else
    {
        while (!IsEmpty(S))
            pop(S);
    }
}
void Push(ElementType X, Stack S)
{
    PtrToNode Tmp = malloc(sizeof(struct Node));
    if (Tmp == NULL)
    {
        //error
    }
    Tmp->Element = X;
    Tmp->Next = S->Next;
    S->Next = Tmp;
}
ElementType Top(Stack S)
{
    if (!IsEmpty(S))
    {
        return S->Next->Element;
    }
    //error
    return 0;
}
void Pop(Stack S)
{
    PtrToNode Tmp;
    if (IsEmpty(S))
    {
        //error
    }
    else
    {
        Tmp = S->Next;
        S->Next = S->Next->Next;
        free(Tmp);
    }
}