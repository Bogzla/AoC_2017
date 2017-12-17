#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int MAX = 16;
char lin[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
void inst(char *c);
void spin(char *c);
void xchange(char *c);
void xchangec(char *c);

int main(void)
{
    char *s;
    int ln = 0;
    char ins[7];
    if (scanf("%ms", &s) != EOF) //read in input. declaring char *s and using %m modifier allows dynamic memory allocation
    for (int i = 0, n = strlen(s)+1; i < n; i++) // remember strlen doesn't count null terminator
    {
//        printf("%i ",s[i]);
        if ((s[i] == ',') || (s[i] == '\0'))
        {
            ins[ln] = '\0';
            ln = 0;
            inst(ins);
        }
        else
        {
            ins[ln] = s[i];
            ln++;
        }
    }
    free(s);
    for (int i = 0; i < MAX; i++)
    {
        printf("%c",lin[i]);
    }
    printf("\n");
}
// instruction director
void inst(char *c)
{
    if (c[0] == 's')
    {
        spin(c);
    }
    else if (c[0] == 'x')
    {
        xchange(c);
    }
    else if (c[0] == 'p')
    {
        xchangec(c);
    }
}
// spin chars, use modulo to spin chars into new positions in 2nd array then copy back
void spin(char *c)
{
    char lin2[MAX];
    char spn[3];
    for (int i = 0, n = strlen(c); i < n; i++)
    {
        spn[i] = c[i+1]; // copy spin qty
    }
    int sp = atoi(spn) % MAX;
    if (sp != 0)
    {
        for (int i = 0; i < MAX; i++)
        {
            lin2[(i + sp) % MAX] = lin[i];
        }
        for (int i = 0; i < MAX; i++)
        {
            lin[i] = lin2[i];
        }
    }
}
// exchange characters based on position.
void xchange(char *c)
{
    char a[3];
    char b[3];
    int j = 0;
    // first determine positions
    for (int i = 1, n = strlen(c)+1; i < n; i++)
    {
        if (c[i] == '/')
        {
            a[i-1] = '\0';
        }
        else if (c[i] == '\0')
        {
            b[j] = '\0';
        }
        else if (i < 3)
        {
            a[i-1] = c[i];
        }
        else
        {
            b[j] = c[i];
            j++;
        }
    }
    // then swap
    char d = lin[atoi(a)];
    char e = lin[atoi(b)];
    lin[atoi(b)] = d;
    lin[atoi(a)] = e;
}
// swap chars based on what they are
void xchangec(char *c)
{
    char a = c[1];
    int aa;
    char b = c[3];
    int bb;
    // first find their positions
    for (int i = 0; i < MAX; i++)
    {
        if (lin[i] == a)
        {
            aa = i;
        }
        else if (lin[i] == b)
        {
            bb = i;
        }
    }
    // then swap
    char d = lin[aa];
    char e = lin[bb];
    lin[bb] = d;
    lin[aa] = e;
}
