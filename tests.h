#ifndef LAB1BUNTSEV_TESTS_H
#define LAB1BUNTSEV_TESTS_H

#include "array.h"
#include "number.h"
#include "float.h"
#include <stdio.h>

/*
 * Заголовочный файл для тестов
 */

//arrayNamedInit(), arrayPrintElements(), arrayFree() - работают априори

// return 0 - ok
int testCreateFindLogic(); // error: return -1

int testPushBackLogic(); // error: return -2

int testConcatenationLogic(); // error: return -3

int testMapLogic(); // error: return -4

int testWhereLogic(); // error: return -5

int testSortLogic(); // error: return -6

#endif