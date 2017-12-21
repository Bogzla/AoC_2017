#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX = 1000;

int main(void)
{
    char s[60];
    long long p[MAX][10]; // particles
    long long d = 2000000000; // lowest distance tracker
    int pn;
    int j;

    for (int i = 0; i < MAX; i++) // read initial state into p
    {
       if (fgets(s, 60, stdin) != NULL)
       {
           int i3 = 0; // array element
           int i4 = 0; // ss position
           char ss[10];
           for (int i2 = 0, n = strlen(s); i2 < n; i2++)
           {
               if ((s[i2] == ',' ) || (s[i2] == '>')) // end of integer, update array
               {
                   if (s[i2-1] != '>')
                   {
                   ss[i4] = '\0';
                   p[i][i3] = atoi(ss);
               //    printf("%i - ",p[i][i3]);
                   i4 = 0;
                   i3++;
                   }
               }
               // get the integers
               else if (s[i2] == '-' ) // some values are -ve
               {
                   ss[i4] = '-';
                   i4++;
               }
               else if (((int)s[i2] < 58) && ((int)s[i2] > 47)) // if char is integer, part of larger one.
               {
                   ss[i4] = s[i2];
                   i4++;
               }
           }
           // find nearest to origin in initial state
           p[i][9] = llabs(p[i][0]) + llabs(p[i][1]) + llabs(p[i][2]);
           if (p[i][9] < d)
           {
               d = p[i][9];
               pn = i;
           }
         //  printf("\n");
       }
    }
    // start the ticks
    for (int ij=0; ij < 1000; ij++)
    {
        d = 2000000000;
        for (int i = 0; i < MAX; i++)
        {
            // update v then p
            p[i][3] += p[i][6];
            p[i][4] += p[i][7];
            p[i][5] += p[i][8];
            p[i][0] += p[i][3];
            p[i][1] += p[i][4];
            p[i][2] += p[i][5];
            // find Manhattan distance & compare, keep track of nearest to origin
            p[i][9] = llabs(p[i][0]) + llabs(p[i][1]) + llabs(p[i][2]);
            if (p[i][9] < d)
            {
               d = p[i][9];
               pn = i;
            }
        }
        j = pn; // update nearest
    }
    printf("%i\n",j);
}
