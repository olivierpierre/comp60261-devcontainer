#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGUSR1
void handle_sigusr1(int signum) {
    printf("[%d] signal received!\n", getpid());
    fflush(stdout); // Ensure immediate output
}

int main() {
    // Install custom handler for SIGUSR1
    struct sigaction sa;
    sa.sa_handler = handle_sigusr1;
    sigemptyset(&sa.sa_mask);   // No additional signals blocked in handler
    sa.sa_flags = SA_RESTART;   // Restart interrupted syscalls automatically

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("[%d] Doing useful work\n", getpid());
        sleep(1);  // Simulate work
    }

    return 0;
}