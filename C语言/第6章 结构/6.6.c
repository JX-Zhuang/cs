#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define IN 1
struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};
#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval += *s + 31 * hashval;
    return hashval % HASHSIZE;
}
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (!np || (np->name = name) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        free((void *)np->defn);
    if ((np->defn = defn) == NULL)
        return NULL;
    return np;
}
void undef(char *s)
{
    unsigned hashval = hash(s);
    struct nlist *prev = NULL, *np;
    for (np = hashtab[hashval]; np != NULL; np = np->next)
    {
        if (strcmp(s, np->name) == 0)
            break;
        prev = np;
    }
    if (np != NULL)
    {
        if (prev == NULL)
            hashtab[hashval] = np->next;
        else
            prev->next = np->next;
        free(np->name);
        free(np->defn);
        free(np);
    }
}