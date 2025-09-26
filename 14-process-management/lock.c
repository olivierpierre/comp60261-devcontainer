#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

typedef struct {
    pthread_mutex_t lock;
    int field1;
    int field2;
    int counter;
} shared_data_t;

int main() {
    shared_data_t *shared;

    // Create anonymous shared memory using mmap (no shm_open needed)
    shared = mmap(NULL, sizeof(shared_data_t),
                  PROT_READ | PROT_WRITE,
                  MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (shared == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // Initialize process-shared mutex
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_setpshared(&attr, PTHREAD_PROCESS_SHARED);

    if (pthread_mutex_init(&shared->lock, &attr) != 0) {
        perror("pthread_mutex_init");
        return -1;
    }
    pthread_mutexattr_destroy(&attr);

    shared->counter = 0;

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 5; i++) {
        if (pthread_mutex_lock(&shared->lock) != 0) {
            perror("pthread_mutex_lock");
            exit(EXIT_FAILURE);
        }

        int old = shared->counter;
        shared->field1 = rand();
        shared->field2 = rand();
        shared->counter++;
        printf("[%d] counter %d -> %d\n", getpid(), old, shared->counter);

        if (pthread_mutex_unlock(&shared->lock) != 0) {
            perror("pthread_mutex_unlock");
            exit(EXIT_FAILURE);
        }

        usleep(100000); // small delay for readability
    }

    // Wait for child in parent
    if (pid > 0) {
        wait(NULL);
        pthread_mutex_destroy(&shared->lock);

        printf("[%d] final counter: %d\n", getpid(), shared->counter);
        munmap(shared, sizeof(shared_data_t));
    }

    return 0;
}