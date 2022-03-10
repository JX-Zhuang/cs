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