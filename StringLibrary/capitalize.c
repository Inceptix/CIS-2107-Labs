#include "libstr2107.h"
#include <ctype.h>
#include <stdio.h>

void capitalize(char *s1)
{

    int len1=0;

    while(s1[len1]!='\0')
    {

        if(len1==0){ //check for first word

        if(s1[len1]>='a' && s1[len1]<='z')
        {
            s1[len1]-=32;

        }

    }
    else
    {
        if(s1[len1]>='A' && s1[len1]<='Z')
        {
            s1[len1]+=32;
        }

    }

    len1++;

    }

}
