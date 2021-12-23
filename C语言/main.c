#include <stdio.h>
#include <string.h>
void swap(char **s1, char **s2)
{
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main()
{
    int l = 5;
    char *arr[l];
    int i = 0;
    while (i < l)
    {
        scanf("%s", &arr[i++]);
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    printf("After sorted:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", arr[i]);
    }
}