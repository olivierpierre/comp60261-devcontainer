#include <stdio.h>

int main() {
    int i;

    for (i = 0; i < 5; i++) {
        printf("For loop iteration %d\n", i);
    }

    i = 0;
    while (i < 5) {
        printf("While loop iteration %d\n", i);
        i++;
    }

    return 0;
}