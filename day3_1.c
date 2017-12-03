#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //movement pattern is 1 step right, 1 step up, 2 steps left, 2 steps down, 3 steps right... etc
    int i2 = 1; //direction switch: 1 = right, 2 = up, 3 = left, 4 = down
    int i3 = 1; //number of steps in direction
    int ix = 0, iy = 0; //coordinate trackers
    int i4 = 0; //toggle between 0-1 to increse i3 every 2 goes
    int n = 368078; //number of square to get data from
    int i = 1; //number of square we are on
    while (i < n)
    {
        //check we won't overshoot
        if (i + i3 > n)
        {
            i3 = n-i;
        }
        switch(i2) //alter x or y coordinate depending on direction / distance to travel
        {
            case 1:
                ix += i3;
                break;
            case 2:
                iy += i3;
                break;
            case 3:
                ix -= i3;
                break;
            case 4:
                iy -= i3;
                break;
        }
        i += i3; //update square number
        i2 += 1; //change direction
        if (i2 == 5)
        {
            i2 = 1;
        }
        if (i4 == 1) //check if we need to increase next distance to travel
        {
            i4 = 0;
            i3 += 1;
        }
        else
        {
            i4 = 1;
        }


    }
    printf("%i\n", abs(ix)+abs(iy));

}
