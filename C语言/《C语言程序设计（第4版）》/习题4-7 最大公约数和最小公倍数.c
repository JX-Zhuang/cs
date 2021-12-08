#include <stdio.h>
int a(int M, int N)
{
    int a, b;
    while (M % N != 0)
    {
        a = M % N;
        M = N;
        N = a;
    }
    return N;
}
int main()
{
    int M, N;
    scanf("%d%d", &M, &N);
    int max = a(M, N);
    int min = M * N / max;
    printf("%d %d", max, min);
    return 0;
}