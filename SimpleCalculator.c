#include <stdio.h>

int main(void) {
  int choice;
  long a,b;
  printf("\nSimple Calculator\n");
  printf("\nAvailable Operations are : \nAddition (1)\nSubstraction (2)\nMultiplication (3)\nDivision (4)\n\nEnter the choice to perform operations : ");
  scanf("%d", &choice);

  switch(choice) {
    case 1 :
            printf("\nEnter 2 numbers to perform Addition :\n");
            scanf("%ld %ld", &a, &b);
            printf("\nThe Summation of 2 numbers is %ld .\n", a+b);
            break;
    case 2 :
            printf("\nEnter 2 numbers to perform Substraction :\n");
            scanf("%ld %ld", &a, &b);
            printf("\nThe Substraction of 2 numbers is %ld .\n", a-b);
            break;
    case 3 :
            printf("\nEnter 2 numbers to perform Multiplication :\n");
            scanf("%ld %ld", &a, &b);
            printf("\nThe Multiplication of 2 numbers is %ld .\n", a*b);
            break;
    case 4 :
            printf("\nEnter 2 numbers to perform Division :\n");
            scanf("%ld %ld", &a, &b);
            printf("\nThe Division of 2 numbers is %.2f\n", (float)a/b);
            break;
    default: printf("\nEnter valid operation.... TRY AGAIN..\n");
      
  }

  return 0;
}
