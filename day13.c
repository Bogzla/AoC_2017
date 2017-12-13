// the maths:
// if scanner in given layer n has a range of m, and starts at the top at 0ps,
// it will be at the top whenever ps mod ((range*2)-2) == 0
// break down input into layer and range. handily, layer = ps at the time we're interested in that layer.
// for part 2, added complexity of time offset. Add delay to the layer number and check:
// (layer + delay) mod ((range*2)-2) == 0
// There is a trick that simply looking for 0 severity *is not* the same as avoiding detection as
// getting caught at layer 0 contributes 0 to severity score
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 43;

int main(void)
{
    int vals[MAX][2];
    for (int i = 0; i < MAX; i++)
    {
        // read in input
        char s[8];
        if (fgets(s, 8, stdin) == NULL)
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
            vals[i][1] = atoi(range);
            vals[i][0] = atoi(lyr);
        }
    }
    for (int dly=0; dly < 10000000; dly++)
    {
        int svrty = 0;
        for (int i=0; i < MAX; i++)
        {
            if ((vals[i][0] + dly) % ((vals[i][1] * 2)-2) == 0)
            {
                if (vals[i][0] == 0)
                {
                    svrty += 1; // to avoid trap of getting caught in layer 0 contributing 0 to severity
                }
                svrty += (vals[i][0]*vals[i][1]);
            }
        }
        if (svrty == 0)
        {
            printf("%i\n", dly);
        }
    }
}
