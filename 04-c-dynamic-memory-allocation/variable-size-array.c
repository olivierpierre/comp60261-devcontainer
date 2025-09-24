#include <stdio.h>

void process_array(int size) {
    int arr[size];  // variable-size array, not a great solution
    for (int i = 0; i < size; i++){
        arr[i] = i * i;
        printf("%d\n", arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n > 0) process_array(n);

    printf("all good\n");
    return 0;
}