#include "array.h"

/*
 * Интерфейс для работы с массивами
 */

void arrayInit(Array *m, size_t elemSize, PrintArrayElement printElement) {
    m->data = malloc(elemSize);
    m->size = 0;
    m->elemSize = elemSize;
    m->printElement = printElement;
}

void arrayPushBack(Array *m, const void *elem) {
    // добавить проверку на соответствие типа добавляемого элемента
    m->data = realloc(m->data, (m->size + 1) * m->elemSize);
    mempcpy((char *) m->data + m->size * m->elemSize, elem, m->elemSize);
    m->size++;
}

void arrayFree(Array *m) {
    free(m->data);
    m->data = 0;
    m->size = 0;
    m->elemSize = 0;
}

void arrayPrintElements(const Array *m) {
    for (size_t i = 0; i < m->size; ++i) {
        m->printElement((const char *) m->data + i * m->elemSize);
    }
}

void arrayAddToCollection(ArrayCollection *collection, const char *name, size_t elemSize, PrintArrayElement printElem) {
    collection->arrays = realloc(collection->arrays, (collection->size + 1) * sizeof(Array));
    Array *newArr = &collection->arrays[collection->size];
    strcpy(newArr->name, name);
    arrayInit(newArr, elemSize, printElem);
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
        arrayPushBack(res, (const char *) m1->data + i * m1->elemSize);
    }
    for (size_t i = 0; i < m2->size; ++i) {
        arrayPushBack(res, (const char *) m2->data + i * m2->elemSize);
    }
}

void arrayMap(void (*func)(void *), Array *arrayMap) {
    for (size_t i = 0; i != arrayMap->size; ++i) {
        (*func)((void *) arrayMap->data + i * arrayMap->elemSize);
    }
}

void arrayWhere(int (*func)(void *), Array *arrayWhere, Array *arrayWhereRes) {
    for (size_t i = 0; i < arrayWhere->size; ++i) {
        if ((*func)((void *) arrayWhere->data + i * arrayWhere->elemSize)) {
            arrayPushBack(arrayWhereRes, (void *) arrayWhere->data + i * arrayWhere->elemSize);
        }
    }
}

void arraySort(Array *array, SortArrayElement sortArray) {
    for (size_t j = 0; j < array->size - 1; ++j) {
        for (size_t i = 0; i < array->size - 1; ++i) {
            if (sortArray((void *) array->data + i * array->elemSize,
                          (void *) array->data + (i + 1) * array->elemSize)) {
                void *help;
                numberSwap((void *) array->data + i * array->elemSize, (void *) array->data + (i + 1) * array->elemSize,
                           &help);
            }
        }
    }
}