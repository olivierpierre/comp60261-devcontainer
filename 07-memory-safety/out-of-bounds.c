#include <stdio.h>

int main() {
    int numbers[3] = {1, 2, 3};
    // In C, no compile-/runtime notification: program misbehaves and prints garbage:
    printf("The fourth number is: %d\n", numbers[3]);
}
