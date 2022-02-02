#include <stdio.h>
#include <string.h>
#define NKEYS (sizeof keytab / sizeof keytab[0])
struct key
{
    char *word;
    int count;
} keytab[] = {
    "auto",
    0,
    "break",
    0,
    "void",
    0,
    "while",
    0};
int binsearch(char *word, struct key tab[], int n)
{
    int low = 0, high = n - 1, mid, cond;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
int main()
{
    int index;
    char *test[] = {"auto", "void", "void", "while", "hello"};
    for (int i = 0; i < 5; i++)
    {
        if ((index = binsearch(test[i], keytab, NKEYS)) >= 0)
        {
            keytab[index].count++;
        }
    }
    for (int i = 0; i < NKEYS; i++)
    {
        printf("word:%s,count:%d\n", keytab[i].word, keytab[i].count);
    }
    return 0;
}