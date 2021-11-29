#include <stdio.h>

int primenos(int a, int b) {
  int count;
  for(int i=a;i<=b;i++)
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
  return 0;
}

int main(void) {
  int n1,n2, count;
  printf("\nEnter the Start : \n");
  scanf("%d", &n1);
  printf("\nEnter the End : \n");
  scanf("%d", &n2);
  printf("\nThe Prime Numbers Between %d and %d are :\n", n1,n2);
  
  primenos(n1, n2);

  printf("\n");
  return 0;
}
