#ifndef _Queue_h
struct QueueRecord;
typedef struct QueueRecord *Queue;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode QueueNode;
typedef int ElementType;

int IsEmpty(Queue Q);
Queue CreateQueue();
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif /* _Queue_h */