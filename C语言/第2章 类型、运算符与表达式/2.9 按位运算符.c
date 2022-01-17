#include <stdio.h>
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & ~(~(~0 << n) << (p + 1 - n))) | (y & ~(~0 << n)) << (p + 1 - n);
}
unsigned invert(unsigned x, int p, int n)
{
    // int bits = (x >> (p + 1 - n)) & (~(~0 << n));
    // return (x ^ (bits << (p + 1 - n)) ^ (0)) | (~(bits | (~0 << n)) << (p + 1 - n));
    return x ^ (~(~0 << n) << (p + 1 - n));
}
int wordlength()
{
    int i;
    unsigned v = (unsigned)~0;
    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}
unsigned rightrot(unsigned x, int n)
{
    if ((n = n % wordlength()) > 0)
    {
        int bits = x & (~(~0 << n));
        return (x >> n) | (bits << (wordlength() - n));
    }
    return x;
    
    // int rbit;
    // while (n-- > 0)
    // {
    //     rbit = (x & 1) << (wordlength() - 1);
    //     x = x >> 1;
    //     x = x | rbit;
    // }
    // return x;
}
int main()
{
    int x = 0b10010101;
    int y = 0b11110011;
    printf("%u\n", getbits(x, 4, 3));
    printf("%u\n", setbits(x, 4, 3, y));
    printf("%u\n", invert(x, 4, 3));
    printf("%u\n", rightrot(y, 3));
}
