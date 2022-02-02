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
struct key *binsearch(char *word, struct key *tab, int n)
{
    struct key *low = &tab[0], *high = &tab[n], *mid;
    int cond;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}
int main()
{
    struct key *p;
    char *test[] = {"auto", "void", "void", "while", "hello", "while", "break"};
    for (int i = 0; i < sizeof(test) / sizeof(test[0]); i++)
    {
        if ((p = binsearch(test[i], keytab, NKEYS)) != NULL)
        {
            p->count++;
        }
    }
    for (p = keytab; p < keytab + NKEYS; p++)
    {
        printf("word:%s,count:%d\n", p->word, p->count);
    }
    return 0;
}