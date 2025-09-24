#include <stdio.h>

// we want this function to "return" 3 things: the product and quotient of n1 by n2,
// as well as an error code in case the division is impossible
int multiply_and_divide(int n1, int n2, int *product, int *quotient) {
    if(n2 == 0) return -1;      // Can't divide if n2 is 0
    *product = n1 * n2;
    *quotient = n1 / n2;
    return 0;
}

int main(int argc, char **argv) {
    int p, q, a = 5, b = 10;
    if(multiply_and_divide(a, b, &p, &q) == 0) {
        printf("10*5 = %d\n", p); printf("10/5 = %d\n", q);
    }
}