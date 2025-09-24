#include <stdio.h>

int main() {
    int so_short = sizeof(short int);
    int so_int = sizeof(int);
    int so_uint = sizeof(unsigned int);
    int so_long = sizeof(long int);
    int so_longlong = sizeof(long long int);
    int so_float = sizeof(float);
    int so_double = sizeof(double);                           
                                                              // storage sizes on x86-64:
    printf("size of short:         %d bytes\n", so_short);    // 2 bytes
    printf("size of int:           %d bytes\n", so_int);      // 4 bytes
    printf("size of unsigned int:  %d bytes\n", so_uint);     // 4 bytes
    printf("size of long int:      %d bytes\n", so_long);     // 8 bytes
    printf("size of long long int: %d bytes\n", so_longlong); // 8 bytes
    printf("size of float:         %d bytes\n", so_float);    // 4 bytes
    printf("size of double:        %d bytes\n", so_double);   // 8 bytes
}