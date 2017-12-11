#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Considering hexagonal grids. These can be regarded as a cartesian grid with a 'hidden' node on each horizontal line.
// So moves have the following properties:
// N = y+2
// S = y-2
// NE = x+1, y+1
// NW = x-1, y+1
// SE = x+1, y-1
// SW = x-1, y-1
int main(void)
{
    char *s;
    char stp[3];
    int x = 0;
    int y = 0;
    if (scanf("%ms", &s) != EOF) //read in input. declaring char *s and using %m modifier allows dynamic memory allocation
    {
        int i2 = 0;
        for (int i=0, n = strlen(s) + 1; i < n; i++) // process string
        {
            if ((s[i] == ',') || (s[i] == '\0')) // check for end of step and modify x / y accordingly
            {
                stp[i2] = '\0';
                i2 = 0;
                if (strcmp("n",stp) == 0)
                {
                    y += 2;
                }
                else if (strcmp("s",stp) == 0)
                {
                    y -= 2;
                }
                else if (strcmp("ne",stp) == 0)
                {
                    y += 1;
                    x += 1;
                }
                else if (strcmp("nw",stp) == 0)
                {
                    y += 1;
                    x -= 1;
                }
                else if (strcmp("se",stp) == 0)
                {
                    y -= 1;
                    x += 1;
                }
                else if (strcmp("sw",stp) == 0)
                {
                    y -= 1;
                    x -= 1;
                }

            }
            else // if step isn't ended we're writing first or second character
            {
                stp[i2] = s[i];
                i2++;
            }
        }
    }
    printf("x = %i\n",x);
    printf("y = %i\n",y);
    // calculate distance
    int stps;
    if (abs(x) >= abs(y))
    {
        stps = x;
    }
    else
    {
        stps = x + ((y-x)/2);
    }
    printf("Num steps: %i\n",stps);
    free(s)
}
