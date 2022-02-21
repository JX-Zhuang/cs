#include <stdlib.h>
#include "ArrayQueue.h"
#define MinQueueSize (5)
struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};
static int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}
int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}
int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}
Queue CreateQueue(int MaxElements)
{
    Queue Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
    {
        //error
    }
    Q->Capacity = MinQueueSize;
    MakeEmpty(Q);
    return Q;
}
void MakeEmpty(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}
void DisposeQueue(Queue Q)
{
    if (Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}
void Enqueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
    {
        //error
    }
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}
ElementType Front(Queue Q)
{
    if (IsEmpty(Q))
    {
        //error
        return 0;
    }
    return Q->Array[Q->Front];
}
void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
    {
        //error
    }
    else
    {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}
ElementType FrontAndDequeue(Queue Q)
{
    if (IsEmpty(Q))
    {
        //error
        return 0;
    }
    ElementType Element = Front(Q);
    Dequeue(Q);
    return Element;
}
