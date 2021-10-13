#include<stdio.h>

int main()
{
    int arr[2][2];
    int i=0,j=0;
    int abc[2][2]={1,2,3,4};
    int bcd[][2] = {2,1,4,3};
  //  int cde[][]= {8,6,4,2};
    int def[2][3]={4,5,6,7};
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        printf("arr[%d][%d]= %d\n",i,j,abc[i][j]);
    }
     for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        printf("arr[%d][%d]= %d\n",i,j,bcd[i][j]);
    }
  /*   for(i=0;i<=1;i++)
    {
        for(j=0;j<=2;j++)
        printf("arr[%d][%d]= %d\n",i,j,cde[i][j]);
    }*/
     for(i=0;i<=1;i++)
    {
        for(j=0;j<=2;j++)
        printf("arr[%d][%d]= %d\n",i,j,def[i][j]);
    }
    return 0;
}


