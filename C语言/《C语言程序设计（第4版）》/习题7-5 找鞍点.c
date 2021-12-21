#include <stdio.h>
int main()
{
    int n, maxIndex, flag = 1;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        maxIndex = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] >= arr[i][maxIndex])
            {
                maxIndex = j;
            }
        }
        flag = 1;
        for (int k = 0; k < n; k++)
        {
            if (arr[k][maxIndex] < arr[i][maxIndex])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("%d %d", i, maxIndex);
            return 0;
        }
    }
    printf("NONE");
    return 0;
}