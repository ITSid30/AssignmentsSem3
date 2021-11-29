#include <stdio.h>

int main(void) {
  int r1,c1,r2,c2;
printf("enter the Rows and Columns of Matrix 1 :\n");
scanf("%d%d",&r1,&c1);
printf("enter the Rows and Columns of Matrix 2 :\n");
scanf("%d%d",&r2,&c2);
    int a[r1][c1];
    printf("\n*********Enter the Elements in matrix 1 **********\n");
    for(int i=0; i<r1; i++)
    {
    for(int j=0; j<c1; j++)
    {
        scanf("%d", &a[i][j]);
    }
    }
    int b[r2][c2];
    printf("\n*********Enter the Elements in matrix 2 **********\n");
    for(int i=0; i<r2; i++)
    {
    for(int j=0; j<c2; j++)
    {
        scanf("%d", &b[i][j]);
    }
    }
    printf("\n-----------The two Matrices are : -----------\n");
    for(int i=0; i<r1; i++)
    {
    for(int j=0; j<c1; j++)
    {
      printf("%d\t", a[i][j]);
    }
    printf("\n");
    }
    printf("\n");
    for(int i=0; i<r1; i++)
    {
    for(int j=0; j<c1; j++)
    {
      printf("%d\t", b[i][j]);
    }
    printf("\n");
    }
    printf("\n------------------------------------------------\n");

    if(r1==r2 && c1==c2)
    {
    int d[r1][c1];
    printf("\n*********The Addition of 2 matrices is **********\n");
    for(int i=0; i<r1; i++)
    {
    for(int j=0; j<c1; j++)
    {
        d[i][j] = a[i][j] + b[i][j];
        printf("%d\t",d[i][j]);
    }
    printf("\n");
    }
    }
    else
    {
        printf("\n The Addition of matrices is not possible...\n");
    }

    if(c1 == r2)
    {
    int sum = 0;
    printf("\n***** The Multiplication of 2 matrices is *****\n");
    for(int i=0; i<r1; i++)
    {
    for(int j=0; j<c2; j++)
    {
     int sum = 0;
      for(int k=0 ; k<r2 ; k++)
       {
        sum = sum + ( a[i][k] * b[k][j] );
       }
     printf("%d\t",sum);
    }
    printf("\n");
    }
    }
    else
    {
        printf("\n Multiplication of matrices is not possible...\n");
    }
  return 0;
}
