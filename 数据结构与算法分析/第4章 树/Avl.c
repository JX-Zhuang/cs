#include <stdio.h>
#include <stdlib.h>
#include "Avl.h"
struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};