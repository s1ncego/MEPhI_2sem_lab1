#ifndef LAB1BUNTSEV_ARRAY_H
#define LAB1BUNTSEV_ARRAY_H

#include <string.h>
#include <stdlib.h>
#include "number.h"

/*
 * Заголовочный файл для работы с массивами
 */

typedef void (*PrintArrayElement)(const void *el);

typedef int (*SortArrayElement)(void *elem1, void *elem2);

typedef struct {
    char name[20];
    void *data;
    size_t size;
    size_t elemSize;
    PrintArrayElement printElement;
    SortArrayElement sortElement;
} Array;

/*typedef struct {
    char name[20];
    Array array;
} NamedArray;*/

typedef struct {
    Array *arrays;
    size_t size;
} ArrayCollection;

void arrayInit(Array *m, size_t elemSize, PrintArrayElement printElement);

void arrayPushBack(Array *m, const void *elem);

void arrayFree(Array *m);

void arrayPrintElements(const Array *m);

void arrayAddToCollection(ArrayCollection *collection, const char *name, size_t elemSize, PrintArrayElement printElem);

Array *arrayFindInCollection(ArrayCollection *collection, const char *name);

void arrayConcatenation(Array *res, Array *m1, Array *m2);

void arrayMap(void (*func)(void *), Array *mapArray);

void arrayWhere(int (*func)(void *), Array *arrayWhere, Array *arrayWhereRes);

void arraySort(Array *array, SortArrayElement sortArray);

#endif