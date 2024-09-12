#include <stdio.h>

float add(float a, float b) {
    return a + b;
}

float subtract(float a, float b) {
    return a - b;
}

float multiply(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}
float calculate(float a, float b, char op) {
    switch (op) {
        case '+':
            return add(a, b);
        case '-':
            return subtract(a, b);
        case '*':
            return multiply(a, b);
        case '/':
            return divide(a, b);
        default:
            fprintf(stderr, "Error: Invalid operator\n");
            return 1;
    }
}

int main(void) {


    float a, b;
    char op;
    printf("calculate (a op b): ");
    scanf("%f %c %f", &a, &op , &b);
    if (b == 0 && op == '/') {
        fprintf(stderr, "Error: Division by zero\n");
        return 1;
    }
    printf("%f %c %f = %f\n", a, op, b, calculate(a, b, op));
    return 0;
}