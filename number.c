#include "number.h"

/*
 *  Работа с int
 */

void numberPrint(const void *elem) {
    printf("%d ", *(const int *) elem);
}

void numberSwap(void *a, void *b, void *help) {
    *(int *) help = *(int *) a;
    *(int *) a = *(int *) b;
    *(int *) b = *(int *) help;
}

int numberSort(void *element1, void *element2) {
    if (*(int *) element1 > *(int *) element2) {
        return 1;
    } else {
        return 0;
    }
}