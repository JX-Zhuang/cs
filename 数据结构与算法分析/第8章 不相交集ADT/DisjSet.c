#include "DisjSet.h"
#define NumSets 10
void Initilialize(DisjSet S)
{
    int i;
    for (i = NumSets; i > 0; i--)
        S[i] = 0;
}
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    S[Root2] = Root1;
}
SetType Find(ElementType X, DisjSet S)
{
    if (S[X] <= 0)
    {
        return X;
    }
    return S[X] = Find(S[X], S);
}
