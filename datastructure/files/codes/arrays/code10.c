// Array elements in reverse order:
#include <stdio.h>
int main()
{
    int i, a[100], c, k, j, n, num;
    printf("Enter number of elements in array\n");
    scanf("%d", &num);
    printf("Enter numbers\n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Before arranging \n");
    for (i = 0; i < num; i++)
        printf("%d\n", a[i]);
    k = num;
    while (k >= 0)
    {
        for (j = 0; j < k - 1; j++)
        {
            // using swap method c=a[j];
            a[j] = a[j + 1];
            a[j + 1] = c;
        }
        k--;
    }
    printf("After arranging \n");
    for (i = 0; i < num; i++)
        printf("%d\n", a[i]);
}
