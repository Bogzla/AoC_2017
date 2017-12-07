// Usage: day05_2 < INPUT.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX = 2000;

int main(void)
{
  int inst[MAX];
  int i3 = 0;

  for (int i = 0; i < MAX; i++)
  {
    // read in input
    char s[BUFSIZ];
    if (scanf("%s", s) == EOF)
    {
      break;
    }
    else
    {
      inst[i] = atoi(s);
      i3 = i; //get highest element #
     // printf("You entered: %i\n",inst[i]);
    }
  }
  int i = 0; //current position
  int i2 = 0; //# steps
  while (i <= i3)
  {
    int i4 = inst[i]; //get instruction
    if (i4 > 2)
    {
      inst[i]--; //increment instruction down if offset > 2
    }
    else
    {
      inst[i]++; //increment instruction up if offset < 3
    }
    i += i4; // carry out original instruction
    i2++; //increment count
  }
  printf("%i\n", i2);
}
