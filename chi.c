#include <stdio.h>
#include <math.h>

int main(void)
{
    int mat_1[10][10], n, m;
    float chisquared, mat_2[10][10], difference[10][10], sum;
    sum = 0.0;

    printf("enter number of rows for table 1: ");
    scanf("%d", &n);

    printf("enter number of colums for table 1: ");
    scanf("%d", &m);

    // creating the tables

    printf("Enter your matrix\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat_1[i][j]);
        }
    }

    printf("\nHere is your matrix:\n");

    for (int i = 0; i <= n; i++){
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat_1[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("enter number of rows for table 2: ");
    scanf("%d", &n);

    printf("enter number of colums for table 2: ");
    scanf("%d", &m);

    printf("Enter your matrix\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf("%f", &mat_2[i][j]);
        }
    printf("\nHere is your matrix:\n");
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%f ", mat_2[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // subtracting the values in the tables

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            difference[i][j] = mat_1[i][j] - mat_2[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d\t", difference[i][j]);
        
            // if(j == m-1){
            //     printf("\n");

            chisquared = (pow((difference[i][j]), 2) / mat_2[i][j]);
            printf("p-value = %f", chisquared);
            sum += chisquared;
            }
        }

    printf("\n");

    printf("total sum = %f", sum);
    
}