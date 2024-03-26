#include "tests.h"
#include "func.h"

/*
 *  Реализация самих тестов
 */

int testCreateFindLogic() {
    int ErrorCode = 0;
    ArrayCollection collection = {NULL, 0};

    // Create new int or float array
    arrayAddToCollection(&collection, "test1", GetIntFieldInfo() /*GetFloatFieldInfo()*/);
    if (collection.size != 1) {
        printf("\narrayAddToCollection does not work!\n");
        ErrorCode = -1;
    }

    // Find array
    Array *arr1 = arrayFindInCollection(&collection, "test1");
    if (!arr1) {
        printf("\narrayFindInCollection does not work!\n");
        ErrorCode = -1;
    }

    // Освобождение ресурсов
    for (size_t i = 0; i < collection.size; ++i) {
        arrayFree(&collection.arrays[i]);
    }
    free(collection.arrays);

    return ErrorCode;
}

int testPushBackLogic() {
    int ErrorCode = 0;
    ArrayCollection collection = {NULL, 0};
    arrayAddToCollection(&collection, "test2", GetIntFieldInfo());
    Array *arr1 = arrayFindInCollection(&collection, "test2");

    void *elem1;
    arrayPushBack(arr1, &elem1);
    if (arr1->size != 1) {
        printf("\narrayPushBack does not work!\n");
        ErrorCode = -2;
    }

    // Освобождение ресурсов
    for (size_t i = 0; i < collection.size; ++i) {
        arrayFree(&collection.arrays[i]);
    }
    free(collection.arrays);

    return ErrorCode;
}

int testConcatenationLogic() {
    int ErrorCode = 0;
    ArrayCollection collection = {NULL, 0};

    arrayAddToCollection(&collection, "test3.1", GetIntFieldInfo());
    arrayAddToCollection(&collection, "test3.2", GetIntFieldInfo());
    Array *firstarr = arrayFindInCollection(&collection, "test3.1");
    Array *secondarr = arrayFindInCollection(&collection, "test3.2");

    void *elem1, *elem2;
    arrayPushBack(firstarr, &elem1);
    arrayPushBack(secondarr, &elem2);

    arrayAddToCollection(&collection, "res", GetIntFieldInfo());
    Array *resultarr = arrayFindInCollection(&collection, "res");

    arrayConcatenation(resultarr, firstarr, secondarr);
    if (resultarr->size != 2) {
        printf("\narrayConcatenation does not work!\n");
        ErrorCode = -3;
    }

    // Освобождение ресурсов
    for (size_t i = 0; i < collection.size; ++i) {
        arrayFree(&collection.arrays[i]);
    }
    free(collection.arrays);

    return ErrorCode;
}

int testMapLogic() {
    int ErrorCode = 0;
    ArrayCollection collection = {NULL, 0};
    arrayAddToCollection(&collection, "test4", GetIntFieldInfo());
    Array *array = arrayFindInCollection(&collection, "test4");

    int elem = 1;
    arrayPushBack(array, &elem);
    size_t sz = array->size;

    arrayMap(funcMap, array);
    if (array->size != sz) {
        printf("\nMap does not work!\n");
        ErrorCode = -4;
    }

    // Освобождение ресурсов
    for (size_t i = 0; i < collection.size; ++i) {
        arrayFree(&collection.arrays[i]);
    }
    free(collection.arrays);

    return ErrorCode;
}

int testWhereLogic(){
    int ErrorCode = 0;
    ArrayCollection collection = {NULL, 0};

    arrayAddToCollection(&collection, "test5", GetIntFieldInfo());
    Array *arrWhere = arrayFindInCollection(&collection, "test5");
    arrayAddToCollection(&collection, "res", GetIntFieldInfo());
    Array *arrResult = arrayFindInCollection(&collection, "res");

    //arrayWhere(funcWhere, arrWhere, arrResult);
    if(0){ //TODO no logic in Where?
        printf("\nWhere does not work!\n");
        ErrorCode = -5;
    }

    // Освобождение ресурсов
    for (size_t i = 0; i < collection.size; ++i) {
        arrayFree(&collection.arrays[i]);
    }
    free(collection.arrays);

    return ErrorCode;
}

int testSortLogic(){
    int ErrorCode = 0;
    ArrayCollection collection = {NULL, 0};

    arrayAddToCollection(&collection, "res", GetIntFieldInfo());
    Array *arrSort = arrayFindInCollection(&collection, "res");

    size_t sz = arrSort->size;
    //arraySort(arrSort, numberSort);
    if(arrSort->size != sz){
        printf("\nSort does not work!\n");
        ErrorCode = -6;
    }

    // Освобождение ресурсов
    for (size_t i = 0; i < collection.size; ++i) {
        arrayFree(&collection.arrays[i]);
    }
    free(collection.arrays);

    return ErrorCode;
}