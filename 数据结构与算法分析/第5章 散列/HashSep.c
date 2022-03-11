#include <stdio.h>
#include <stdlib.h>
#include "HashSep.h"

struct ListNode
{
    ElementType Element;
    Position Next;
};

typedef Position List;

struct HashTbl
{
    int TableSize;
    List *TheLists;
};
int Hash(const char *Key, int TableSize)
{
    unsigned int HashVal = 0;
    while (*Key != '\0')
    {
        HashVal = (HashVal << 5) + *Key++;
    }
    return HashVal % TableSize;
}
HashTable InitializeTable(int TableSize)
{
    HashTable H;
    int i;
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
    {
        //error;
    }
    H->TableSize = TableSize; //prime素数
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL)
    {
        //error
    }
    for (i; i < H->TableSize; i++)
    {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
        {
            //error
        }
        else
        {
            H->TheLists[i]->Next = NULL;
        }
    }
}
Position Find(ElementType Key, HashTable H)
{
    Position P;
    List L;
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while (P != NULL && P->Element != Key)
        P = P->Next;
    return P;
}
void Insert(ElementType Key, HashTable H)
{
    Position P, NewCell;
    List L;
    P = Find(Key, H);
    if (P == NULL)
    {
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL)
        {
            //
        }
        else
        {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key;
            L->Next = NewCell;
        }
    }
}