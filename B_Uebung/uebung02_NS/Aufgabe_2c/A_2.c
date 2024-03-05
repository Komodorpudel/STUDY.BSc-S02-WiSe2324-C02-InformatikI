#include <stdio.h>
#include <stdlib.h> /* for abs() */


/* Prototypen */
void manipulate_and_print(int v[], int size);

int main(void)
{
    int numbers[] = {1, -4, 6, 2, -7, 3, 0};

    manipulate_and_print(numbers,7);
    
    return 0;
    
}

void manipulate_and_print(int v[], int size) {

    int i;

    for (i = 0; i < size; i++){
        if(v[i] < 0) {
            switch(abs(v[i] % 4)) {
                case 0:
                    v[i] = 2* v[i];
                    break;
                
                case 1:
                    v[i] = v[i] - 1;
                    break;

                case 2:
                    v[i] = -v[i] + 5;
                    break;

                case 3:
                    break;

            }

            printf("%i\n", v[i]);
        }

        else {
            printf("\n");
        }
    }
}