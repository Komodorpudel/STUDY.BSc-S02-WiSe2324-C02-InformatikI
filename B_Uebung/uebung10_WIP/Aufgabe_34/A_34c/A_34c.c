#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* my_string_copy(char **destination, char *source)
{
    int i = 0;
    destination = malloc((strlen(source) + 1) * sizeof(char));

    if(destination == NULL) {
        return NULL;
    }

    while (source[i] != '\0') {
        destination[i] = *(source + i);
        i++;
    }
    destination[i] = '\0';
    return destination;
}


int main(void)
{
    char *original_string = "Test";
    char *copied_string = "";

    if (my_string_copy(copied_string, original_string) != NULL) {
        printf("Kopierter String: %s\n", copied_string);
        return 0;
    }
    else {
        printf("Fehler beim Allokieren des Speichers.\n");
        return 1;
    }
}