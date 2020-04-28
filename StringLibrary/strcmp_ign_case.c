#include "libstr2107.h"
#include <ctype.h>
#include <stdio.h>

int strcmp_ign_case(char *s1, char *s2)
{
    char *t = s1;
    char *p = s2;
    char first = tolower(*t);
    char second = tolower(*p);
    int result = first - second;
    while(result == 0 && *t != '\0' && *p !='\0')
    {
         first = tolower(*t);
         second = tolower(*p);
         result = first - second;
         t++;
         p++;
    }
    if(*t == '\0' && *p!='\0')
    {
        return -1;
    }
    if(*t != '\0' && *p=='\0')
    {
        return 1;
    }

    return result;
}
