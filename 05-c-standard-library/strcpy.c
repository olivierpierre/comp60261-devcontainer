#include <stdio.h>
#include <string.h>

int main() {
    char *string1 = "hello";
    char *string2 = string1;   // this is not a string copy!
    char string3[10];          // allocated space of 10 bytes, it's called a buffer

    /* not super safe, what happens if string1 > string3? */
    strcpy(string3, string1);

    /* better */
    strncpy(string3, string1, 10);
    
    printf("string1 @%p: %s\n", string1, string1); // string1 @1234: hello
    printf("string2 @%p: %s\n", string2, string2); // string2 @1234: hello
    printf("string3 @%p: %s\n", string3, string3); // string3 @5678: hello
}