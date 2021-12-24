#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **s1, char **s2)
{
    char *temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}
int main()
{
    int l = 5, max = 80;
    char *arr[5];
    for (int i = 0; i < l; i++)
    {
        arr[i] = malloc(max * sizeof(char));
        scanf("%s", arr[i]);
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l - 1; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    printf("After sorted:\n");
    for (int i = 0; i < l; i++)
    {
        printf("%s\n", arr[i]);
    }
}