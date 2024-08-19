#include<stdio.h>

int main()
{
    int a, r, n;
    a = 2;
    r = 3;

    printf("enter the value of n : ");
    scanf("%d", &n);

    int gp = a;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        printf("%d + ", gp);
        sum += gp;
        gp *= r;
    }

    printf("...");
    printf("\n");

    printf("sum = %d", sum);

    return 0;
}