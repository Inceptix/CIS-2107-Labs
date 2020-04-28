#include "libstr2107.h"
#include <ctype.h>
#include <stdio.h>

void take_last(char *s, int n)
{

    int len = 0;
    char *s1 = s;

    while (*(s1++) != '\0')
    {
        len++;
    }

    if (n >= len)
        return;

    for (int i = n; s[i] != '\0'; i++)
    {

        printf("%c", s[i]);

    }

}
