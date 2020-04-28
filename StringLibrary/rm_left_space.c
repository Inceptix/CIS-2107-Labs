#include "libstr2107.h"
#include <stdio.h>
#include <ctype.h>



void rm_left_space(char *s)
{
    char ch = s[0];
    int count = 0;
    int i = 0;

    while (ch != '\0') {
        ch = s[i];
        if (isspace(ch))
            count++;

        i++;
    }


    for (int j = count; s[j] != '\0'; j++)
    {
        printf("%c", s[j]);
    }

}
