// for part 2 we only care about monitoring the value after 0
// since 0 is always in position 0, we can track insertion position, and update
// position 1 value when it coi-incides
#include <stdio.h>

int main(void)
{
    long n = 1; // current size of buffer
    int in = 356; // input aka steps
    long p = 0; // current position
    long soln = 0;
    for (long i = 1; i < 50000001; i++)
    {
        // new position before insertion
        p = (p + in) % n;
        // is it 0? if so update solution (value in position 1)
        if (p == 0)
        {
            soln = i;
        }
        // update position & buffer size
        p++;
        n++;
    }
    printf("%li\n",soln); // report position 1 value after final iteration.
}
