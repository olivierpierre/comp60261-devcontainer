#include <stdio.h>

int main() {
    int choice = 1;

    switch(choice) {
    case 1:
        printf("choice is 1\n");
        break;
    case 2:
        printf("choice is 2\n");
        break;
    default:
        printf("choice is neither 1 nor 2\n");
    }

    return 0;
}