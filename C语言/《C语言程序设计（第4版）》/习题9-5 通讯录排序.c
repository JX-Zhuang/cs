#include <stdio.h>
struct Person
{
    char name[100];
    int birth;
    char phone[180];
};
void swap(struct Person *p1, struct Person *p2);
void sort(struct Person arr[], int length);
void input(struct Person arr[], int n);
void output(struct Person arr[], int n);
int main()
{
    int n = 0;
    scanf("%d", &n);
    struct Person arr[n];
    input(arr, n);
    sort(arr, n);
    output(arr, n);
    return 0;
}
void swap(struct Person *p1, struct Person *p2)
{
    struct Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void sort(struct Person arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (arr[j].birth > arr[j + 1].birth)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void input(struct Person arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("\n");
        scanf("%s %d %s\n", arr[i].name, &arr[i].birth, arr[i].phone);
    }
}
void output(struct Person arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %s\n", arr[i].name, arr[i].birth, arr[i].phone);
    }
}
