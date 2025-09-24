#include <stdio.h>

void negate_int_array(int *ptr, int size) { // function taking pointer as parameter
    for(int i=0; i<size; i++)               // also need the size to iterate properly
        ptr[i] = -ptr[i];      // use square brackets like a standard array
                               // equivalent to *(ptr+i) = -(*(ptr+i))
}

int main(int argc, char **argv) {
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    negate_int_array(array, 7); // to get the pointer just use the array's name
    for(int i=0; i<7; i++)
        printf("array[%d] = %d\n", i, array[i]);
    return 0;
}