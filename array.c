#include "array.h"

/*
 * Интерфейс для работы с массивами
 */

void arrayInit(Array *m, FieldInfo *GetElem) {
    m->data = malloc(GetElem->elemSize);
    m->size = 0;
    m->fieldinfo = *GetElem;
}

void arrayPushBack(Array *m, const void *elem) {
    m->data = realloc(m->data, (m->size + 1) * m->fieldinfo.elemSize);
    if (m->data == NULL) {
        printf("\nFailed memory action!\n");
    }
    mempcpy((char *) m->data + m->size * m->fieldinfo.elemSize, elem, m->fieldinfo.elemSize);
    m->size++;
}

void arrayFree(Array *m) {
    free(m->data);
    m->data = 0;
    m->size = 0;
    m->fieldinfo.elemSize = 0;
}

void arrayPrintElements(const Array *m) {
    for (size_t i = 0; i < m->size; ++i) {
        m->fieldinfo.printElement((const char *) m->data + i * m->fieldinfo.elemSize);
    }
}

void arrayAddToCollection(ArrayCollection *collection, const char *name, FieldInfo *GetField) {
    collection->arrays = realloc(collection->arrays, (collection->size + 1) * sizeof(Array));
    if (collection->arrays == NULL) {
        printf("\nFailed memory action!\n");
    }
    Array *newArr = &collection->arrays[collection->size];
    strcpy(newArr->name, name);
    arrayInit(newArr, GetField);
    collection->size++;
}

Array *arrayFindInCollection(ArrayCollection *collection, const char *name) {
    for (size_t i = 0; i < collection->size; ++i) {
        if (strcmp(collection->arrays[i].name, name) == 0) {
            return &collection->arrays[i];
        }
    }
    return NULL;
}

void arrayConcatenation(Array *res, Array *m1, Array *m2) {

    for (size_t i = 0; i < m1->size; ++i) {
        arrayPushBack(res, (const char *) m1->data + i * m1->fieldinfo.elemSize);
    }
    for (size_t i = 0; i < m2->size; ++i) {
        arrayPushBack(res, (const char *) m2->data + i * m2->fieldinfo.elemSize);
    }
}

void arrayMap(void (*func)(void *), Array *arrayMap) {
    for (size_t i = 0; i != arrayMap->size; ++i) {
        (*func)((void *) arrayMap->data + i * arrayMap->fieldinfo.elemSize);
    }
}

void arrayWhere(int (*func)(void *), Array *arrayWhere, Array *arrayWhereRes) {
    for (size_t i = 0; i < arrayWhere->size; ++i) {
        if ((*func)((void *) arrayWhere->data + i * arrayWhere->fieldinfo.elemSize)) {
            arrayPushBack(arrayWhereRes, (void *) arrayWhere->data + i * arrayWhere->fieldinfo.elemSize);
        }
    }
}

void arraySort(Array *array, SortArrayElement sortArray) {
    for (size_t j = 0; j < array->size - 1; ++j) {
        for (size_t i = 0; i < array->size - 1; ++i) {
            if (sortArray((void *) array->data + i * array->fieldinfo.elemSize,
                          (void *) array->data + (i + 1) * array->fieldinfo.elemSize)) {
                void *help;
                numberSwap((void *) array->data + i * array->fieldinfo.elemSize,
                           (void *) array->data + (i + 1) * array->fieldinfo.elemSize,
                           &help);
            }
        }
    }
}