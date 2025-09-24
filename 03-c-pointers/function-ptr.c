#include <stdio.h>

void greet_v1(char *name) {
    printf("Good morning, %s!\n", name);
}
void greet_v2(char *name) {
    printf("Good evening, %s!\n", name);
}
int main() {
    // declare a function pointer, function returns void and takes a char * as parameter:
    void (*func_ptr)(char *);  
    char *username = "Pierre";
    func_ptr = greet_v1;  // set func_ptr to point to greet_v1
    func_ptr(username);   // call greet_v1 through the pointer
    func_ptr = greet_v2;  // set func_ptr to point greet_v2
    func_ptr(username);   // call greet_v2 through the pointer
    return 0;
}