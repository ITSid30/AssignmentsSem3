/*Name : Siddhesh Ramvijay Bajad
  Rollno : SYITA104 
  Assignment 7 - Circular Queue using Arrays.*/

#include <stdio.h>
#include <stdlib.h>

const int size=8 ;
int front=0, rear=-1;
int queue[size];

int isfull()
{
  if(rear == size-1)
    return 1;
  else return 0;
}

int isempty()
{
  if(front > rear)
    return 1;
  else return 0;
}

void enqueue()
{
  
  if(isfull())
  {
    printf("\nCircular Queue is Full\n");
  }
  else
  {
    rear++;
    printf("\nEnter data to enter : ");
    scanf("%d", &queue[rear]);

  }
}

int dequeue()
{
  if(isempty())
  {
    printf("\nQueue is Empty.\n");
    return -1;
  }
  else
  {
    int item;
    item = queue[front];
    front = front+1;
    return item;
  }
  return 0;
}

void display()
{
  int i = front;
  if(isempty())
  {
    printf("\nCircular Queue is Empty.\n");
  }
  else 
  {
    printf("\nThe Elements of the Circular Queue are : \n");
    while(i <= rear)
    {
      printf("%d\n", queue[i]);
      i++;
    }
    printf("--------------------------\n");
  }
}

int main(void) {

  int choice, data;
  while(1)
  {
    printf("\nCircular Queue Menu \n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice :   ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1 : enqueue();
      break;
      case 2 : data = dequeue();
      if(data == -1)
      {
        printf("\nNo element dequeued since queue is Empty.\n");
      }
      else
        printf("\nThe Dequeued Element is : %d.\n", data);
      break;
      case 3 : display();
      break;
      case 4 : printf("\nExited the program .\n");
      break;
    }
  }

  return 0;
}
