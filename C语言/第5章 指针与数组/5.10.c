#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINE 1000
#define LINES 100
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
int main1(int argc, char *argv[])
{
    int i = 1;
    for (; i < argc; i++)
    {
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    }
    printf("\n");
    return 0;
}
int main2(int argc, char *argv[])
{
    printf("%d\n", argc);
    while (--argc > 0)
    {
        printf("%s%s", *++argv, argc > 1 ? " " : "");
    }
    printf("\n");
    return 0;
}
// find -x -n parttern
int find(int argc, char *argv[])
{
    long lineno = 0;
    char line[MAXLINE];
    int c, number = 0, except = 0, found = 0;
    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find:illegal option %c\n", c);
                found = -1;
                break;
            }
    if (argc != 1)
    {
        printf("Usage:find -x -n pattern\n");
    }
    else
    {
        while (myGetline(line, MAXLINE) > 0)
        {
            ++lineno;
            if ((strstr(line, *argv) != NULL) != except)
            {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}
int tail(int argc, char *argv[])
{
    char line[MAXLINE];
    char *lineptr[LINES];
    int n = 10, c, m = 0, flag = 0, i = 0, last = 0, len;
    if (--argc > 0 && (*++argv)[0] == '-')
    {
        while (isdigit(c = *++argv[0]))
        {
            m = c - '0' + m * 10;
            flag = 1;
        }
        if (flag)
            n = m;
    }
    while ((len = myGetline(line, MAXLINE)) > 0)
    {
        lineptr[last] = (char *)malloc(len);
        strcpy(lineptr[last], line);
        last++;
    }
    if (last > n)
    {
        i = last - n;
    }
    for (; i < last; i++)
    {
        printf("%s", lineptr[i]);
    }
    return 0;
}
int main(int argc, char *argv[])
{
    return tail(argc, argv);
}