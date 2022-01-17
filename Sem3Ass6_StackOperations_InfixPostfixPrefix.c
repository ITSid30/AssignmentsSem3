/*Name : Siddhesh Ramvijay Bajad
  Rollno : SYITA104
  Assignment 6 : Infix to prefix , Infix to postfix 
  Evaluation of Postfix and Prefix Expression*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <cstdio>

struct stack 
{
  char data;
  struct stack *next;
};
struct stack *top= NULL;

struct Node
{
    int data;
    struct Node *next;
} *stop = NULL;

int precedence(char);
void push(char);
char pop();


int topostfix()
{
  char infix[20], postfix[20];
  int i=0,j=0;
  printf("\nEnter INFIX Expression :\n");
  //gets(infix);
  scanf("%s", infix);
  while(infix[i] != '\0')
  {
    if(isalnum(infix[i]))
    {
      postfix[j++] = infix[i];
    }
    else 
    {
      if(top == NULL)
      {
        push(infix[i]);
      }
      else 
      {
        if( (precedence(top->data) >= precedence(infix[i]) ) )
        {
          postfix[j++] = pop();
          push(infix[i]);
        }
        else 
        {
          push(infix[i]);
        }
      }
    }
    ++i;
  }

  while(top != NULL)
  {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';
  puts(postfix);
  return 0;
}

int toprefix()
{
  char infix[20], prefix[20];
  int i=0,j=0;
  printf("\nEnter INFIX Expression :\n");
  //gets(infix);
  scanf("%s", infix);
  int len = strlen(infix);
  int end = len - 1, begin;
  char rinfix[20];
  strcpy(rinfix , infix);
   for (begin = 0; begin < len; begin++) {
      infix[begin] = rinfix[end];
      end--;
   }
   infix[begin] = '\0';

  while(infix[i] != '\0')
  {
    if(isalnum(infix[i]))
    {
      prefix[j++] = infix[i];
    }
    else 
    {
      if(top == NULL)
      {
        push(infix[i]);
      }
      else 
      {
        if( (precedence(top->data) >= precedence(infix[i]) ) )
        {
          prefix[j++] = pop();
          push(infix[i]);
        }
        else 
        {
          push(infix[i]);
        }
      }
    }
    ++i;
  }

  while(top != NULL)
  {
    prefix[j++] = pop();
  }
  prefix[j] = '\0';
  len = strlen(prefix);
  end = len -1;
  strcpy(rinfix , prefix);
   for (begin = 0; begin < len; begin++) {
      prefix[begin] = rinfix[end];
      end--;
   }
   prefix[begin] = '\0';
  puts(prefix);
  return 0;
}

int precedence(char x)
{
  switch(x)
  {
    case '^' : return 4;
    case '*' :
    case '/' : return 3;
    case '+' : 
    case '-' : return 2;

    default : return 0;
  }
}

void push(char x)
{
  struct stack *temp;
  temp = (struct stack*)malloc(sizeof(struct stack));
  if(top == NULL)
  {
    temp->data = x;
    temp->next = NULL;
    top = temp;
  }
  else 
  {
    temp->data = x;
    temp->next = top;
    top = temp;
  }
}

char pop()
{
  struct stack *temp;
  char item;
  if(top == NULL)
  {
    printf("\nStack is EMPTY .\n");
  }
  else if(top->next == NULL)
  {
    temp = top;
    item = top->data;
    top = NULL;
    free(temp);
  }
  else
  {
    temp = top;
    item = top->data;
    top = top->next;
    free(temp);
  }
  return item;
}

void spush(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = stop;
        stop = t;
    }
}

int spop()
{
    struct Node *t;
    int x = -1;

    if (stop == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = stop;
        stop = stop->next;
        x = t->data;
        free(t);
    }
    return x;
}


void Display()
{
    struct Node *p;
    p = stop;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


// To Check Whether the Given Character is Operand or Not.
int isOperand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}


int solvepostfix(char *postfix){
    int i=0;
    int x1, x2, r;

    for (i = 0;  postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            spush(postfix[i] - '0');
        else
        {
            x2 = spop();
            x1 = spop();

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            
            case '-':
                r = x1 - x2;
                break;
            
            case '/':
                r = x1 / x2;
                break;
            
            case '*':
                r = x1 * x2;
                break;
            }
            
            spush(r);
        }
    }
    
    return stop->data;
}


int main(void) {
  int choice;
  char *post, pre[20];
  int ans;
  while(1)
  {
  printf("\n1. Infix to Prefix\n2. Infix to Postfix\n3. Evaluate Postfix\n4. Evaluate Prefix\n5. Exit\nEnter choice :  ");
  scanf("%d", &choice);

  switch(choice)
  {
    case 1 : topostfix();
    break;
    case 2 : toprefix();
    break;
    case 3 : printf("\nEnter the Postfix expression :\n");
    scanf("%s", post);
    ans = solvepostfix(post);
    printf("\nThe Result of Postfix expression is :\n%d\n\n", ans);
    break;

    case 4: {
    printf("\nEnter Prefix Expression :\n");
    scanf("%s", pre);
    int len = strlen(pre);
    int end = len - 1, begin;
    char temp[20];
    strcpy(temp , pre);
    for (begin = 0; begin < len; begin++) {
      pre[begin] = temp[end];
      end--;
    }
    pre[begin] = '\0';
    printf("\n%s\n", pre);
    ans = solvepostfix(pre);
    printf("\nThe Result of Prefix Expression is :\n%d\n\n", ans);
    break;
    }
    case 5 : printf("\nExited the program.\n");
    return 0;

  }
  }

  return 0;
}
