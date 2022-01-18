/*Name : Siddhesh Ramvijay Bajad
  Rollno : SYITA104 
  Assignment 8 - Student Information List*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
  int rollno;
  char name[20];
  char division;
  char address[20];
}stud;

void addstud()
{
  printf("\nEnter data of Student in format\nRollno Name Div Address .\n");
  scanf("%d %s %c %s", &stud.rollno, stud.name, &stud.division,stud.address);
  FILE *fp;
  fp = fopen("Record", "a");
  fprintf(fp, "%d %s %c %s\n", stud.rollno, stud.name, stud.division, stud.address);
  printf("\nStudent added .\n");
  fclose(fp);

}

void display()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nRollNo\tName\tDiv\t\tAddress\n\n");
 while (fread(&stud, sizeof(stud), 1, fp1) )
 printf("%d\t%s\t%c\t%s\n", stud.rollno, stud.name, stud.division,stud.address);
 fclose(fp1);
} 


void deletestud()
{
  int roll;
  FILE *fp1, *fp2, *fp3;
  printf("\nEnter rollno of student to delete data : \n");
  scanf("%d", &roll);
  FILE *fpo, *fpt;
  int s;
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&stud, sizeof(stud), 1, fpo))
  {
   s = stud.rollno;
   if (s != roll)
    fwrite(&stud, sizeof(stud), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&stud, sizeof(stud), 1, fpt))
   fwrite(&stud, sizeof(stud), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
  printf("\nStudent information deleted .\n");
}


int main(void) {
  int choice;
  while(1)
  {
  printf("\nMenu\n1. Add students\n2. Delete students\n3. Exit\nEnter your choice :  ");
  scanf("%d", &choice);
  switch(choice)
  {
    case 1 : addstud();
    break;
    case 2 : deletestud();
    break;
    case 3 : printf("\nExited the Program\n");
    return 0;
    default : printf("\nEnter valid choice...\n");

  }

  }
  return 0;
}
