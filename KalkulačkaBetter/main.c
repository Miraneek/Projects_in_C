#include <stdio.h>
#include <stdlib.h>

int convert_char_to_int(char *str) {
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

int calculator() {
    char c;
    int size_of_calculation = 0;

    // Allocate initial memory for calculation
    char *calculation = malloc(1 * sizeof(char));

    do {
        scanf("%c", &c);
        char *temp = realloc(calculation, (size_of_calculation + 1) * sizeof(char));
        if (temp == NULL) {
            // Handle memory reallocation failure
            free(calculation);
            printf("Memory allocation failed!\n");
            return -1;
        }
        calculation = temp;
        calculation[size_of_calculation] = c;
        size_of_calculation++;
    } while (c != '=');

    // Arrays for storing numbers and operations
    int *numbers = malloc(sizeof(int));
    int number_of_numbers = 0;
    char *number = malloc(1 * sizeof(char));
    int size_of_number = 0;
    char *operations = malloc(sizeof(char));
    int number_of_operations = 0;

    for (int i = 0; calculation[i] != '='; i++) {
        if (calculation[i] == ' ')
            continue;

        if (calculation[i] != '+' && calculation[i] != '-') {
            number = realloc(number, (size_of_number + 1) * sizeof(char));
            number[size_of_number] = calculation[i];
            size_of_number++;
        }

        if (calculation[i + 1] == '+' || calculation[i + 1] == '-' || calculation[i + 1] == '=') {
            number = realloc(number, (size_of_number + 1) * sizeof(char));
            number[size_of_number] = '\0';  // Null-terminate the string

            numbers = realloc(numbers, (number_of_numbers + 1) * sizeof(int));
            numbers[number_of_numbers] = convert_char_to_int(number);
            number_of_numbers++;

            number = realloc(number, sizeof(char) * 2);
            size_of_number = 0;

            if (calculation[i + 1] != '=') {
                operations = realloc(operations, (number_of_operations + 1) * sizeof(char));
                operations[number_of_operations] = calculation[i + 1];
                number_of_operations++;
                i++;  // Skip the operator
            }
        }
    }

    // Initialize result with the first number
    int result = numbers[0];

    // Perform the operations
    for (int i = 0; i < number_of_operations; i++) {
        switch (operations[i]) {
            case '+':
                result += numbers[i + 1];
                break;
            case '-':
                result -= numbers[i + 1];
                break;
            default:
                fprintf(stderr, "Error: Invalid operator\n");
                break;
        }
    }


    free(operations);
    free(number);
    free(numbers);
    free(calculation);
    return result;
}

int main() {
    printf("Enter calculation (e.g., 20+20=): ");
    int result = calculator();
    printf("Result: %d\n", result);
    return 0;
}
