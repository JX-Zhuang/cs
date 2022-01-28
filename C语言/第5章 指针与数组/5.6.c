#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000
#define MAXSTOR 5000

char *lineptr[MAXLINES];

int myReadlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines);
void myQsort(char *lineptr[], int left, int right);
int main()
{
    int nlines;
    char linestor[MAXSTOR];
    if ((nlines = myReadlines(lineptr, linestor, MAXLINES)) >= 0)
    {
        printf("linestor = %s\n", linestor);
        myQsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error:input too big to sort\n");
        return 1;
    }
}
#define MAXLINE 1000
int myGetline(char *, int);
char *alloc(int);
int myReadlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char *p = linestor, line[MAXLINES];
    char *linestop = linestor + MAXSTOR;
    nlines = 0;
    while ((len = myGetline(line, MAXLINE)) > 0)
        if (nlines >= maxlines || p + len > linestop)
            return -1;
        else
        {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
int myGetline(char s[], int lim)
{
    int i = 0, c;
    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void myQsort(char *v[], int left, int right)
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, last, left);
    myQsort(v, left, last - 1);
    myQsort(v, last + 1, right);
}