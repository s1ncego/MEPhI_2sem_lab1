#include "fieldinfo.h"

/*
 * Работа с fieldinfo
 */

static FieldInfo *FLOAT_FieldInfo = NULL;
static FieldInfo *INT_FieldInfo = NULL;

FieldInfo *GetIntFieldInfo() {
    if (INT_FieldInfo == NULL) {
        INT_FieldInfo = malloc(sizeof(FieldInfo));
        INT_FieldInfo->typeName = "int";
        INT_FieldInfo->elemSize = sizeof(int);
        INT_FieldInfo->printElement = numberPrint;
        INT_FieldInfo->sortElement = numberSort;
    }
    return INT_FieldInfo;
}

FieldInfo *GetFloatFieldInfo() {
    if (FLOAT_FieldInfo == NULL) {
        FLOAT_FieldInfo = malloc(sizeof(FieldInfo));
        FLOAT_FieldInfo->typeName = "float";
        FLOAT_FieldInfo->elemSize = sizeof(float);
        FLOAT_FieldInfo->printElement = floatPrint;
        FLOAT_FieldInfo->sortElement = floatSort;
    }
    return FLOAT_FieldInfo;
}