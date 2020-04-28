#include "libstr2107.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char *dedup(char *s)
{
    char *t = s;
    char *r, *p, *q;
    int i;
    int c = 0;
    while(*t != '\0')
    {
         c++;
         t++;
    }
    r = (char *)malloc(c + 1);
    q = r;
    for(i = 0;i<c;i++,q++)
    {
         *q = '\0';
         q++;
    }

    t = s;
    p = r;
    while(*t != '\0')
    {
         q = r;
         while(*q != *t && *q != '\0')
         {
            q++;
         }
         if(*q == '\0')
         {
             *p = *t;
             p++;
             t++;
         }
         else
         {
            t++;
         }
    }
    *p = '\0';

return r;
}
