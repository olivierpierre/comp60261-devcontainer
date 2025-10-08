#include <stdio.h>

int f(int param) {
    int f_local = 0xcafe;
    /* ... */
    return 0;
}

int main() {
    int main_local = 0x42;
    int ret = f(main_local);
    printf("ret: %d\n", ret);
}