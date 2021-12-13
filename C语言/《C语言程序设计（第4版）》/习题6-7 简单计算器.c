#include <stdio.h>
int main()
{
    int sum = 0, n = 0;
    char op = '0';
    scanf("%d", &sum);
    while (op != '=')
    {
        scanf("%c", &op);
        if (op == '=')
            break;
        scanf("%d", &n);
        if (op == '+')
        {
            sum += n;
        }
        else if (op == '-')
        {
            sum -= n;
        }
        else if (op == '*')
        {
            sum *= n;
        }
        else if (op == '/')
        {
            if (n == 0)
            {
                printf("ERROR");
                return 0;
            }
            else
            {
                sum /= n;
            }
        }
        else
        {
            printf("ERROR");
            return 0;
        }
    }
    printf("%d", sum);
    return 0;
}
