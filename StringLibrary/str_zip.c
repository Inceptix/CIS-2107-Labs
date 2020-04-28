#include "libstr2107.h"
#include <stdio.h>

char *str_zip(char* s1, char* s2, char *output)
{

    while (*s1 != '\0' && *s2 != '\0')
    {
        *(output++)=  *(s1++);
        *(output++) = *(s2++);
    }

    while (*s1 != '\0')
        *output++ = *s1++;
    while (*s2 != '\0')
        *output++ = *s2++;

    *output='\0';

    return output;

}
