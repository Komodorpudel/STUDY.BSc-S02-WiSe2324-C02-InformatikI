#include <limits.h>

#include "arraylist.h"

int arraylist_iselemBinSearcH(arraylist *m, int n){
    int left = 0;
    int right = m -> size -1;
    int mid;

    while (left < right -1){
        /* Mitte: */
        mid = (left + right) / 2; 

        if(n == m -> elements[mid]){
            return 1;
        }
        else if(n > m -> elements[mid]){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    return 0;
}

