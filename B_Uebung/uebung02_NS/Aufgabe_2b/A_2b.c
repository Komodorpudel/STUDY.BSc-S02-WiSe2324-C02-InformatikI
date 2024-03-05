#include <stdio.h>
#include <ctype.h>

/* Prototypen */
void copy_only_digits(char v[], char w[], int size);


int main(void)
{
    char char1[] = {'H', '4', '1', '1', 'o', '\0'};
    char char2[] = {'I', 'n', 'f', 'o', 'r', 'm', 'a', 't', 'i', 'k', '1', '\0'};

    char w[12];

    copy_only_digits(char1, w, 6);
    printf("chars1: %s\n", w);

    copy_only_digits(char2, w, 12);
    printf("chars1: %s\n", w);

}

void copy_only_digits(char v[], char w[], int size) /* returned nichts, logisch, weil w ist pointer */
{
    int i;
    
    for (i = 0; i < size; i++) {

        if(isdigit(v[i]) || v[i] == '\0') {
            w[i] = v[i];
        }
        
        else {
            w[i] = '0';
        }
    }

}