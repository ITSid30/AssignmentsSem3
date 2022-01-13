/*Name : Siddhesh Ramvijay Bajad
  Rollno : SYITA104
  Doubly Linked Lists Implementation.*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next, *prev;
};

void create(struct node *head, int n)
{
  struct node *temp, *head1;
  head1 = head;
  for(int i=1;i<=n;i++)
  {
    temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->prev = NULL;
    printf("\nEnter data for node : \n");
    scanf("%d", &temp->data);
    head1->next = temp;
    temp->prev = head1;
    head1 = head1->next;
  }

}

void display(struct node *head)
{
  printf("\nThe D.L.L is :\n");
  while(head != NULL)
  {
    printf("%d\n", head->data);
    head = head->next;
  }
}

struct node* insertstart(struct node *head)
{
  struct node *temp, *p;
  p =head;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("\nEnter data : ");
  scanf("%d", &temp->data);
  temp->next =NULL;
  temp->prev =NULL;
  temp->next = head;
  head->prev = temp;
  return temp;
}

void insertmiddle(struct node *head)
{
  int num;
  printf("\nEnter data after which you want to insert : ");
  scanf("%d", &num);
  struct node *temp, *p,*q=head;
  temp = (struct node*)malloc(sizeof(struct node));
  temp->next = NULL;
  temp->prev = NULL;
  printf("\nEnter data that you want to insert : \n");
  scanf("%d", &temp->data);
  while(q->data != num)
  {
    q = q->next;
  }
  p = q->next;
  temp->next = p;
  q->next = temp;

}

void insertend(struct node *head)
{
  struct node *a = head, *temp;
  while(a->next!=NULL && a != NULL)
  {
    a = a->next;
  }
  temp = (struct node*)malloc(sizeof(struct node));
  temp->next = NULL;
  temp->prev = NULL;
  printf("\nEnter data that you want to insert : \n");
  scanf("%d", &temp->data);
  a->next = temp;
  temp->prev = a;
}

struct node* deletefirst(struct node *head)
{
  struct node *p = head;
  p = p->next;
  p->prev = NULL;
  free(head);
  return p;
}

void deletemiddle(struct node *head, int m)
{
  struct node *p= head, *q, *r;
  while(p->data != m)
  {
    q = p;
    p = p->next;
  }
  r = p->next;
  r->prev = p->prev;
  q->next = r;
  free(p);
}

struct node* deletelast(struct node *head)
{
  struct node *p=head;
  while(p->next != NULL)
  {
    p = p->next;
  }
  p->prev->next = NULL;
  p->prev = NULL;
  return p;
}

void reverse(struct node *head, struct node *last)
{
  struct node *current, *temp, *p, *q;
  p = head;
  current = head;
  while(current != NULL)
  {
    temp = current->next;
    current->next = current->prev;
    current->prev = temp;
    if(temp == NULL)
      break;
    current = temp;
  }
  /*q = head;
  head = last;
  last = q; */
  printf("\nThe Reverse of Doubly Linked list is :\n");
  while(current != NULL)
  {
    printf("%d\n", current->data);
    current = current->next;
  } 
  printf("\n"); 
}

int main(void) {
  int e, choice, n,m;
  struct node *head, *last;
  head = (struct node*)malloc(sizeof(struct node));
  printf("Enter data for Head node :\n");
  scanf("%d", &head->data);
  head->next = NULL;
  head->prev = NULL;
  while(1) {
  printf("\nD.L.L Menu \n1. Create\n2. Display\n3. Insert at Begining\n4. Insert in Middle\n5. Insert at Last\n6. Delete First\n7. Delete Middle\n8. Delete End\n9. Reverse\n10. Exit\nEnter your choice :  ");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1 : printf("Enter no. of nodes : ");
    scanf("%d", &n);
    create(head, n);
    break;
    case 2 : display(head);
    break;
    case 3 : head = insertstart(head);
    break;
    case 4 : insertmiddle(head);
    break;
    case 5 : insertend(head);
    break;
    case 6 : head = deletefirst(head);
    break;
    case 7 : printf("\nEnter data to be deleted : ");
    scanf("%d", &m);
    deletemiddle(head, m);
    break;
    case 8 : last = deletelast(head);
    break;
    case 9 : reverse(head, last);
    break;
    case 10 : printf("\nExited program...\n");
    return 0;

  }
  }

  return 0;
}
