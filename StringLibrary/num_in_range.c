#include "libstr2107.h"
#include <stdio.h>

int num_in_range(char *s1, char b, char t)

{

    int count=0;

    while (*s1 != '\0')

    {

        if(b <= *s1 && *s1 <= t)

        count++;

        s1++;

    }

    return count;

}

//function to return the number of characters that differ


//function to return the number of characters that differ
