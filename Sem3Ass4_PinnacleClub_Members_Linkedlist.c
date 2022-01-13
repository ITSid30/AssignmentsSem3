/*Name : Siddhesh Ramvijay Bajad
  Rollno : SYITA104
  Pinnacle Club Members List using Linkedlists.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int prn;
  int rollno;
  char name[20];
  struct node *next;
};

struct node* create()
{
  int r,p;
  char name[20];
  struct node *head;
  head = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter Name , Roll no, PRN No. of President : \n");
  scanf("%s %d %d", name, &r, &p);
  head->prn = p;
  head->rollno = r;
  strcpy(head->name, name);
  head->next = NULL;
  printf("\n\n");
  return head;
}

struct node* addmembers(int m, struct node *head)
{
  struct node *temp, *p;
  p = head;
  int q,r;
  char name[20];
  for(int i=0;i<m;i++)
  {
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter Name , Rollno, PRN No. of Group Members : \n");
    scanf("%s %d %d", name, &r, &q);
    temp->prn = q;
    temp->rollno = r;
    strcpy(temp->name, name);
    temp->next = NULL;
    p->next = temp;
    p = temp;
  }
  printf("\n");
  return p;
}

void display(struct node *head)
{
  struct node *copy;
  copy = head;
  printf("\n\nPINNACLE CLUB Members are :\nPRN  Rollno Name\n");
  while(copy!=0)
  {
    printf("%d\t%d\t%s\n", copy->prn, copy->rollno, copy->name);
    copy = copy->next;
  }
  printf("-------------------------------------------------");
  printf("\n\n");
}

struct node* addsecratory(struct node *lastM)
{
  struct node *last;
  int p,r;
  char name[20];
  last = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter Name , Roll no, PRN No. of Secratory : \n");
  scanf("%s %d %d", name, &r, &p);
  last->prn = p;
  last->rollno = r;
  strcpy(last->name, name);
  last->next = NULL;

  lastM->next = last;
  printf("\n");
  return last;
}

struct node* deleteP(struct node *head)
{
  struct node *temp;
  temp = head;
  temp = temp->next;
  free(head);
  return temp;
}

struct node* deleteS(struct node *head)
{
  struct node *p, *q;
  p = head;
  q = head;
  while(head!= NULL && head->next != NULL)
  {
    p = head;
    head = head->next;
  }
  p->next = NULL;
  free(head);
  //display(q);
  return q;
}

struct node* deletemembers(struct node *head)
{
  int roll;
  struct node *temp, *p=NULL;
  printf("\nEnter rollno of members that you want to delete :\n");
  scanf("%d", &roll);
  printf("\n\n");
  temp = head;
  p = head;
  if(temp->rollno == roll)
  {
    head = head->next;
    free(temp);
    return head;
  }
  while(temp->rollno != roll)
  {
    p = temp;
    temp = temp->next;
  }
  if(temp->next == NULL)
  {
    p->next = NULL;
  }
  else {
  p->next = temp->next;
  }
  free(temp);
  return head;
}

struct node* reversedisplay(struct node *head)
{
  struct node *prev, *current, *nextnode;
  prev = NULL;
  current = head;
  nextnode = head;
  while(nextnode != NULL)
  {
    nextnode = nextnode->next;
    current->next = prev;
    prev = current;
    current = nextnode;
  }
  head = prev;
  return head;
}


int main(void) {
  int choice;

  struct node *head, *lastM, *last;
  int m;

  while(1)
  {
  printf("Menu for Club members :\n1. Create\n2. Add Members\n3. Add Secratory\n4. Display\n5. Delete President\n6. Delete Secratory\n7. Delete Members\n8. Reverse\n9. Exit\nEnter your choice :  ");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1 : head = create();
            break;
    case 2 :
    printf("Enter number of Members in club :  ");
    scanf("%d", &m);
    lastM = addmembers(m , head);
    break;

    case 3 : last = addsecratory(lastM);
    break;
    case 4 : display(head);
    break;
    case 5 : head = deleteP(head);
    break;
    case 6 : head = deleteS(head);
    break;
    case 7 : head = deletemembers(head);
    break;
    case 8 : head = reversedisplay(head);
    break;
    case 9 : printf("\nExited program\n");
    return 0;
            break;
  }

  }
  return 0;
}
