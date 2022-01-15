#include <stdio.h>
// 2-4
// int any(char s[], char c);
// void squeeze(char s1[], char s2[]);
// int main()
// {
//     {
//         char s1[] = "";
//         char s2[] = "a";
//         squeeze(s1, s2);
//         printf("s1 = %s\n", s1);
//         printf("s2 = %s\n", s2);
//     }
//     {
//         char s1[] = "abcadef";
//         char s2[] = "a";
//         squeeze(s1, s2);
//         printf("s1 = %s\n", s1);
//         printf("s2 = %s\n", s2);
//     }
//     {
//         char s1[] = "aa";
//         char s2[] = "a";
//         squeeze(s1, s2);
//         printf("s1 = %s\n", s1);
//         printf("s2 = %s\n", s2);
//     }
//     {
//         char s1[] = "abcd";
//         char s2[] = "";
//         squeeze(s1, s2);
//         printf("s1 = %s\n", s1);
//         printf("s2 = %s\n", s2);
//     }
// }
// int any(char s[], char c)
// {
//     int i = 0;
//     while (s[i] != '\0')
//     {
//         if (s[i++] == c)
//             return i;
//     }

//     return -1;
// }
// void squeeze(char s1[], char s2[])
// {
//     int i, j;
//     for (i = j = 0; s1[i] != '\0'; i++)
//     {
//         if (any(s2, s1[i]) == -1)
//         {
//             s1[j++] = s1[i];
//         }
//     }
//     s1[j] = '\0';
// }

int any(char s1[], char s2[]);
int main()
{
    {
        char s1[] = "abcdecf",
             s2[] = "ghc";
        printf("%d\n", any(s1, s2));
    }
    {
        char s1[] = "abcdecf",
             s2[] = "g";
        printf("%d\n", any(s1, s2));
    }
    {
        char s1[] = "abcdecf",
             s2[] = "a";
        printf("%d\n", any(s1, s2));
    }
}
int any(char s1[], char s2[])
{
    int i = 0, j;
    while (s1[i] != '\0')
    {
        j = 0;
        while (s2[j] != '\0')
        {
            if (s1[i] == s2[j++])
                return i;
        }
        i++;
    }
    return -1;
}