#include <stdio.h>
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
int main(int argc, char *argv[])
{
    while (--argc > 0)
    {
        printf("%s%s", *++argv, argc > 1 ? " " : "");
    }
    printf("\n");
    return 0;
}