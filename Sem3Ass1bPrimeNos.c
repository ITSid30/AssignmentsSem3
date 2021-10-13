#include <stdio.h>

int main(void) {
  int n1,n2, count;
  printf("\nEnter the Start : \n");
  scanf("%d", &n1);
  printf("\nEnter the End : \n");
  scanf("%d", &n2);
  printf("\nThe Prime Numbers Between %d and %d are :\n", n1,n2);
  for(int i=n1;i<=n2;i++)
  {
    count =0;
    for(int j=1;j<=i;j++)
    {
      if( i%j == 0)
      {
        count++;
      }
    }
    if(count == 2)
    {
      printf("%d\n", i);
    }
  }
  printf("\n");
  return 0;
}
