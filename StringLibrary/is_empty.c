#include "libstr2107.h"
#include <stdio.h>
#include <ctype.h>

int is_empty(char *s)
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

    if ((i-1) == count)
    {
        return 1;
    }

    if (s[0] == '\0')
    {
        return 1;
    }

    return 0;

}
