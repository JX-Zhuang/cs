#include <stdio.h>
int main()
{
    int m[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int flag = 1, arr[20], doubleArr[20], i = 0, c, a = 0, sum = 0;
    while ((c = getchar()) != '\n')
    {
        arr[i] = c - 48;
        m[arr[i]]++;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        sum = arr[j] * 2 + a;
        if (sum >= 10)
        {
            doubleArr[j] = (sum) % 10;
            a = sum / 10;
        }
        else
        {
            doubleArr[j] = sum;
            a = 0;
        }
    }
    if (a != 0)
    {
        doubleArr[0] += a * 10;
    }
    for (int k = 0; k < i; k++)
    {
        m[doubleArr[k]]--;
    }
    for (int i = 0; i < 10; i++)
    {
        if (m[i] != 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    for (int k = 0; k < i; k++)
    {
        printf("%d", doubleArr[k]);
    }
    return 0;
}