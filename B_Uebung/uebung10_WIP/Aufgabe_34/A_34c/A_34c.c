#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_string_copy(char **destination, char *source)
{
    int i = 0;
    *destination = malloc((strlen(source) + 1) * sizeof(char));
    /* Fehler: *destination anstatt destination - Wir müssen ja da hin wo destination zeigt und da Platz frei machen */

    if(*destination == NULL) {
        return NULL;
    }

    while (source[i] != '\0') {
        (*destination)[i] = *(source + i);
        /* Fehler: (*destination) anstatt destination: * hat niedrigere prio als [], wir müssen aber zuerst dereferenzieren */
        i++;
    }
    (*destination)[i] = '\0';
    /* Selbes Problem hier */

    return *destination;
    /* Fehler: *destination anstatt destination, die Funktion muss ja char* zurückgeben und nicht char** */
}


int main(void)
{
    char *copied_string = NULL; /* Unser Ziel */
    /* Fehler: NULL anstatt "", das ist ja ein Pointer  */
    
    char *original_string = "Test";

    if (my_string_copy(&copied_string, original_string) != NULL) {
        /* Fehler:
        &copied_string anstatt copied_string. Wieso? my_string_copy will einen pointer haben auf einen pointer, ansonsten würde copied_string danach immernoch auf NULL zeigen. Oder in anderen Worten: Via malloc wollen wir ändern auf was copied_string zeigt. Das geht nur wenn wir einen Zeiger auf copied_string übergeben
        
        origina_string passt so, weil wir hier ja nur lesen wollen und nicht schreiben.*/
        
        printf("Kopierter String: %s\n", copied_string);
        return 0;
    }
    else {
        printf("Fehler beim Allokieren des Speichers.\n");
        return 1;
    }
}