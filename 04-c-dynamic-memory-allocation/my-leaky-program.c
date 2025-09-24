#include <stdio.h>
#include <stdlib.h>

void process_array(int size) {
    int *arr = (int *)malloc(size * sizeof(int));

    if(!arr) {
        printf("ERROR: cannot allocate memory\n");
        exit(-1);
    }

    for (int i = 0; i < size; i++){
        arr[i] = i * i;
        printf("%d\n", arr[i]);
    }

    // oops, no free!
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n > 0) process_array(n);

    printf("all good\n");
    return 0;
}