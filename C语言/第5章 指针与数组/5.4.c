#include <stdio.h>
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
int strlen1(char *s)
{
    char *p = s;
    while (*p != '\0')
    {
        p++;
    }
    return p - s;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int *p = &arr[0], *q = &arr[1];
    printf("p = %p\n", p);
    printf("q = %p\n", q);
    printf("%ld\n", q - p);
    char s[] = "abcdef";
    printf("s[0] = %p\n", &s[0]);
    printf("s[1] = %p\n", &s[1]);
    printf("%ld\n", &s[1] -&s[0]);
    printf("s length = %d\n", strlen1(s));
    return 0;
}