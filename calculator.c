#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculator_func(int a, int b, char op) {
    int result;

    switch (op) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b != 0) {
                result = a / b;
            } else {
                printf("Error: Division by zero is not allowed.\n");
                return 0;
            }
            break;
        default:
            printf("Invalid operator '%c'. Supported operators are +, -, *, /.\n", op);
            return 0;
    }

    printf("Result = %d\n", result);
    return result;
}

void input_scanner() {
    char input[100];
    int a, b;
    char op;

    printf("Enter an expression (e.g., 5 + 3): ");
    fgets(input, 100, stdin);

    if (sscanf(input, "%d %c %d", &a, &op, &b) == 3) {
        calculator_func(a, b, op);
    } else {
        printf("Invalid input. Please enter an expression in the format: <number> <operator> <number>\n");
    }
}

int main() {
    input_scanner();
    return 0;
}
