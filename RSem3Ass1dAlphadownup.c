#include <stdio.h>
#include <string.h>

int main(void) {
  char s[50];
  printf("Enter The String :\n");
  gets(s);
  int i=0;
  while(s[i] != '\0')
  {
    if(s[i] == 32)
    {
      s[i] = 32;
    }
    else if(s[i] >= 97 && s[i] <= 122)
    {
      s[i] -= 32;
    }
    else if(s[i] >= 65 && s[i] <= 90)
    {
      s[i] += 32;
    }
    i++;
  }
  printf("\nThe Case Changed String is :\n");
  i=0;
  while(s[i] != '\0')
  {
    printf("%c", s[i]);
    i++;
  }
  printf("\n");
  return 0;
}
