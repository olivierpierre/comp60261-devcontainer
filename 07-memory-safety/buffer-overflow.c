#include <stdio.h>

int main() {
    int array[4] = {0, 1, 2, 3};

    for(int i=0; i<=4; i++)
        array[i] *= 2;          // when i == 4, overflows array

    printf("array[0]: %d\n", array[0]);
}