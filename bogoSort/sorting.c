//
// Created by Miroslav Novotný on 07.11.2024.
//

#include "sorting.h"

#include <math.h>
#include <stdlib.h>

void bogo_sort(int *arr, int size) {
    int temp[size];

    int i = 0;
    while (i < size) {
        int random_selection = rand() % size;
        if (arr[random_selection] != NAN) {
            temp[i] = arr[random_selection];
            arr[random_selection] = NAN;
            i++;
        }
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != NAN) {
            arr[j] = arr[i];
            j++;
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
}
