#include "libstr2107.h"
#include <stdio.h>

int diff(char *s1, char *s2)

{

    int count = 0;

    while ( *(s1++) != '\0' && *(s2++) != '\0' )

    {

        if(*s1 != *s2)
        {
            count++;

        }

        while( *(s1) != '\0' && *(s2) == '\0')
        {
            count++;
            s1++;
        }

        while( *(s2) != '\0' && *(s1) == '\0')
        {
            count++;
            s2++;
        }


    }



    return count-1;

}
