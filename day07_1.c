#include <stdio.h>
#include <string.h>
#define MAX 1281

void substring(char s[], char sub[], int p, int l);

int main(void)
{
    char s[100];
    char ss[50];
    char in[MAX][10][20]; // input

    for (int i = 0; i < MAX; i++) // read input into in[]
    {
       if (fgets(s, 100, stdin) != NULL)
       {
           int i3 = 0; // store position of last space found
           int i4 = 2; // count qty programmes supported
           for (int i2 = 0, n = strlen(s); i2 < n; i2++)
           {
               if (s[i2] == ' ')
               {
                   i3 = i2; // preceeding space
                   if (s[i2+1] == '(') // listed programme
                   {
                        substring(s, ss, 0, i2);
                        strcpy(in[i][0], ss);
                   }
               }
               else if (s[i2] == ',') // supported programme
               {
                   substring(s, ss, i3+1, i2-i3-1);
                   strcpy(in[i][i4], ss);
                   i4++;
               }
               else if ((i2 == n-1) && (s[i2-1] != ')') && (s[i2] != ')')) // end of line is last supported programme, if there are any
               {
                   substring(s, ss, i3+1, i2-i3-1);
                   strcpy(in[i][i4], ss);
                   i4++;
               }
               else if (s[i2] == ')') // programme weight
               {
                   substring(s, ss, i3+2, i2-i3-2);
                   strcpy(in[i][1], ss);
               }
           }
           if (i4 < 10) // set remainder of indeces to 0 length strings
           {
               while (i4 < 10)
               {
                    in[i][i4][0] = '\0';
                    i4++;
               }
           }
       }
    }
    /* debug
    for (int i = 0; i< MAX; i++)
    {
        for (int i2 = 0; i2 < 10; i2++)
        {
            printf("%s; ",in[i][i2]);
        }
        printf("\n");
    } */
    for (int i = 0; i < MAX; i++) // go through whole list off supporting programmes
    {
        int i4 = 0;
        for (int i3 = 0; i3 < MAX; i3++)
        {
            for (int i2 = 2; i2 < 10; i2++)
            {
                if (strcmp(in[i][0], in[i3][i2]) == 0) // if it appears on RHS of any -> marker, it is not at the bottom. Move on to next.
                {
                    i4 = 1;
                    break;
                }
            }
            if (i4 == 1)
            {
                break;
            }
        }
        if (i4 == 0) // no matches found, this is the bottom programme
        {
            printf("%s\n",in[i][0]);
            return 0;
        }
    }
}

// C substring function definition
// populate sub[] with l chars, starting at p (1st index of s[] is 0)
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
