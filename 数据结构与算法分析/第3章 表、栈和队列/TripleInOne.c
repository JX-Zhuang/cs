#include <stdlib.h>
#include <stdio.h>
typedef enum
{
    true = 1,
    false = 0
} bool;
typedef struct
{
    int *arr;
    int top[3];
    int size;
} TripleInOne;

TripleInOne *tripleInOneCreate(int stackSize)
{
    TripleInOne *obj = (TripleInOne *)malloc(sizeof(TripleInOne));
    obj->arr = (int *)malloc(sizeof(int) * stackSize * 3);
    obj->top[0] = -1;
    obj->top[1] = stackSize - 1;
    obj->top[2] = 2 * stackSize - 1;
    obj->size = stackSize;
    return obj;
}

void tripleInOnePush(TripleInOne *obj, int stackNum, int value)
{
    if (obj->top[stackNum] < (stackNum + 1) * obj->size - 1)
        obj->arr[++(obj->top[stackNum])] = value;
}

int tripleInOnePop(TripleInOne *obj, int stackNum)
{
    if (obj->top[stackNum] > stackNum * obj->size - 1)
        return obj->arr[obj->top[stackNum]--];
    return -1;
}

int tripleInOnePeek(TripleInOne *obj, int stackNum)
{
    if (obj->top[stackNum] > obj->size * stackNum - 1)
        return obj->arr[obj->top[stackNum]];
    return -1;
}

bool tripleInOneIsEmpty(TripleInOne *obj, int stackNum)
{
    return obj->top[stackNum] == stackNum * obj->size - 1;
}

void tripleInOneFree(TripleInOne *obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your TripleInOne struct will be instantiated and called as such:
 * TripleInOne* obj = tripleInOneCreate(stackSize);
 * tripleInOnePush(obj, stackNum, value);
 
 * int param_2 = tripleInOnePop(obj, stackNum);
 
 * int param_3 = tripleInOnePeek(obj, stackNum);
 
 * bool param_4 = tripleInOneIsEmpty(obj, stackNum);
 
 * tripleInOneFree(obj);
*/