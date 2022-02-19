#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord
{
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};
