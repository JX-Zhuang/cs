#ifndef _Queue_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Queue;
typedef int ElementType;

int IsEmpty(Queue Q);
Queue CreateQueue();
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif /* _Queue_h */