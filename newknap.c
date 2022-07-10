#include <stdio.h>
#include <conio.h>
void main()
{
 int i, j, n;
 float w, total = 0;
 printf("Enter num of item: ");
 scanf("%d", &n);
 printf("\nEnter maximum limit of bag: ");
 scanf("%f", &w);
 float weight[n + 1], profit[n + 1], p_by_w[n + 1], temp;
 for (i = 1; i <= n; i++)
 {
 printf("\nFor item %d weight and profit\n", i);
scanf("%f", &weight[i]);
 scanf("%f", &profit[i]);
 p_by_w[i] = profit[i] / weight[i];
 }
 for (i = 1; i <= n; i++)
 {
 for (j = n; j >= (i + 1); j--)
 {
 if (p_by_w[j] > p_by_w[j - 1])
 {
 temp = p_by_w[j];
 p_by_w[j] = p_by_w[j - 1];
 p_by_w[j - 1] = temp;
 temp = weight[j];
 weight[j] = weight[j - 1];
 weight[j - 1] = temp;
 temp = profit[j];
 profit[j] = profit[j - 1];
 profit[j - 1] = temp;
 }
 }
 }
 printf("\n\n w\t\t p\t\t p/w\n\n");
 for (i = 1; i <= n; i++)
 {
 printf("%f\t %f\t %f\n", weight[i], profit[i], p_by_w[i]);
 }
 while (w > 0)
 {
 for (i = 1; i <= n; i++)
 {
 if (weight[i] <= w)
 {
 w = w - weight[i];
 total = total + profit[i];
 }
 else
 {
 total = total + ((w * profit[i]) / weight[i]);
 w = 0;
 }
if (w == 0)
 break;
 }
 }
 printf("\n\nMaximum profit: %f\n\n", total);
}
