// an introduction to bit masks today
#include <stdio.h>

int main(void)
{
    long long a = 116;
    long long b = 299;
    int afac = 16807;
    int bfac = 48271;
    int cnt = 0;
    long div = 2147483647;
    long msk = (1 << 16) - 1; // create mask for lowest 16 bits (we'll use this for & operator, 16 lowest set to '1'; higher set to '0')
    // for part 2, generate a 'til it meets divisible by 4 then b til divisible by 8 then compare them.'
    for (long i = 0; i < 5000000; i++)
    {
        do
        {
            a = (a*afac) % div;
        } while (a % 4 != 0);
        do
        {
            b = (b*bfac) % div;
        }while (b % 8 != 0);
        if ((a & msk) == (b & msk)) // use mask to compare only 16 lowest bits
        {
            cnt += 1;
        }
    }
    printf("count = %i\n", cnt);
}
