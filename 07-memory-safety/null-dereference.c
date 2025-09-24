#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    // forgot to call malloc ...
    *ptr = 42; // dereference NULL (address 0)
    free(ptr); // another problem: tries to free a NULL pointer
}