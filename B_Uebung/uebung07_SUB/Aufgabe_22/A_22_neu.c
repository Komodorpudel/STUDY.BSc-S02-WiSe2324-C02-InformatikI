#include <stdio.h>
#include <string.h> /* für strlen */

#define TRUE 1 /* Vorsicht: Kein ; hin machen */
#define FALSE 0
#define STRING_MAX 20


int is_palindrome(char v[]) /* Beachte: Hier das gleiche wie char* v */
{

    int i;
    /* Länge bestimmten */
    int len = strlen(v);

    for (i = 0; i < len; i++){
        if(v[i] != v[(len - 1) - i]){
            return FALSE;
        }
    }

    return TRUE;

}

int string_reverse(char v[], char w[], int len_w)
{
    int i;
    int j = 0;
    i = strlen(v);

    if(i> len_w){
        return FALSE;
    }

    i--;
    for (; i >= 0; i--){
        w[j] = v[i];
        j++;
    }

    w[j] = '\0'; /* Terminierer */

    return TRUE;
}


int main(int argc, char* argv[]) /* argv[0] enthält den names den programs */
{
    int i;
    char palindrome[STRING_MAX + 1];
    char inverted_palindrome[STRING_MAX + 1];


    if (argc < 2){
        printf("Mindeszahl argmunete beachten\n");
        return 1;
    }

    for (i = 1; i < argc; i++){
        if (is_palindrome(argv[i])){
            printf("%s ist ein Palindrom\n", argv[i]);
        }
        else if (strlen(argv[i]) <= (STRING_MAX / 2)){
            strcpy(palindrome, argv[i]);
            string_reverse(argv[i],inverted_palindrome, STRING_MAX);

            strcat(palindrome, inverted_palindrome);

            printf("Urpsrünglicher Parameter: %s, Neues Palindrome: %s\n", argv[i], palindrome);

        }
        else{
            printf("Kein Palindrome bzw. zu lang um umzuformen\n");
        }
    }






    return 0;
}

