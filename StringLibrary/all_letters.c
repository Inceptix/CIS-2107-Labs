#include "libstr2107.h"
#include <stdio.h>

int all_letters(char *s)

{                      //open the loop

    int i=0;

    while(s[i]!='\0')

    {          //open the loop

        if(s[i]>='a'&&s[i]<='z')

            i++;      //representation of increment

        else

            break;

    }          //close the loop

    if(s[i]=='\0')

        return(1);

    i=0;

    while(s[i]!='\0')

    {          //open the loop

    if(s[i]>='A'&&s[i]<='Z')

        i++;      //representation of increment

    else

        break;

    }          //close the loop

    if(s[i]=='\0')

        return(1);

return(0);

}          //close the loop
