#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //movement pattern is 1 step right, 1 step up, 2 steps left, 2 steps down, 3 steps right... etc
    int n = 368078; //number to compare value to
    int i2 = 1; //number just written
    int x = 25;
    int y = 25;
    int st = 1; // # steps in current direction
    int d = 1; // direction switch
    int sq[50][50] = {{0}}; //I'm sure there's a better way than just creating a big array and starting in the middle.. but I don't know it..
    int t = 0; //toggle to increase st

    sq[x][y] = 1;

    while (i2 < n) //keep going until number written is bigger than input
    {
        for (int i = 0; i < st; i++) // take steps in current direction
        {
            switch(d)
            {
                case 1:
                    x += 1;
                    break;
                case 2:
                    y += 1;
                    break;
                case 3:
                    x -= 1;
                    break;
                case 4:
                    y -= 1;
                    break;
            }
            // sum all surrounding squares
            sq[x][y] = sq[x-1][y-1] + sq[x-1][y] + sq[x-1][y+1] + sq[x][y-1] + sq[x][y+1] + sq[x+1][y-1] + sq[x+1][y] + sq[x+1][y+1];
            i2 = sq[x][y];
            printf("%i, %i: %i\n", x, y, i2);
        }
         d += 1; // switch direction
         if (d == 5)
         {
             d = 1;
         }
         if (t == 1) // check wether to increase steps
         {
             t = 0;
             st += 1;
         }
         else
         {
             t = 1;
         }
    }

}
