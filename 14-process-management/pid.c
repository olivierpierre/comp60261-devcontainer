#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("my pid is: %d\n", getpid());
    return 0;
}