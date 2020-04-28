#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cartoon
{
    char name[20];
}hero;

char* assign(struct cartoon *cartoonPtr)
{
    strcpy(cartoonPtr->name, "Batman");
    return cartoonPtr->name;
}

int main()
{
    strcpy(hero.name, "Spiderman");
    printf("%s %s", hero.name, assign(&hero));
    return 0;

}
