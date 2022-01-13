#include <stdio.h>
int htoi(char s[]);
int main()
{
    printf("%s = %d\n", "0x123AF", htoi("0x123AF"));
    printf("%s = %d\n", "0X123aF", htoi("0X123aF"));
    printf("%s = %d\n", "0xF", htoi("0xF"));
    printf("%s = %d\n", "123", htoi("123"));
    printf("%s = %d\n", "0", htoi("0"));
}
int htoi(char s[])
{
    int i = 0, n = 0, temp;
    if (s[i] == '0')
    {
        i++;
        if (s[i] == 'x' || s[i] == 'X')
            i++;
    }
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            temp = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            temp = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            temp = s[i] - 'A' + 10;
        }
        else
        {
            break;
        }

        n = temp + n * 16;
        i++;
    }
    return n;
}