#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem(struct ListNode *L, int m);
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
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}
struct ListNode *readlist()
{
    struct ListNode *head, *temp, *p;
    head = NULL;
    while (1)
    {
        p = malloc(sizeof(struct ListNode));
        scanf("%d", &p->data);
        if (p->data == -1)
        {
            break;
        }
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            temp->next = p;
        temp = p;
    }
    return head;
}
struct ListNode *deletem(struct ListNode *L, int m)
{
    struct ListNode *head = malloc(sizeof(struct ListNode)), *tail, *p = L;
    head->next = L;
    tail = head;
    while (p)
    {
        if (p->data == m)
        {
            free(tail->next);
            tail->next = p->next;
        }
        else
        {
            tail = p;
        }
        p = p->next;
    }
    L = head->next;
    head->next = NULL;
    free(tail);
    return L;
}
/* 你的代码将被嵌在这里 */