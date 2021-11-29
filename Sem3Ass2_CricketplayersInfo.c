/*Name : Siddhesh Ramvijay Bajad
  Rollno. : SYITA104
  Assignment 2 - Cricket Players Information */

#include <stdio.h>
#include <string.h>

struct cricket
{
  char name[20];
  char type[15];
  float avgscore;
  int wickets;
  int runs;
  char country[15];
}player[10];

void avgscoresort(struct cricket p[], int n)
{
  struct cricket p1;
  for(int i=0; i<n; i++)
  {
    for(int j=i+1; j<n; j++)
    {
      if(p[i].avgscore < p[j].avgscore)
      {
        p1 = p[i];
        p[i] = p[j];
        p[j] = p1;
      }
    }
  }
  printf("\nThe SORTED Details of players are : \n");
      printf("\nName\t\tType\t\tAvgScore \tWickets \tRuns\tCountry\n");
      for(int i=0; i<n; i++)
      {
        printf("%s \t\t%s\t\t%.2f\t\t\t%d\t\t%d\t\t%s\n", p[i].name, p[i].type, p[i].avgscore, p[i].wickets, p[i].runs, p[i].country);
      }
      printf("\n");

}

void display(int n)
{
  char name[20];
  printf("\nEnter the Name of player to display : ");
  scanf("%s", name);
  int i;
  printf("\nThe Info of the Player is : ");
  for(i=0; i<n; i++)
  {
    if(strcmp(player[i].name , name) == 0)
    {
      printf("\nName          -> %s .\n", player[i].name);
      printf("Type          -> %s\n", player[i].type);
      printf("Average Score -> %f\n", player[i].avgscore);
      printf("Wickets       -> %d\n", player[i].wickets);
      printf("Runs          -> %d\n", player[i].runs);
      printf("Country       -> %s\n", player[i].country);
      printf("======================================\n");
      break;
    }
  }
  if(i==n)
  {
    printf("\nNo, such player found. !!\n\n");
  }
}

void batcountry(int n)
{
  char country[15];
  int batsman=0;
  printf("\nEnter Country to find Batsmans : ");
  scanf("%s", country);
  for(int i=0; i<n; i++)
  {
    if(strcmp(country, player[i].country)==0 && strcmp(player[i].type, "Batsman") ==0)
    {
      batsman++;
      //printf("\n' %s ' is Batsman of %s country.\n", player[i].name, player[i].country);
    }
  }
  printf("\nThere are  %d  Batsmans of %s country.", batsman, country);
  printf("\n----------------------------------------------------");
  printf("\n\n");
}

void bowlcountry(int n)
{
  char country[15];
  int bowler=0;
  printf("\nEnter Country to find Bowler : ");
  scanf("%s", country);
  for(int i=0; i<n; i++)
  {
    if(strcmp(country, player[i].country)==0 && strcmp(player[i].type, "Bowler") ==0)
    {
      bowler++;
      //printf("\n' %s ' is Bowler of %s country.\n", player[i].name, player[i].country);
    }
  }
  printf("\nThere are  %d  Bowlers of %s country.", bowler, country);
  printf("\n----------------------------------------------------");
  printf("\n\n");
}

void highestruns(int n)
{
  int maxrun = player[0].runs;
  int i, k=0;
  for(i=1; i<=n; i++)
  {
    if(maxrun < player[i].runs)
    {
      maxrun = player[i].runs;
      k = i;
    }
    else continue;
  }
  printf("\nThe player ' %s ' has Scored Maximum Runs .\n", player[k].name);
  printf("====================================================\n\n");
}

void highestwickets(int n)
{
  int maxwickets = player[0].wickets;
  int i, k;
  for(i=1; i<=n; i++)
  {
    if(maxwickets < player[i].wickets)
    {
      maxwickets = player[i].wickets;
      k = i;
    }
  }
  printf("\nMaximum Wickets have taken by ' %s ' .\n", player[k].name);
  printf("====================================================\n\n");
}

void highestavgscore(int n)
{
  float max = player[0].avgscore;
  int k=0;
  for(int i=0; i<n; i++)
  {
    if(max < player[i].avgscore)
    {
      k = i;
    }
  }
  printf("\n\nThe player ' %s ' has Highest Average Score which is -> %.2f .\n", player[k].name, player[k].avgscore);
  printf("==========================================================\n");
} 



int main(void) {
  int n;
  printf("\nEnter number of players : \n");
  scanf("%d", &n);
  for(int i=0; i<n; i++)
  {
    printf("\nEnter Name of player %d :  ", i+1);
    scanf("%s", player[i].name);
    printf("Enter Type of Player %d :  ", i+1);
    scanf("%s", player[i].type);
    printf("Enter average Score of Player %d :  ", i+1);
    scanf("%f", &player[i].avgscore);
    printf("Enter Wickets Taken by player %d :  ", i+1);
    scanf("%d", &player[i].wickets);
    printf("Enter Runs Scored by player %d :  ", i+1);
    scanf("%d", &player[i].runs);
    printf("Enter Country of player %d :  ", i+1);
    scanf("%s", player[i].country);
    printf("\n");
  } 
  printf("------------------------------------------------\n");

  int choice;
  while(1)
  {
    printf("\n1. Enter 1 to Sort players .\n2. Enter 2 to Search for a player .\n3. Enter 3 to Display players .\n4. Enter 4 to Find Batsmans of particular Country .\n5. Enter 5 to Find Bowlers of particular country .\n6. Enter 6 to Find Maximum Runs Player .\n7. Enter 7 to Find Maximum Wickets Player .\n8. Enter 8 to Display Player with highest average Score .\n9. Enter 9 to EXIT .\n\nEnter your choice : ");
    scanf("%d", &choice);
    printf("------------------------------------------------------\n");
    switch(choice)
    {
      case 1 : avgscoresort(player, n);
      break;

      case 2 : display( n);
      break;

      case 3 : printf("\nThe Details of players are : \n");
      printf("\nName\t\tType\t\tAvgScore \tWickets \tRuns\tCountry\n");
      for(int i=0; i<n; i++)
      {
        printf("%s \t\t%s\t\t%.2f\t\t\t%d\t\t%d\t\t%s\n", player[i].name, player[i].type, player[i].avgscore, player[i].wickets, player[i].runs, player[i].country);
      }
      printf("\n");
      break;

      case 4 : batcountry(n);
      break;

      case 5 : bowlcountry(n);
      break;

      case 6 : highestruns(n);
      break;

      case 7 : highestwickets(n);
      break;

      case 8 : //struct cricket q = findMaximum(player, 0, n-1);
      highestavgscore(n);
      break;

      case 9 : printf("\nYou Exited The Program !!...\n");
               return 0;

      default : printf("\nEnter a valid choice !!...\n");
      printf("===========================================\n");
                break;
    }
  }
  
  return 0;
}
