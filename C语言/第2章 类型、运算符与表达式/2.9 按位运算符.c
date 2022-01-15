#include <stdio.h>
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & ~(~(~0 << n) << (p + 1 - n))) | (y & ~(~0 << n)) << (p + 1 - n);
}
int main()
{
    int x = 0b10010101;
    int y = 0b11110011;
    printf("%u\n", getbits(x, 4, 3));
    printf("%u\n", setbits(x, 4, 3, y));
}
