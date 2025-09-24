#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000000  // 100 million

int main() {
    int *arr = malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) arr[i] = i;

    clock_t start = clock();

    long long sum = 0;
    for (int i = 0; i < N; ++i) {
        // bound check here would be: if (i<N)
        sum += arr[i];
    }

    clock_t end = clock();

    printf("Sum = %lld\n", sum);
    printf("Time = %.3f seconds\n",
      (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
    return 0;
}