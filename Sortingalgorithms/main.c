//
// Created by Miroslav Novotný on 14.11.2024.
//

#include <stdio.h>

void bubleSort (int * arr, int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

}

void printArray (int * arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d" , arr[i]);
    }
    printf("\n");
}

int main () {

    int array[15] = {5,8,1,8,5,4,5,4,1,5,7,1,5,1,5};
    int size = 15;

    printArray(array, size);

    bubleSort(array, size);

    printArray(array, size);

    return 0;
}
