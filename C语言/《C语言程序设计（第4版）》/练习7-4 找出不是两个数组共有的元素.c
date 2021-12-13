#include <stdio.h>
int main()
{
    int n, m, result[40], k = 0;
    scanf("%d", &n);
    int arrN[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrN[i]);
    }
    scanf("%d", &m);
    int arrM[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arrM[i]);
    }
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        for (int j = 0; j < m; j++)
        {
            if (arrN[i] == arrM[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            result[k++] = arrN[i];
        }
    }
    for (int i = 0; i < m; i++)
    {
        flag = 1;
        for (int j = 0; j < n; j++)
        {
            if (arrM[i] == arrN[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            result[k++] = arrM[i];
        }
    }
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (result[i] == result[j])
            {
                for (int repCnt = j; repCnt < k - 1; repCnt++)
                {
                    result[repCnt] = result[repCnt + 1];
                }
                k--;
            }
        }
    }
    printf("%d", result[0]);
    for (int i = 1; i < k; i++)
    {
        printf(" %d", result[i]);
    }
    return 0;
}
