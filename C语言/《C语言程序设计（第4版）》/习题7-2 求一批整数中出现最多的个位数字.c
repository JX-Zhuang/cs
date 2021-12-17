#include <stdio.h>
int main()
{
    int n, num, arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num);
        if (num == 0)
        {
            arr[0]++;
        }
        else
        {
            while (num != 0)
            {
                arr[num % 10]++;
                num /= 10;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    printf("%d:", max);
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == max)
            printf(" %d", i);
    }
}
