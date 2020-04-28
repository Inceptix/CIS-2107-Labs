#include "libstr2107.h"
#include <ctype.h>
#include <stdio.h>

int ends_with_ignore_case(char *s, char *suff)
{
    int c = 0;
    char *t = suff;
    while(*t != '\0')
    {
         t++;
         c++;
    }

    t = s;
    while(*t != '\0')
    {
        t++;
    }

    t = t -c;
    char *p = suff;
    char ignoreSuff = tolower(*p);
    char ignoreStr = tolower(*t);
    while(ignoreSuff == ignoreStr && *p !='\0' && *t != '\0')
    {
         p++;
         t++;
         ignoreSuff = tolower(*p);
         ignoreStr = tolower(*t);
    }

    if(*p == '\0')
        return 1;
    else
        return 0;
}
