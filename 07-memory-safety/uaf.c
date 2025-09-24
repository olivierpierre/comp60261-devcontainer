#include <stdio.h>
#include <stdlib.h>

int main() {
    int *buffer = malloc(1 * sizeof(int));

    // do something with buffer here ...
    
    // after that free, buffer points to unallocated memory:
    // it's a dangling pointer (invalid reference)
    free(buffer);

    *buffer = 42; // use after free
    printf("buffer points to: %d\n", *buffer);
}