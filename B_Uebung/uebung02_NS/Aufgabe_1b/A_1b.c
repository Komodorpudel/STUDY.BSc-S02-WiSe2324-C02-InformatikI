#include <stdio.h>
#include <ctype.h> /* For isdigit() */

int main(void)
{
    int i = 0;
    int n = 127;

    for (;i <= n; i++) {
        if(isgraph(i)) {
            printf("%i: Ja\n", i);
        }
        else {
            printf("%i: Nein\n", i);
        }
    }

    return 0;
}
