#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define BINARY_PATH     "/bin/ls"

int main() {
    char *args[] = {BINARY_PATH, "-l", NULL};
    char *envp[] = {NULL};
    printf("[%d] Parent, forking\n", getpid());

    switch(fork()) {
        case -1:
            printf("fork error!\n");
            return -1;

        case 0:
            printf("[%d] child, calling execve()\n", getpid());
            execve(BINARY_PATH, args, envp);
            printf("execve error!\n");
            break;
        
        default:
            break;
    }

    return 0;
}