#ifndef LAB1BUNTSEV_ARRAY_H
#define LAB1BUNTSEV_ARRAY_H

#include <string.h>
#include "fieldinfo.h"

/*
 * Заголовочный файл для работы с массивами
 */

typedef struct {
    char name[20];
    void *data;
    size_t size;
    FieldInfo fieldinfo;
//    size_t elemSize;
//    PrintArrayElement printElement;
//    SortArrayElement sortElement;
} Array;

typedef struct {
    Array *arrays;
    size_t size;
} ArrayCollection;

//void arrayInit(Array *m, size_t elemSize, PrintArrayElement printElement);
void arrayInit(Array *m, FieldInfo *GetElem);

void arrayPushBack(Array *m, const void *elem);

void arrayFree(Array *m);

void arrayPrintElements(const Array *m);

//void arrayAddToCollection(ArrayCollection *collection, const char *name);
void arrayAddToCollection(ArrayCollection *collection, const char *name, FieldInfo *GetField);

Array *arrayFindInCollection(ArrayCollection *collection, const char *name);

void arrayConcatenation(Array *res, Array *m1, Array *m2);

void arrayMap(void (*func)(void *), Array *mapArray);

void arrayWhere(int (*func)(void *), Array *arrayWhere, Array *arrayWhereRes);

void arraySort(Array *array, SortArrayElement sortArray);

#endif