#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define FIFO_PATH "/tmp/myfifo"

int main() {
    // Create a named pipe (FIFO)
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
        // It's fine if it already exists
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // --- Child Process: Writer ---
        int fd = open(FIFO_PATH, O_WRONLY);
        if (fd == -1) { perror("open (child)"); exit(EXIT_FAILURE); }

        const char *msg = "Hello from child!\n";
        write(fd, msg, strlen(msg));
        close(fd);
        exit(0);
    } else {
        // --- Parent Process: Reader ---
        int fd = open(FIFO_PATH, O_RDONLY);
        if (fd == -1) { perror("open (parent)"); exit(EXIT_FAILURE); }

        char buffer[128];
        int n = read(fd, buffer, sizeof(buffer)-1);
        if (n > 0) {
            buffer[n] = '\0';  // Null-terminate
            printf("Parent received: %s", buffer);
        }
        close(fd);
        unlink(FIFO_PATH);  // Clean up FIFO file
    }

    return 0;
}