#include <stdio.h>

int main() {
    int array[4];  // declare an array with 4 elements of type int
    array[0] = 42; // set the elements' content
    array[1] = 43;
    array[2] = 44;
    array[3] = 45;
    printf("%d\n", array[2]); // print the 3rd element of the array

    int arr2d[2][2];  // declare a 2-dimensional 2x2 array of ints
    arr2d[0][0] = 12; // set the elements' content
    arr2d[0][1] = 13;
    arr2d[1][0] = 14;
    arr2d[1][1] = 15;
    
    char str[3];   // in C, strings are array of characters...
    str[0] = 'h';
    str[1] = 'i';
    str[2] = '\0'; // ... that end with the `\0` termination character
}