#include <stdio.h>

int main()
{
    int a[20], i, x, n;
    printf("How many element do you want to search?");
    scanf("%d", &n);
    printf("Enter the array element:\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("\nEnter the array element you want to search:");
    scanf("%d", &x);
    for (i = 0; i < n; ++i)
        if (a[i] == x)
            break;
    if (i < n)
        printf("The elememt is foumd at: %d", i);
    else
        printf("Element not found");

    return 0;
}