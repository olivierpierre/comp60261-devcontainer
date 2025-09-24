#include <stdio.h>
#include <stdlib.h>

int main() {
    int *buffer = malloc(1 * sizeof(int));

    // do something with buffer here ...

    free(buffer);

    // more code here ...

    free(buffer); // double free
}