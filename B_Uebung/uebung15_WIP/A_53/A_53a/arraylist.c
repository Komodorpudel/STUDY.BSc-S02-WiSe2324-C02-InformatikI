#include <limits.h>

#include "arraylist.h"

int arraylist_get(arraylist *m, int index){

    if ( index > m -> size - 1){
        return INT_MIN;
    }

    return m -> elements[index];

}