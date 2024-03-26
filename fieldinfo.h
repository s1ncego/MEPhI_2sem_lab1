#ifndef LAB1BUNTSEV_FIELDINFO_H
#define LAB1BUNTSEV_FIELDINFO_H

/*
 * Заголовочный файл для работы с fieldinfo
 */

#include <stdlib.h>
#include "number.h"
#include "float.h"

typedef void (*PrintArrayElement)(const void *el);

typedef int (*SortArrayElement)(void *elem1, void *elem2);

typedef struct {
    char *typeName;
    size_t elemSize;
    PrintArrayElement printElement;
    SortArrayElement sortElement;
} FieldInfo;

FieldInfo *GetIntFieldInfo();

FieldInfo *GetFloatFieldInfo();

#endif