#include "libstr2107.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    char *s = "Yellow";
    char *s1 = "  sir";
    char *s2 = "yellow";
    char *s3 = "yalloeeeee";
    char s4[50] = "yellow";
    char s5[50] = "  y el l o w";
    char *s6 = "sir   n";
    char *s7 = "   ";
    char output[200];
    char s8[50] = "yellow";
    char *s9 = "There's always money in the banana stand.";
    char **arr;
    char s10[50] = "i like c";


    puts("Test for all_letters - Yellow");
    int letters = all_letters(s);
    printf("%d\n\n", letters);

    puts("Test for all_letters - yellow ");
    int letters2 = all_letters(s2);
    printf("%d\n\n", letters2);


    puts("Test for num_in_range");
    int numInRange = num_in_range(s, 'f', 'm');
    printf("%d\n\n", numInRange);

    puts("Test for diff - yellow, yalloeeeee");
    int charDiff = diff(s2, s3);
    printf("%d\n\n", charDiff);

    puts("Test for shorten - yalloeeeee");
    shorten(s4, 4);
    printf("%s\n\n", s4);

    puts("Test for rm_left_space -  sir");
    rm_left_space(s1);
    puts("");
    puts("");

    puts("Test for rm_space -  y el l o w");
    rm_space(s5);
    printf("%s\n\n", s5);

    puts("Test for rm_right_space -  sir   n");
    rm_right_space(s6);
    puts("");
    puts("");

    puts("Test for find -  sir   n");
    int findChar = find(s6, "r");
    printf("%d\n\n", findChar);

    puts("Test for find -  sir   n");
    char *findCharPtr = ptr_to(s6, "r");
    printf("%p\n\n", findCharPtr);

    puts("Test for is_empty - s7");
    int cEmpty = is_empty(s7);
    printf("%d\n\n", cEmpty);

    puts("Test for str_zip - Yellow yellow");
    str_zip(s, s2, output);
    printf("%s\n\n", output);

    puts("Test for str_zip - Yellow yellow");
    int strIgnCmp = strcmp_ign_case(s, s2);
    printf("%d\n\n", strIgnCmp);

    puts("Test for take_last - yellow,3");
    take_last(s8, 3);
    printf("\n\n");

    puts("Test for dedup - There's always money in the banana stand.");
    char *cDedup = dedup(s9);
    printf("%s\n\n", cDedup);

    puts("Test for ends_with_ignore_case - yellow, ow");
    int cSuffix = ends_with_ignore_case(s2, "fow");
    printf("%d\n\n", cSuffix);

//    puts("Test for replace - yellow, ow, us");
//    char *cReplace = custom_replace(s2, "ow", "us");
//    printf("%s", cReplace);

    puts("Test for capitalize");
    capitalize(s10);
    printf("%s\n\n", s10);

    puts("Test for chop");
    arr = str_chop_all(s9, ' ');
    for(int i = 0; arr[i] != NULL; i++)
    {
        printf("word  %d: %s\n", i, arr[i]);
    }

    return 0;

}
