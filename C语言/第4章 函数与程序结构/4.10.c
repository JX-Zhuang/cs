#include <stdio.h>
#include <string.h>
void printd(int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}
void swap(int v[], int i, int j)
{
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void qsort(int v[], int left, int right)
{
    int index;
    if (left >= right)
        return;
    index = left;
    for (int i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
        {
            swap(v, i, ++index);
        }
    }
    swap(v, left, index);
    qsort(v, left, index - 1);
    qsort(v, index + 1, right);
}
void reverser(char s[], int left, int right)
{
    if (left >= right)
        return;
    char t = s[left];
    s[left] = s[right];
    s[right] = t;
    reverser(s, ++left, --right);
}
void reverse(char s[])
{
    reverser(s, 0, strlen(s) - 1);
}
int main()
{
    char s[] = "abcdef";
    reverse(s);
    printf("%s\n", s);
    return 0;
}