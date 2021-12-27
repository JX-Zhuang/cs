#include <stdio.h>
#include <math.h>
int main()
{
    char arr[100];
    int n = 0, c, sum = 0, flag = 1, end = 1, num;
    while ((c = getchar()) != '#')
    {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c == '-' && n == 0))
        {
            arr[n] = c;
            n++;
        }
    }
    if (arr[0] == '-')
    {
        flag = -1;
        end = 2;
    }
    for (int i = n; i >= end; i--)
    {

        if (arr[i - 1] >= '0' && arr[i - 1] <= '9')
        {
            num = (arr[i - 1] - 48);
        }
        else
        {
            if (arr[i - 1] == 'a' || arr[i - 1] == 'A')
                num = 10;
            else if (arr[i - 1] == 'b' || arr[i - 1] == 'B')
                num = 11;
            else if (arr[i - 1] == 'c' || arr[i - 1] == 'C')
                num = 12;
            else if (arr[i - 1] == 'd' || arr[i - 1] == 'D')
                num = 13;
            else if (arr[i - 1] == 'e' || arr[i - 1] == 'E')
                num = 14;
            else if (arr[i - 1] == 'f' || arr[i - 1] == 'F')
                num = 15;
        }
        sum += num * pow(16, n - i);
    }
    printf("%d", sum * flag);
    return 0;
}