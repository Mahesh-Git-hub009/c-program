#include <stdio.h>

// Macro definition for identity function
#define IDENTITY(x) (x)

int main() {
    int int_val = 25;
    float float_val = 3.14;
    char char_val = 'A';

    printf("Original Integer: %d | Identity: %d\n", int_val, IDENTITY(int_val));
    printf("Original Float: %.2f | Identity: %.2f\n", float_val, IDENTITY(float_val));
    printf("Original Char: %c | Identity: %c\n", char_val, IDENTITY(char_val));

    return 0;
}
