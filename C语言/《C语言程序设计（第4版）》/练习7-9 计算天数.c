#include <stdio.h>
int main()
{
    int y, m, d;
    int month_array[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d/%d/%d", &y, &m, &d);
    int sum = d;
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
    {
        month_array[1] = 29;
    }
    for (int i = 0; i < m - 1; i++)
    {
        sum += month_array[i];
    }
    printf("%d", sum);
    return 0;
}
