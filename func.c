#include "func.h"

/*
 * Работа кастомных функций
 */

void funcMap(void *elem) { // тестовая функция для проверки Map (+1 каждый элемент)
    int *intPtr = (int *) elem;
    *intPtr = *intPtr + 1;
}

int funcWhere(void *elem) { // тестовая функция для проверки Where (ищем четные числа)
    int *intPtr = (int *) elem;
    if (*intPtr % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}