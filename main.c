#include "array.h"
#include "number.h"
#include "float.h"
#include "tests.h"
#include "Menu.h"
#include "func.h"
#include "fieldinfo.h"

int main() {
    // Юнит-тесты перед переходом в меню
    if (testCreateFindLogic() == -1 || testPushBackLogic() == -1 || testConcatenationLogic() == -1 || testMapLogic() || testSortLogic()) {
        return -1;
    }
    printf("\nAll tests compeleted successfully!\n\n");
    printf("\n-~~~~==Hello!==~~~~-\n");

    ArrayCollection collection = {NULL, 0};

    while (1) {

        // Стартовое меню
        char input[20];
        printMenu();
        scanf("%19s", input);

        // Стоп-слово (выход из меню)
        if (strcmp(input, "STOP") == 0) {
            break;
        }

        int action = atoi(input);

        switch (action) {
            case 0: // Show arrays
            {
                printf("\nAll arrays: ");
                for (size_t i = 0; i < collection.size; ++i) {
                    printf("%s ", collection.arrays[i].name);
                }
                break;
            }
            case 1: // Create new int array
            {
                char name[20];
                printf("\nEnter int array name: ");
                scanf("%19s", name);
                arrayAddToCollection(&collection, name, sizeof(int), numberPrint);
                break;
            }
            case 2: // Create new float array
            {
                char name[20];
                printf("\nEnter float array name: ");
                scanf("%19s", name);
                arrayAddToCollection(&collection, name, sizeof(float), floatPrint);
                break;
            }
            case 3: // Add element to int array
            {
                char name[20];
                printf("\nEnter int array name: ");
                scanf("%19s", name);
                Array *array = arrayFindInCollection(&collection, name);
                if (array) {
                    int value;
                    printf("\nEnter integer to add to int array: ");
                    scanf("%d", &value);
                    if ((value / 1) == value) {
                        arrayPushBack(array, &value);
                    } else {
                        printf("\nYou did not entered the integer!\n");
                    }
                } else {
                    printf("\nArray is not found.");
                }
                break;
            }
            case 4: // Add element to float array
            {
                char name[20];
                printf("\nEnter float array name: ");
                scanf("%19s", name);
                Array *array = arrayFindInCollection(&collection, name);
                if (array) {
                    float value;
                    printf("\nEnter float to add to float array: ");
                    scanf("%f", &value);
                    arrayPushBack(array, &value);
                } else {
                    printf("\nArray is not found.\n");
                }
                break;
            }
            case 5:  // Show array by name
            {
                char name[20];
                printf("\nEnter array name for show: ");
                scanf("%19s", name);
                Array *array = arrayFindInCollection(&collection, name);
                if (array) {
                    arrayPrintElements(array);
                } else {
                    printf("\nArray is not found.\n");
                }
                break;
            }
            case 6: // Concatenate arrays
            {
                char name1[20];
                char name2[20];
                char res[20];
                printf("\nEnter first array name to concatenate: ");
                scanf("%19s", name1);
                printf("\nEnter second array name to concatenate: ");
                scanf("%19s", name2);
                Array *firstarr = arrayFindInCollection(&collection, name1);
                Array *secondarr = arrayFindInCollection(&collection, name2);

                if (firstarr && secondarr) {
                    printf("\nEnter the name of concatenated array: ");
                    scanf("%19s", res);

                    arrayAddToCollection(&collection, res, sizeof(int), numberPrint);
                    Array *resultarr = arrayFindInCollection(&collection, res);

                    arrayConcatenation(resultarr, firstarr, secondarr);
                } else {
                    printf("\nArrays are not found.\n");
                }
                break;
            }
            case 7: // Map
            {
                char name[20];
                printf("\nEnter array name: ");
                scanf("%19s", name);
                Array *mapArray = arrayFindInCollection(&collection, name);
                if (mapArray) {
                    arrayMap(funcMap, mapArray);
                } else {
                    printf("\nArray is not found.\n");
                }
                break;
            }
            case 8: { // Where
                char name[20];
                char result[20];
                printf("\nEnter array name: ");
                scanf("%19s", name);
                Array *arrWhere = arrayFindInCollection(&collection, name);

                if (arrWhere) {
                    printf("\nEnter the name of the array-result: ");
                    scanf("%19s", result);
                    Array *WhereRes = arrayFindInCollection(&collection, result);
                    if (WhereRes) {
                        arrayWhere(funcWhere, arrWhere, WhereRes);
                    } else {
                        printf("\nArray is not found.\n");
                    }
                } else {
                    printf("\nArray is not found.\n");
                }
                break;
            }
            case 9: // Sort
            {
                char name[20];
                printf("\nEnter array name: ");
                scanf("%19s", name);
                Array *arrSort = arrayFindInCollection(&collection, name);

                if (arrSort) {
                    arraySort(arrSort, numberSort);
                } else {
                    printf("\nArray not found.\n");
                }
                break;
            }
            default:
                printf("\nUnknown command, try again.\n");
                break;
        }
    }


    // Освобождение ресурсов
    for (size_t i = 0; i < collection.size; ++i) {
        arrayFree(&collection.arrays[i]);
    }
    free(collection.arrays);

    return 0;
}