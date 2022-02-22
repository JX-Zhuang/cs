#include <stdio.h>
#include <stdlib.h>
#include "ListQueue.h"
struct QueueRecord
{
    QueueNode Front;
    QueueNode Rear;
};
struct Node
{
    PtrToNode Next;
    ElementType Element;
};

int IsEmpty(Queue Q)
{
    return Q->Front->Next == NULL;
}
Queue CreateQueue()
{
    Queue Q = malloc(sizeof(struct Node));
    if (Q == NULL)
    {
        //error
    }
    Q->Front = Q->Rear = malloc(sizeof(struct Node));
    Q->Front->Next = NULL;
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
    return Q->Front->Next->Element;
}
void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
    {
        //error
        return;
    }
    PtrToNode Tmp, Front;
    Front = Q->Front;
    Tmp = Front->Next;
    Front->Next = Front->Next->Next;
    free(Tmp);
    if (IsEmpty(Q))
    {
        Q->Rear = Front;
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
    QueueNode Front = Q->Front->Next;
    while (Front)
    {
        printf("%d\n", Front->Element);
        Front = Front->Next;
    }
    printf("Print Queue Over \n");
}
int main()
{
    Queue Q = CreateQueue();
    Enqueue(1, Q);
    Enqueue(2, Q);
    PrintQueue(Q);
    Enqueue(3, Q);
    Enqueue(4, Q);
    PrintQueue(Q);
    Dequeue(Q);
    Dequeue(Q);
    PrintQueue(Q);
    Dequeue(Q);
    Dequeue(Q);
    PrintQueue(Q);
    Enqueue(1, Q);
    Enqueue(2, Q);
    Enqueue(3, Q);
    Enqueue(4, Q);
    PrintQueue(Q);

    return 0;
}