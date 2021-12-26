#include <stdio.h>
struct Book
{
    double price;
    char name[30];
};
int main()
{
    int n;
    scanf("%d\n", &n);
    struct Book books[n];
    for (int i = 0; i < n; i++)
    {
        scanf("Programming in %s\n", books[i].name);
        scanf("%lf\n", &books[i].price);
    }
    int maxIndex = 0, minIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (books[i].price < books[minIndex].price)
            minIndex = i;
        if (books[i].price > books[maxIndex].price)
            maxIndex = i;
    }
    printf("%.2f, Programming in %s\n", books[maxIndex].price, books[maxIndex].name);
    printf("%.2f, Programming in %s\n", books[minIndex].price, books[minIndex].name);
    return 0;
}