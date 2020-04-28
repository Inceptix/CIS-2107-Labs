#include "libstr2107.h"
#include <stdio.h>

int find(char *h, char* n)
{

    for (int i = 0; h[i] != '\0'; i++)
    {
        if (*n == (h[i]))
            return i;
    }

    return -1;

}
