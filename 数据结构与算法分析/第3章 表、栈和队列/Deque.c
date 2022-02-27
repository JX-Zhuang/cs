#include <stdlib.h>
#include <stdio.h>
typedef int ElementType;
struct DequeRecord
{
    int Capacity;
    int Front;
    int Rear;
    ElementType *Array;
};
typedef struct DequeRecord *Deque;
Deque CreateDeque(int Size)
{
    Deque D = (Deque)malloc(sizeof(struct DequeRecord));
    if (D == NULL)
    {
        //error
    }
    D->Array = (ElementType *)malloc(sizeof(int) * (Size + 1));
    if (D->Array == NULL)
    {
        //error
    }
    D->Front = D->Rear = 0;
    D->Capacity = Size + 1;
    return D;
}
//把X插入D的前端
void Push(ElementType X, Deque D)
{
    if (IsFull(D))
    {
    }
    else
    {
        D->Front = (D->Front - 1 + D->Capacity) % D->Capacity;
        D->Array[D->Front] = X;
    }
}
//从D中删除前端并返回
ElementType Pop(Deque D)
{
    if (IsEmpty(D))
    {
        //error
    }
    else
    {
        ElementType T = D->Array[D->Front];
        D->Front = (D->Front + 1) % D->Capacity;
        return T;
    }
}
//把X插入D的尾端
void Inject(ElementType X, Deque D)
{
    if (IsFull(D))
    {
        //error
    }
    else
    {
        D->Array[D->Rear] = X;
        D->Rear = (D->Rear + 1) % D->Capacity;
    }
}
//把X的尾端删除并返回
ElementType Eject(Deque D)
{
    if (IsEmpty(D))
    {
        //error
    }
    else
    {
        D->Rear = (D->Rear - 1 + D->Capacity) % D->Capacity;
        return D->Array[D->Rear];
    }
}
int IsFull(Deque D)
{
    return (D->Front - 1 + D->Capacity) % D->Capacity == D->Rear;
}
int IsEmpty(Deque D)
{
    return D->Front == D->Rear;
}