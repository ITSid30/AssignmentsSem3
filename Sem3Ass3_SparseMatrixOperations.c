/*Name : Siddhesh Ramvijay Bajad  
  Rollno : SYITA104
  Sparse Matrix Operations .*/

#include <stdio.h>

int addmatrix(int a[50][3], int b[50][3], int v1, int v2, int r1, int c1, int r2, int c2)
{
  int sum[50][3];
  if(r1!= r2 || c1!= c2)
  {
    printf("Not Allowed to add.\n");
    return 0;
  }

  int i=1,j=1, k=1;
    while(i<=v1 || j<=v2)
    {
      if(a[i][0] < b[j][0])
      {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++, k++;
      }
      else if(a[i][0] > b[j][0])
      {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++, k++;
      }
      else if(a[i][1] < b[j][1])
      {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++, k++;
      }
      else if(a[i][1] > b[j][1])
      {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++, k++;
      }
      else 
      {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2] + b[j][2];
        i++,j++,k++;
      }
    }  
    
    sum[0][0] = r1;
    sum[0][1] = c1;
    sum[0][2] = k-1;
    
  
  printf("\n\nThe Sum of Marices is :\nR C V\n");
  printf("%d %d %d\n", r1,c1,k-1);
  for(int n=1;n<k;n++)
  {
    printf("%d %d %d\n", sum[n][0]-1, sum[n][1], sum[n][2]);
  }
  printf("\n--------------------------------------------------\n");
  return 0;
}  

int transpose(int p[50][3], int v, int c, int r)
{
  int pt[50][3];
  pt[0][0] = p[0][1];
  pt[0][1] = p[0][0];
  pt[0][2] = p[0][2];
  if(v == 0)
  return 0;

  int i=0, j=1, k=1;
  for(i=0;i<c;i++)
  {
    for(j=1;j<=v;j++)
    {
      if(p[j][1] == i)
      {
        pt[k][0] = p[j][1];
        pt[k][1] = p[j][0];
        pt[k][2] = p[j][2];
        k++;
      }
    }
  }
  printf("The Transpose Matrix Representaation is :\nR C V\n%d %d %d\n", r,c,v);
  for(int i=1;i<k;i++)
  {
    printf("%d %d %d\n", pt[i][0], pt[i][1]-1, pt[i][2]);
  }
  printf("--------------------------------------------------\n\n");
  return 0;
}

void fasttranspose(int p[50][3], int v, int c, int r)
{
  int index[c+1], total[c] , count;

  for(int i=0;i<c;i++)
  {
    total[i] = 0;
  }
  int colnum;
  for(int i=1;i<=v;i++)
  {
    colnum = p[i][1];

    total[colnum]++;
  }

  index[0] = 1;
  for(int i=1;i<c+1;i++)
  {
    index[i] = index[i-1] + total[i-1];
  }

  /*for(int i=0;i<c;i++)
  {
    printf("%d ", total[i]);
  }printf("\n");
  for(int i=0;i<c+1;i++)
  {
    printf("%d ", index[i]);
  }printf("\n"); */
  int ptrans[50][3];
  ptrans[0][0] = p[0][1];
  ptrans[0][1] = p[0][0];
  ptrans[0][2] = p[0][2];

  for(int i=1;i<=v;i++)
  {
    int m = p[i][1];
    int n = index[m];
    index[m] = index[m] +1;
    ptrans[n][0] = p[i][1];
    ptrans[n][1] = p[i][0];
    ptrans[n][2] = p[i][2];

  }

  printf("\nThe Fast Transpose of Matrix is :  \nR C V \n%d %d %d\n", ptrans[0][0], ptrans[0][1], ptrans[0][2]);
  for(int i=1;i<=v;i++)
  {
    printf("%d %d %d\n", ptrans[i][0], ptrans[i][1]-1 , ptrans[i][2]);
  }
  printf("\n--------------------------------------------------\n");

}

int main(void) {
  int a[50][3], b[50][3], sum[50][3] ={0}, r1,c1,v1, r2,c2,v2;
  
  while(1)
  {
  int ch;
  printf("\nMENU OF SPARSE MATRIX OPERATIONS\n1. Make Matrix A.\n2. Make Matrix B.\n3. Addition of Matrices.\n4. Simple Transpose. \n5. Fast Transpose. \n6. Exit.\nEnter your Choice :   ");
  scanf("%d", &ch);
  
  
  switch(ch)
  {
  
  case 1 :
  printf("\nFor Matrix A :\n");
  printf("\nEnter the No. of Rows and Columns, Nonzero Values :\n");
  scanf("%d %d %d", &r1,&c1,&v1);
  a[0][0] = r1;
  a[0][1] = c1;
  a[0][2] = v1; 
  printf("\nEnter Non Zero elements of Matrix A in (R+1) C V Format:\n");
  for(int i=1;i<=v1;i++)
  {
    scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
  }
  printf("\nMatrix A :\nR C V\n");
  printf("%d %d %d\n", r1, c1, v1);
  for(int i=1;i<=v1;i++)
  {
    printf("%d %d %d\n", a[i][0]-1, a[i][1], a[i][2]);
  }
  printf("-----------------------------------------\n");
  break;

  case 2:
  printf("\nFor Matrix B :\n");
  printf("\nEnter the No. of Rows and Columns, Nonzero Values :\n");
  scanf("%d %d %d", &r2,&c2,&v2);
  b[0][0] = r2;
  b[0][1] = c2;
  b[0][2] = v2; 
  printf("\nEnter the nonzero elements of B in (R+1) C V Format :\n");
  for(int i=1;i<=v2;i++)
  {
    scanf("%d %d %d", &b[i][0], &b[i][1], &b[i][2]);
  }

  printf("\nThe Matrix B is :\nR C V\n");
  printf("%d %d %d\n", r2, c2, v2);
  for(int i=1;i<=v2;i++)
  {
    printf("%d %d %d\n", b[i][0]-1, b[i][1], b[i][2]);
  }
  printf("-----------------------------------------\n");
  break;

  case 3:
  addmatrix(a,b, v1,v2, r1, c1, r2 , c2);
  break;
  
  case 4:
  while(1) {
  int choice;
  printf("\nSimple Transpose of :\n1. Enter 1 for A\n2.Enter 2 for B\n3. Enter any other choice to Exit\nEnter choice :  ");
  scanf("%d", &choice);
  if(choice ==1)
  {
    transpose(a, v1, c1, r1);
  }
  else if(choice == 2)
  {
    transpose(b, v2, c2, r2);
  }
  else{
    printf("\nExited Simple Matrix Function.\n");
    break;
  }
  }
  break;

  case 5:
  while(1) {
  int choice;
  printf("\nFast Transpose of 1.A OR 2.B\nEnter any other choice to exit\nEnter choice :  ");
  scanf("%d", &choice);
  if(choice ==1)
  {
    fasttranspose(a, v1, c1, r1);
  }
  else if(choice == 2)
  {
    fasttranspose(b, v2, c2, r2);
  }
  else{
    printf("\nExited Fast Transpose Function.\n");
    break;
  }
  }
  break;

  case 6 :
  return 0;
  }
  }
  return 0;
}
