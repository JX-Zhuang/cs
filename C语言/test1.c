#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printArrAddress(int arr[]);
void strcopy(char *s, char *t);
void printStr(char *s);
int main()
{
    // int a = 1;
    // char *str1 = "hello world!";
    // char *str2 = (char *)malloc(strlen(str1) + 1);
    // printf("a    = %p\n", &a);
    // printf("str1 = %p\n", &str1);
    // printf("str2 = %p\n", &str2);
    // strcopy(str2, str1);
    // printStr(str2);
    int a[] = {1, 2, 3};
    printf("%p\n", &a);
    printArrAddress(a);
    return 0;
}
void strcopy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}
void printStr(char *s)
{
    while (*s)
    {
        printf("%c", *s++);
    }
}
void printArrAddress(int arr[])
{
    printf("%p", &arr);
}