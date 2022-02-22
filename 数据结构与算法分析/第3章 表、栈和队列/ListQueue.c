#include <stdio.h>
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
        free(Tmp);
        if (IsEmpty(Q))
        {
            Q->Rear = Q;
        }
    }
}
ElementType FrontAndDequeue(Queue Q)
{
    ElementType X = Front(Q);
    Dequeue(Q);
    return X;
}
void PrintQueue(Queue Q)
{
    Q = Q->Next;
    while (Q)
    {
        printf("%d\n", Q->Element);
        Q = Q->Next;
    }
}
int main()
{
    Queue Q = CreateQueue();
    Enqueue(1, Q);
    Enqueue(2, Q);
    Enqueue(3, Q);
    Enqueue(4, Q);

    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);
    Dequeue(Q);

    Enqueue(1, Q);
    Enqueue(2, Q);
    PrintQueue(Q);

    return 0;
}