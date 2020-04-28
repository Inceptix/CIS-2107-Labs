#include "libstr2107.h"
#include <stdio.h>

char *ptr_to(char *h, char* n)
{

    for (int i = 0; h[i] != '\0'; i++)
    {
        if (*n == (h[i]))
            return n;
    }

    return NULL;

}
