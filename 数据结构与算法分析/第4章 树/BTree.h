#ifndef _BTree_H

struct BTreeNode;
typedef struct BTreeNode *Position;
typedef struct BTreeNode *BTree;
typedef int ElementType;

BTree MakeEmpty(BTree T);
BTree Insert(ElementType X, BTree T);
BTree Delete(ElementType X, BTree T);
Position Find(ElementType X, BTree T);


#endif /* _BTree_H */