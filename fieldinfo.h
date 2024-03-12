#ifndef LAB1BUNTSEV_FIELDINFO_H
#define LAB1BUNTSEV_FIELDINFO_H

/*
 * Заголовочный файл для работы с fieldinfo
 */

#include <stdlib.h>
#include "number.h"
#include "float.h"

typedef void (*printArrayElement)(const void *element);

typedef int (*sortArrayElement)(void *element1, void *element2);

typedef struct {
    char *typeName;
    size_t elemSize;
    printArrayElement printElement;
    sortArrayElement sortElement;
} FieldInfo;

FieldInfo *GetIntFieldInfo();

FieldInfo *GetFloatFieldInfo();

#endif