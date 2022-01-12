#include <stdio.h>
#include <limits.h>
int main()
{
    printf("limits.h\n");
    printf("signed char min = %d\n", SCHAR_MIN);
    printf("signed char max = %d\n", SCHAR_MAX);
    printf("signed int min = %d\n", INT_MIN);
    printf("signed int max = %d\n", INT_MAX);
    printf("unsigned char max = %u\n", UCHAR_MAX);
    printf("my limits\n");
    printf("signed char min = %d\n", -(char)((unsigned char)~0 >> 1) - 1);
    printf("signed char max = %d\n", (char)((unsigned char)~0 >> 1));
    printf("signed int min = %d\n", -(int)((unsigned int)~0 >> 1));
    printf("signed int max = %d\n", (int)((unsigned int)~0 >> 1));
    printf("unsigned char max = %u\n", (unsigned char)~0);
}