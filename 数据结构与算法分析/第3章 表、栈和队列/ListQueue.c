#include <stdlib.h>
#include "ListQueue.h"

struct Node
{
    PtrToNode Next;
    ElementType X;
};

int IsEmpty(Queue Q)
{
    return Q->Next == NULL;
}
Queue CreateQueue()
{
    Queue Q = malloc(sizeof(struct Node));
    if (Q == NULL)
    {
        //error
    }
    Q->Next = NULL;
    return Q;
}
void Enqueue(ElementType X, Queue Q)
{
}
ElementType Front(Queue Q)
{
    if (IsEmpty(Q))
    {
        //error
    }
    return Q->Next->X;
}
void Dequeue(Queue Q)
{
    PtrToNode Tmp;
    if (!IsEmpty(Q))
    {
        Tmp = Q->Next;
        Q->Next = Q->Next->Next;
        free(Tmp);
    }
}
ElementType FrontAndDequeue(Queue Q)
{
    ElementType X = Front(Q);
    Dequeue(Q);
    return X;
}