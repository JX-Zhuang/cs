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