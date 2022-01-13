#include <stdio.h>
int htoi(char s[]);
int main()
{
    char s[] = "0x123AF";
    int a = htoi("0x");
    printf("%s = %d", s, a);
}
int htoi(char s[])
{
    
}