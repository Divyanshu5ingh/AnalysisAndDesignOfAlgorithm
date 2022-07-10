#include <stdio.h>
int main()
{
    int num_denominations, coin_list[100], use_these[100], i, owed;

    printf("Enter number of denominations : ");
    scanf("%d", &num_denominations);

    printf("\nEnter the denominations in descending order: ");

    for (i = 0; i < num_denominations; i++)
    {
        scanf("%d", &coin_list[i]);
        // use_these[i] = 0;
    }

    printf("\nEnter the amount owed : ");
    scanf("%d", &owed);

    for (i = 0; i < num_denominations; i++)
    {
        use_these[i] = owed / coin_list[i];
        owed %= coin_list[i];
    }

    printf("\nSolution: \n");
    for (i = 0; i < num_denominations; i++)
    {
        printf("%dx%d ", coin_list[i], use_these[i]);
    }
}