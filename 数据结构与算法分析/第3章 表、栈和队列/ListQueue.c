#include <stdlib.h>
#include "ListQueue.h"

struct Node
{
    PtrToNode Next;
    PtrToNode Rear;
    ElementType Element;
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
    Q->Rear = Q;
    return Q;
}
void Enqueue(ElementType X, Queue Q)
{
    PtrToNode Node = malloc(sizeof(struct Node));
    if (Node == NULL)
    {
        //error
    }
    Node->Element = X;
    Node->Rear = NULL;
    Node->Next = NULL;
    Q->Rear->Next = Node;
    Q->Rear = Node;
}
ElementType Front(Queue Q)
{
    if (IsEmpty(Q))
    {
        //error
    }
    return Q->Next->Element;
}
void Dequeue(Queue Q)
{
    PtrToNode Tmp;
    if (!IsEmpty(Q))
    {
        Tmp = Q->Next;
        Q->Next = Q->Next->Next;
        if (IsEmpty(Q))
        {
            Q->Rear = NULL;
        }
        free(Tmp);
    }
}
ElementType FrontAndDequeue(Queue Q)
{
    ElementType X = Front(Q);
    Dequeue(Q);
    return X;
}