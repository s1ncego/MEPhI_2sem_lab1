#ifndef LAB1BUNTSEV_MENU_H
#define LAB1BUNTSEV_MENU_H

#include <stdio.h>

/*
 * Заголовочный файл интерфейса (меню)
 */

void printMenu() {
    printf("\n---=== Menu ===---\n");
    printf("  0. Show arrays\n");
    printf("  1. Create new int array\n");
    printf("  2. Create new float array\n");
    printf("  3. Add element to int array\n");
    printf("  4. Add element to float array\n");
    printf("  5. Show array by name\n");
    printf("  6. Concatenate arrays\n");
    printf("  7. Map\n");
    printf("  8. Where\n");
    printf("  9. Sort array\n");
    printf("Enter 'STOP' to finish.\n");
    printf("Press 0-9 to choose the action:\n");
}

#endif