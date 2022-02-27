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
    if (T == NULL)
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