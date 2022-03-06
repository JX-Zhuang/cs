#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

int Max(int a, int b)
{
    return a > b ? a : b;
}

static int Height(Position P)
{
    if (P == NULL)
        return -1;
    return P->Height;
}
static Position SingleRotateWithLeft(Position K2)
{
    Position K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;
    return K1;
}
static Position SingleRotateWithRight(Position K2)
{
    Position K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Right), K2->Height) + 1;
    return K1;
}
static Position DoubleRotateWithLeft(Position K3)
{
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}
static Position DoubleRoateWithRight(Position K3)
{
    K3->Right = SingleRotateWithLeft(K3->Right);
    return SingleRotateWithRight(K3);
}
AvlTree MakeEmpty(AvlTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
Position Find(ElementType X, AvlTree T)
{
    if (T == NULL)
        return T;
    if (X > T->Element)
        return Find(X, T->Right);
    if (X < T->Element)
        return Find(X, T->Left);
    return T;
}
Position FindMin(AvlTree T)
{
    if (T == NULL)
        return NULL;
    if (T->Left == NULL)
        return T;
    return FindMin(T->Left);
}
Position FindMax(AvlTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;
    return T;
}
AvlTree Insert(ElementType X, AvlTree T)
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct AvlNode));
        if (T == NULL)
        {
            //error
        }
        else
        {
            T->Left = T->Right = NULL;
            T->Element = X;
            T->Height = 0;
        }
    }
    else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2)
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
    }
    else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRoateWithRight(T);
    }
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}
AvlTree Delete(ElementType X, AvlTree T)
{
    Position Tmp;
    if (T == NULL)
        return T;
    if (T->Element > X)
        T->Left = Delete(X, T->Left);
    else if (T->Element < X)
        T->Right = Delete(X, T->Right);
    else
    {
        if (T->Left && T->Right)
        {
            Tmp = FindMin(T->Right);
            T->Element = Tmp->Element;
            T->Right = Delete(T->Element, T->Right);
        }
        else
        {
            Tmp = T;
            if (T->Left == NULL)
                T = T->Right;
            else if (T->Right == NULL)
                T = T->Left;
            free(Tmp);
        }
    }
    return T;
}