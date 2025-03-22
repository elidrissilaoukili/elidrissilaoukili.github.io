// Find sum of positive and negative integers:
#include <stdio.h>
int main()
{
    int i, size, pos = 0, neg = 0;
    float avg;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    int array[size];
    printf("Enter numbers to find sum of positive and negative numbers\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    for (i = 0; i < size; i++)
    {
        if (array[i] > 0)
            pos += array[i];
        if (array[i] < 0)
            neg += array[i];
    }
    printf("The sum of positive inegers is %d\n", pos);
    printf("The sum of negative integers is %d\n", neg);
}
