#include <stdio.h>

//Funktionen
int sum_even (int n, int m);


int main() {
    int n = 4;
    int m = 1;
    int summe =   sum_even ( n,  m);
    printf("%i", summe);
  


    return 0;
}


int sum_even (int n, int m)
{ 
    int summe = 0;
    int start = 0 ;
    int ende = 0 ;
    // Prüfen ob  n größer m ist
    if (m < n){

        ende = n ; 
        start = m;
    } else {
        ende = m;
        start = n;
    }
// gerade zahlen zwischen n und m prüfen

    for (; start <= ende; start++ ){

        if( start %2 ==0 ){
            summe= summe + start;

        }
    }

    return summe;

}