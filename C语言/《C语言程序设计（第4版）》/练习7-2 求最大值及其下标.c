#include <stdio.h>
int main()
{
    int max = 0, maxIndex = 0;
    int n = 0, m = 0, i = 1;
    scanf("%d", &n);
    scanf("%d", &max);
    while (i < n)
    {
        scanf("%d", &m);
        if (m > max)
        {
            max = m;
            maxIndex = i;
        }
        i++;
    }
    printf("%d %d", max, maxIndex);
    return 0;
}
