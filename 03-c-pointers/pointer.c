#include <stdio.h>

int main() {
    int x = 42;
    int *ptr = &x;        // ptr is a pointer of int and _points to_ x
    printf("%d\n", *ptr); // dereference ptr, print the value of x
}