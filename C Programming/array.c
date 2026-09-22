//3.program in a to create array of size four and perform addition of all elements.

#include <stdio.h>

int main()
{
    int a[4], i, sum = 0;

    printf("Enter 4 elements:\n");

    for(i = 0; i < 4; i++)
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    printf("Addition of all elements = %d", sum);

    return 0;
}