#include <stdio.h>
#include <string.h>

struct product {
  char code[5];
  char name[20];
  int cost;
};

int main(void) {
  int choice, sum=0;
  char s[5];
  struct product p[5] = {"P100", "Chocolates", 10, 
                         "P200", "Biscuits", 30,
                         "P300", "Wafers ", 50,
                         "P400", "NoteBooks", 80,
                         "P500", "Refills", 15};
  printf("\nWelcome to PRODUCT STORE !!\n");
  printf("\nCode\t\tName\t\tCost\n");
  for(int i=0;i<5;i++)
  {
    printf("%s\t %s\t\t %d\n", p[i].code, p[i].name, p[i].cost);
  }
  printf("\nAvailable Options :\nBuy  (1)\nExit (2)\n\nWhat to buy ? : \n");
    scanf("%d", &choice);
  while(choice!=2)
  {
    
    printf("Enter the Code of Product to buy :\n");
    scanf("%s", s);
    for(int i=0;i<5;i++)
    {
      if(strcmp(s, p[i].code) == 0)
      {
        sum += p[i].cost;
      }
    }
    printf("\nWant anything Else ? Yes (1) No (2) : \n");
    scanf("%d", &choice);
  }
  printf("\nYour Total Bill is Rs. %d /-.\nThankyou...Visit Again !!.\n", sum);
  return 0;
}
