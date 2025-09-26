#include <stdio.h>
#include <unistd.h>

int global = 42;

int main() {
    int local = 10;

    printf("[%d] I'm the parent, before I modify them local = %d, global = %d\n", getpid(), local, global);

    switch(fork()) {
        case -1:
            printf("fork error!\n");
            return -1;

        case 0:
            // Child runs
            printf("[%d] I'm the child, before I modify them local = %d, global = %d\n", getpid(), local, global);
            local = 100;
            global = 100;
            printf("[%d] I'm the child, after I modify them local = %d, global = %d\n", getpid(), local, global);
            break;

        default:
            // Parent runs
            local = 0;
            global = 0;
            printf("[%d] I'm the parent, after I modify them local = %d, global = %d\n", getpid(), local, global);
    }
    
    printf("[%d] bye!\n", getpid()); // executed by both
    return 0;
}