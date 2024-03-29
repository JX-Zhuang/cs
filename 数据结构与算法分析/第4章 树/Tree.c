#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    return T;
}

Position FindMin(SearchTree T)
{
    if (T != NULL)
        while (T->Left != NULL)
        {
            T = T->Left;
        }
    return T;
}

Position FindMax(SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (T->Right == NULL)
        return T;
    return FindMax(T->Right);
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
        {
            //error
        }
        else
        {
            T->Element = X;
            T->Right = T->Left = NULL;
        }
    }
    else
    {
        if (X > T->Element)
        {
            T->Right = Insert(X, T->Right);
        }
        else if (X < T->Element)
        {
            T->Left = Insert(X, T->Left);
        }
    }
    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position Tmp;
    if (T == NULL)
    {
        //error
    }
    else if (X > T->Element)
    {
        T->Right = Delete(X, T->Right);
    }
    else if (X < T->Element)
    {
        T->Left = Delete(X, T->Left);
    }
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
            {
                T = T->Right;
            }
            else if (T->Right == NULL)
            {
                T = T->Left;
            }
            free(Tmp);
        }
    }
    return T;
}