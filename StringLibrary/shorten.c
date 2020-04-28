#include "libstr2107.h"
#include <stdio.h>

void shorten(char *s, int new_len)

{

    int len = 0;
    char *s1 = s;

    while (*(s1++) != '\0')
    {
        len++;
    }


    if (new_len < len)
    {
        s[new_len] = '\0';
    }

}
