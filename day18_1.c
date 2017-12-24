// usage: ./day18_1 < input.txt
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void substring(char s[], char sub[], int p, int l);
long long regval(char c[]);

const int MAX = 41;
long long reg[123]; // registers. Use ascii codes.
int main(void)
{
    char s[20];
    char inst[MAX][3][20]; // instructions

    for (int i = 0; i < 41; i++) // read instructions into inst[]
    {
       if (fgets(s, 20, stdin) != NULL)
       {
            char ss[20];
            substring(s, ss, 0, 3);
            strcpy(inst[i][0],ss);
            substring(s, ss, 4, 1);
            strcpy(inst[i][1],ss);
            if (s[strlen(s)-1] == '\n')
            {
                substring(s, ss, 6, strlen(s)-7);
            }
            else
            {
                substring(s, ss, 6, strlen(s)-6);
            }
            strcpy(inst[i][2],ss);
         //   printf("%s %s %s\n",inst[i][0], inst[i][1], inst[i][2]);
       }
       else
       {
           printf("\n");
           break;
       }
    }
    int snd;
    int i = 0;
    while (i < MAX) // carry out operations
    {
        printf("%i\n",i);
        if (strcmp(inst[i][0],"snd") == 0)
        {
            snd = regval(inst[i][1]);
            i++;
        }
        else if (strcmp(inst[i][0],"set") == 0)
        {
            reg[(int)inst[i][1][0]] = regval(inst[i][2]);
            i++;
        }
        else if (strcmp(inst[i][0],"add") == 0)
        {
            reg[(int)inst[i][1][0]] += regval(inst[i][2]);
            i++;
        }
        else if (strcmp(inst[i][0],"mul") == 0)
        {
            reg[(int)inst[i][1][0]] = regval(inst[i][2]) * regval(inst[i][1]);
            i++;
        }
        else if (strcmp(inst[i][0],"mod") == 0)
        {
            reg[(int)inst[i][1][0]] = regval(inst[i][1]) % regval(inst[i][2]);
            i++;
        }
        else if (strcmp(inst[i][0],"rcv") == 0)
        {
            if (regval(inst[i][1]) != 0)
            {
                printf("%i\n",snd);
                return 0;
            }
            else
            {
                i++;
            }
        }
        else if (strcmp(inst[i][0],"jgz") == 0)
        {
            if (regval(inst[i][1]) > 0)
            {
                i = i + regval(inst[i][2]);
            }
            else
            {
                i++;
            }
        }
        // debugging
/*        for (int i2 = 97; i2 < 123; i2++)
        {
            printf("%c: %lli, ",(char)i2, reg[i2]);
        }
        printf("\n"); */
    }
}

// C substring function definition
// start counting at 0
void substring(char s[], char sub[], int p, int l)
{
    int sl = strlen(s);
    if (p > sl - 1)
    {
        return;
    }
    else if (l > sl - p)
    {
        l = sl - p;
    }
    int c = 0;

    while (c < l)
    {
      sub[c] = s[p+c];
      c++;
    }
    sub[c] = '\0';
}

// register value function
// if argument is a number, return it as integer
// if it is a letter, return value of that register
long long regval(char c[])
{
    if ((int)c[0] < 96)
    {
        return atoi(c);
    }
    else
    {
        return reg[(int)c[0]];
    }
}
