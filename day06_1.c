/* Things I have learnt from this excercise:
{
int *c[i];
int a[i];
c[i] = a;
}
*places* mem location of a into c so IT WILL UPDATE with a and is not a copy

-You can't dynamically name variables in c so creating new array each time and placing it in is not a goer for me right now (maybe there is a way to do it)
-this implementatin is horrifically inneficient
-I'd like to create checksum of each array and store for back-checking but didn't learn this yet. then can order & search much faster.
-memcpy & memcmp are very useful array functions even if I can't apply them here */

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    int sz = 16;  // # blocks
    int hs = 100000; // amount of history
    int c[hs][sz]; // array block history
    int i4 = 0;
    c[0][0] = 4;
    c[0][1] = 10;
    c[0][2] = 4;
    c[0][3] = 1;
    c[0][4] = 8;
    c[0][5] = 4;
    c[0][6] = 9;
    c[0][7] = 14;
    c[0][8] = 5;
    c[0][9] = 1;
    c[0][10] = 14;
    c[0][11] = 15;
    c[0][12] = 0;
    c[0][13] = 15;
    c[0][14] = 3;
    c[0][15] = 5;

    while (true)
    {
        printf("%i\n", i4);
        if (i4 > hs)
        {
            printf("%s\n", "Not found");
            return 1;
        }
        // copy latest array into next 'line'
        for (int i = 0; i < sz; i++)
        {
            c[i4+1][i] = c[i4][i];
        }
        int i2 = 0; // actual largest value
        int i3 = 0; // highest value element
        for (int i = 0; i < sz; i++) // find highest value element
        {
            if (c[i4][i] > i2)
            {
                i2 = c[i4][i];
                i3 = i;
            }
        }
        c[i4+1][i3] = 0; // redistribute the wealth. use modulo to loop back.
        for (int i = 0; i < i2; i++)
        {
            c[i4+1][(i3 + i + 1) % sz] +=1;
        }
        // compare latest 'row' to all previous in c
        for (int i = 0; i <= i4; i++)
        {
            int k = 1;
            for (int j = 0; j < sz; j++)
            {
                if (c[i4+1][j] != c[i][j])
                {
                    k=0; // if any elements don't match, move on
                    break;
                }
            }
            if (k == 1)
            {
                printf("%i\n", i4+1);
                return 0;
            }
        }

        i4++;
    }
}
