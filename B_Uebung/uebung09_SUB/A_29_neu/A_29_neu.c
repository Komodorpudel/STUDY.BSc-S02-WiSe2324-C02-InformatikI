#include <stdio.h>

#define MAX_STRING 6
#define BUFFER_ERROR -1
#define VALID 1
#define INVALID 0

/* ------------------------------------------------------ */
/* Aus Vorlesung */
int flush_buff(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    return c != EOF; /* Returned 1 wenn wahr */
}

/* ------------------------------------------------------ */

int main(void)
{

}

/* ------------------------------------------------------ */

int read_string(char input[])
{
    char c; /* Char den ich mit getchar befülle und teste */
    int i = 0;

    while ((c = getchar() != '\n') && i < MAX_STRING){
        /* Prüfen ob EOF Fehler */
        if(c == EOF){
            return BUFFER_ERROR;
        }
        /* Ansonsten anhängen */
        input[i] = c;
        i++;


    }
    
    /* Prüfen ob zu Lang */
    if (i == MAX_STRING && c !='\n' ){

        if (!flush_buff()){
            return BUFFER_ERROR;
        }

        return INVALID;
    }
}

/* ------------------------------------------------------ */
