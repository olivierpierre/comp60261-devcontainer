#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    int *ptr = malloc(sizeof(int));

    // what ends up in y and z? we do not know!
    int y = x;
    int z = *ptr;

    printf("z: %d\n", z);
}