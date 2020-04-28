#include "libstr2107.h"
#include <stdio.h>

void rm_space(char *s)
{

    // To keep track of non-space character count
    int count = 0;

    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; s[i]; i++)
        if (s[i] != ' ')
            s[count++] = s[i]; // here count is
                                   // incremented
    s[count] = '\0';

}
