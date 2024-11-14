//
// Created by Miroslav Novotný on 07.11.2024.
//
#include <stdio.h>
#include "sorting.h"

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int numbers[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = 10;

while (true) {
        bogo_sort(numbers, size);
    print_array(numbers, size);
}


    return 0;
}
