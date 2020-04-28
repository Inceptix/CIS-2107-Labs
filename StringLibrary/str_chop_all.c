#include "libstr2107.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char **str_chop_all(char *s, char c)
{
int i = 0;
int tokens = 0;
char **result;
char *t, *p, *r;

t = s;
while(*t != '\0')
{
 if(*t == c)
 {
 tokens++;
 }
 t++;
}
tokens++;

if ((result=(char**)malloc((tokens+1)*sizeof(char*)))== '\0')
{
    return '\0';
}

t = s;
p = t;
i = 1;
tokens = 0;

while(*t != '\0')
{
 if(*t == c)
 {
 result[tokens] = (char *)malloc(i + 1);
 r = result[tokens];
 while(p != t)
 {
 *r = *p;
 p++;
 r++;
 }
 *r = '\0';
 p++;
 tokens++;
 }
 t++;
 i++;
}

result[tokens] = (char *)malloc(i + 1);
r = result[tokens];
while(p != t)
{
 *r = *p;
 p++;
 r++;
}
*r = '\0';
tokens++;
result[tokens] = '\0';

return result;
}
