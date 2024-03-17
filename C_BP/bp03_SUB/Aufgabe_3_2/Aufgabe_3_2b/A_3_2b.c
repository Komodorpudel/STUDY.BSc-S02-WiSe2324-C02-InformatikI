#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

//Functions
double my_tolower (int c);

int main() {

    int c;
    int e;

    // random number to decrement
    srand(time(NULL));
    c = rand() % 128;

    e = my_tolower(c);

    printf("c: %c und my_tolower: %c", c, e);

    return 0;   

}

double my_tolower (int c){

    if (c >= 'A' && c <= 'Z') {
        return ('a' + (c - 'A')); 
    }
    return c;

}