#include "includes/minishell.h"

void modifyByValue(int value) {
    value = 10;
}

void modifyByReference(int *value) {
    *value = 10;
}

int main() {
    int num1 = 5;
    int num2 = 5;

    modifyByValue(num1);
    modifyByReference(&num2);

    printf("num1: %d\n", num1); // Output: num1: 5
    printf("num2: %d\n", num2); // Output: num2: 10

    return 0;
}