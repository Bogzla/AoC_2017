#include <stdio.h>

int main(void)
{
    int v[2019];
    int n = 1; // current size of buffer
    int in = 356; // input aka steps
    int p = 0; // current position
    v[0] = 0;
    for (int i = 1; i < 2018; i++)
    {
        // new position before insertion
        p = (p + in) % n;
        // shift values after insertion point
        if (p != n-1)
        {
            for (int i2 = n+1; i2 > p; i2--)
            {
                v[i2] = v[i2-1];
            }
        }
        // insert new value
        v[p+1] = i;
        // update position & buffer size
        p++;
        n++;
    }
    printf("%i\n",v[p+1]); // report value after final poistion.
}
