#ifndef _HashSep_H

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef int ElementType;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);

#endif /* _HashSep_H */