#include "float.h"

/*
 *  Работа с float
 */

void floatPrint(const void *elem) {
    printf("%f ", *(const float *) elem);
}

int floatSort(void* element1, void* element2){
    if (*(float*)element1 > *(float*)element2){
        return 1;
    } else {
        return 0;
    }
}