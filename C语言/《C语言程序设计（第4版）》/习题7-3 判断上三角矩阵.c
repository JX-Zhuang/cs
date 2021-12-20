#include <stdio.h>
int main()
{
    int t, n, yes = 1, num;
    scanf("%d", &t);
    int arr[t];
    for (int i = 1; i <= t; i++)
    {
        arr[i-1] = 1;
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                scanf("%d", &num);
                if (k < j && num != 0)
                {
                    arr[i-1] = 0;
                }
            }
        }
    }
    for(int i = 0;i<t;i++){
        if (arr[i])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}