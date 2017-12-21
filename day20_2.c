#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX = 1000;
const int ITER = 100;

int main(void)
{
    char s[60];
    long long p[MAX][11]; // particles

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
       }
    }
    // start the ticks
    for (int ij=0; ij < ITER; ij++)
    {
        // update v then p
        for (int i = 0; i < MAX; i++)
        {
            p[i][3] += p[i][6];
            p[i][4] += p[i][7];
            p[i][5] += p[i][8];
            p[i][0] += p[i][3];
            p[i][1] += p[i][4];
            p[i][2] += p[i][5];
        }
        // check for collisions. Mark destroyed particles with 1 and don't consider them any further beyond this tick
        for (int i = 0; i < MAX; i++)
        {
            if (p[i][9] != 1)
            {
                for (int ii = 0; ii < MAX; ii++)
                {
                    if (i != ii)
                    {
                        if (p[ii][9] != 1)
                        {
                            if ((p[i][0] == p[ii][0]) && (p[i][1] == p[ii][1]) && (p[i][2] == p[ii][2]))
                            {
                                p[i][10] = 1; // use index 10 to mark destroyed particles whilst we compare all other particles this tick
                            //    printf("x: %lli, y: %lli, z: %lli, p1: %i, p2: %i\n", p[i][0], p[i][1], p[i][2], i, ii);
                            }
                        }
                    }
                }
            }
        }
        // now mark all destroyed
        for (int i = 0; i < MAX; i++)
        {
            if (p[i][10] == 1)
            {
                p[i][9] = 1;
            }
        }

    }
    // and subtract destroyed particles from the total
    int rm = MAX;
    for (int i = 0; i < MAX; i++)
    {
        if (p[i][9] == 1)
        {
            rm--;
        }
    }
    printf("%i\n",rm);
}
