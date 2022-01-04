#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd(struct ListNode **L);
void printlist(struct ListNode *L)
{
    struct ListNode *p = L;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}
struct ListNode *readlist()
{
    struct ListNode *head = NULL, *temp, *p;
    while (1)
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d", &p->data);
        if (p->data == -1)
            break;
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            temp->next = p;
        temp = p;
    }

    return head;
}
struct ListNode *getodd(struct ListNode **L)
{
    struct ListNode *odd = NULL, *even = NULL, *p, *oddTemp, *evenTemp;
    while (*L)
    {
        p = (struct ListNode *)malloc(sizeof(struct ListNode *));
        p->data = (*L)->data;
        p->next = NULL;
        if (p->data % 2)
        {
            if (odd == NULL)
                odd = p;
            else
                oddTemp->next = p;
            oddTemp = p;
        }
        else
        {
            if (even == NULL)
                even = p;
            else
                evenTemp->next = p;
            evenTemp = p;
        }
        *L = (*L)->next;
    }
    *L = even;
    return odd;
}