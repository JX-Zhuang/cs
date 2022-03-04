#ifndef _AvlTree_H

struct AvlNode;
typedef struct AvlNode *Postion;
typedef struct AvlNode *AvlTree;
typedef int ElementType;

AvlTree MakeEmpty(AvlTree T);
Postion Find(ElementType X, AvlTree T);
Postion FindMin(AvlTree T);
Postion FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Postion P);

#endif /* _AvlTree_H */