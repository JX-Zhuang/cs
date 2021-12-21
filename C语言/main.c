#include <stdio.h>
int main()
{
    int n;
    char *arr[] = {
        "Jan",
        "Feb",
        "March",
        "Apr",
        "May",
        "June",
        "July",
        "Auguse",
        "September",
        "Oct",
        "Nov",
        "Dec"};
    scanf("%d", &n);
    printf("%s\n", arr[n - 1]);
    return 0;
}
