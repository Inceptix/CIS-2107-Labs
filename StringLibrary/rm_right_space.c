#include "libstr2107.h"
#include <stdio.h>
#include <ctype.h>


void rm_right_space(char *s)
{

    char ch = s[0];
    int count = 0;
    int i = 0;

    //counts space
    while (ch != '\0') {
        ch = s[i];
        if (isspace(ch))
            count++;

        i++;
    }


    for (int j = 0; j < (i-count); j++)
    {
        printf("%c", s[j]);
    }

}
