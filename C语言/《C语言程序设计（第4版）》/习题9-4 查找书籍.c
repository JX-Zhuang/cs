#include <stdio.h>
struct Book
{
    double price;
    char name[31];
};
int main()
{
    int n;
    scanf("%d", &n);
    struct Book books[n];
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        gets(books[i].name);
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
    printf("%.2f, %s\n", books[maxIndex].price, books[maxIndex].name);
    printf("%.2f, %s\n", books[minIndex].price, books[minIndex].name);
    return 0;
}