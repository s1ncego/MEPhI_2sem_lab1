#include "float.h"

/*
 *  Работа с float
 */

void floatPrint(const void *elem) {
    printf("%f ", *(const float *) elem);
}


void floatSwap(const void *a, const void *b, const void *help) {
    help = a;
    a = b;
    b = help;
}

int floatSort(void* element1, void* element2){
    if (*(float*)element1 > *(float*)element2){
        return 1;
    } else {
        return 0;
    }
}