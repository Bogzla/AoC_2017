// the maths:
// if scanner in given layer n has a range of m, and starts at the top at 0ps,
// it will be at the top whenever ps mod ((range*2)-2) == 0
// break down input into layer and range. handily, layer = ps at the time we're interested in that layer.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 2000;

int main(void)
{
    int svrty=0;
    for (int i = 0; i < MAX; i++)
    {
        // read in input
        char s[BUFSIZ];
        if (fgets(s, 50, stdin) == NULL)
        {
          // do nowt
        }
        else
        {
            char range[3];
            range[0] = '\0';
            char lyr[3];
            lyr[0] = '\0';
            int i3;
            int i4 = 0;
            for (int i2=0, n = strlen(s) + 1; i2 < n; i2++)
            {
                if (s[i2] == ':')
                {
                    lyr[i2] = '\0';
                    i3 = i2;
                }
                else if (s[i2] == '\n')
                {
                    range[i4] = '\0';
                }
                else if (s[i2] == ' ')
                {

                }
                else if (i2 < 2)
                {
                    lyr[i2] = s[i2];
                }
                else
                {
                    range[i4] = s[i2];
                    i4++;
                }
            }
            int irange = atoi(range);
            int ilyr = atoi(lyr);
            if (ilyr % ((irange*2)-2) == 0)
            {
                svrty += (irange*ilyr);
            }

        }
    }
    printf("%i\n",svrty);
}
