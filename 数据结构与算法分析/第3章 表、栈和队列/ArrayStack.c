#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack CreateStack(int MaxElements)
{
    Stack S;
    if (MaxElements < MinStackSize)
    {
        //error
    }
    S = malloc(sizeof(struct StackRecord));
    if (S == NULL)
    {
        //error
    }
    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL)
    {
        //error
    }
    S->Capacity = MaxElements;
    MakeEmpty(S);
    return S;
}
void DisposeStack(Stack S)
{
    if (S != NULL)
    {
        free(S->Array);
        free(S);
    }
}
int IsEmpty(Stack S)
{
    return S->TopOfStack == EmptyTOS;
}
void MakeEmpty(Stack S)
{
    S->TopOfStack = EmptyTOS;
}
void Push(ElementType X, Stack S)
{
    if (IsFull(S))
    {
        //error
    }
    else
        S->Array[++S->TopOfStack] = X;
}
int IsFull(Stack S)
{
    return S->TopOfStack + 1 == S->Capacity;
}
ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->TopOfStack];
    // error;
    return 0;
}
void Pop(Stack S)
{
    if (IsEmpty(S))
    {
        //error
    }
    else
        S->TopOfStack--;
}
ElementType TopAndPop(Stack S)
{
    if (IsEmpty(S))
    {
        //error
        return 0;
    }
    return S->Array[S->TopOfStack--];
}