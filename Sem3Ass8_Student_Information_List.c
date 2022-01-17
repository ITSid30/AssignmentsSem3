/*Name : Siddhesh Ramvijay Bajad
  Rollno : SYITA104 
  Assignment 8 - Student Information List*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
  int rollno;
  char name[20];
  char division;
  char address[20];
  struct node *next;
};
struct node *head=NULL;

void create()
{
  struct node *p, *temp;
  int ch=1;
  while(ch)
  {
  if(head == NULL)
  {
    head = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data of Student in format\nRollno Name Div Address .\n");
    scanf("%d %s %c %s", &head->rollno, head->name, &head->division, head->address);
    head->next = NULL;

    printf("\nDo you want to continue (1/0) : ");
    scanf("%d", &ch);
    p = head;
    
  }
  else
  {
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data of Student in format\nRollno Name Div Address .\n");
    scanf("%d %s %c %s", &temp->rollno, temp->name, &temp->division, temp->address);
    temp->next = NULL;
    p->next = temp;
    p = temp;

    printf("\nDo you want to continue (1/0) : ");
    scanf("%d", &ch);
  }
  }
}

void addstud()
{
  struct node *temp, *p;
  p = head;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter data of Student in format\nRollno Name Div Address .\n");
  scanf("%d %s %c %s", &temp->rollno, temp->name, &temp->division, temp->address);
  temp->next = NULL;
  while(p->next != NULL && p != NULL)
  {
    p = p->next;
  }
  p->next = temp;
  printf("\nStudent added .\n");

}

void deletestud()
{
  struct node *p, *q, *temp;
  p = head;
  int roll;
  FILE *fp1, *fp2, *fp3;
  printf("\nEnter rollno of student to delete data : \n");
  scanf("%d", &roll);
  if(roll == p->rollno)
  {
    head = head->next;
    free(p);

    return; 
  }
  while(p->rollno != roll)
  {
    q = p;
    p = p->next;
  }
  
  if(p->next == NULL)
  {
    q->next = NULL;
    free(p);
  }
  else 
  {
    q->next = p->next;
    free(p);
  }
  printf("\nStudent information deleted .\n");
}


void display()
{
  struct node *p;
  p = head;
  printf("\nThe Student Information entered is :\n\nRoll Name\t Div Address\n");
  while(p != NULL)
  {
    printf("%d  %s\t %c\t %s\n", p->rollno, p->name, p->division, p->address);
    p = p->next;
  }
}

void addtolist()
{
  FILE *fp;
  int choice;
  printf("\n1. Enter in New List.\n2. Enter in existing List.\nEnter your choice :  ");
  scanf("%d", &choice);
  if(choice == 1)
  {
    fp = fopen("data.txt", "w");
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
      fprintf(fp, "%d %s %c %s\n", temp->rollno, temp->name, temp->division, temp->address);
      temp = temp->next;
    }
    fclose(fp);
  }
  else if(choice == 2)
  {
    fp = fopen("data.txt", "a");
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
      fprintf(fp, "%d %s %c %s\n", temp->rollno, temp->name, temp->division, temp->address);
      temp = temp->next;
    }
    fclose(fp);
  }
  else
  {
    printf("\nEnter valid choice..\n");
  }
  printf("\nStudent Data added to File.\n");

}

void readfile()
{
  FILE *fp;
  fp = fopen("data.txt", "r");
  if(fp == NULL)
  {
    printf("\nError, no such file created..\n\n");
  }
  else
  {
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node)); 
    printf("\nThe Data in File is :\n\nRoll Name\t Div Address\n");
    while(fscanf(fp, "%d %s %c %s", &p->rollno, p->name, &p->division, p->address) != EOF)
    {
      printf("%d  %s\t %c\t %s\n", p->rollno, p->name, p->division, p->address);
    }
  }
  fclose(fp);
}

int main(void) {
  int choice;
  while(1)
  {
  printf("\nMenu\n1. Create List\n2. Add students\n3. Delete students\n4. Display Data entered\n5. Add to file.\n6. Read File.\n7. Exit\nEnter your choice :  ");
  scanf("%d", &choice);
  switch(choice)
  {
    case 1 : create();
    break;
    case 2 : addstud();
    break;
    case 3 : deletestud();
    break;
    case 4 : display();
    break;
    case 5 : addtolist();
    break;
    case 6 : readfile();
    break;
    case 7 : printf("\nExited the Program\n");
    return 0;
    default : printf("\nEnter valid choice...\n");

  }

  }
  return 0;
}
