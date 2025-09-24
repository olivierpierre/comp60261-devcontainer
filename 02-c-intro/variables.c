#include <stdio.h>

int main() {
    int a;                 // declare a of type int (signed integer)
    int b; int c;          // b and c of type int
    int d = 12;            // declare d of type int, and set its value
    int x, y = 10, z = 11; // declare x, y and z, set values for y and z

    a = 12;      // set a's value to 12
    b = 20;      // set b's value to 20
    c = 10 + 10; // set c's value to 20
    a = b;       // a = 20
    d++;         // d = d + 1
    y *= 2;       // y = y * 2;

    printf("a: %d, b: %d, c: %d, x: %d, y: %d, z: %d\n", a, b, c, d, x, y, z);
}