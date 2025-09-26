#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

typedef struct {
    pthread_mutex_t lock;
    int field1;
    int field2;
    int counter;
} shared_data_t;

void* thread_func(void* arg) {
    shared_data_t *shared = (shared_data_t*)arg;

    for (int i = 0; i < 5; i++) {
        if (pthread_mutex_lock(&shared->lock) != 0) {
            perror("pthread_mutex_lock");
            pthread_exit(NULL);
        }

        int old = shared->counter;
        shared->field1 = rand();
        shared->field2 = rand();
        shared->counter++;
        printf("[%d] counter %d -> %d\n", gettid(), old, shared->counter);

        if (pthread_mutex_unlock(&shared->lock) != 0) {
            perror("pthread_mutex_unlock");
            pthread_exit(NULL);
        }

        usleep(100000); // small delay for readability
    }

    pthread_exit(NULL);
}

int main() {
    shared_data_t shared;

    // Initialize mutex (thread-shared, default attributes)
    if (pthread_mutex_init(&shared.lock, NULL) != 0) {
        perror("pthread_mutex_init");
        return -1;
    }

    shared.counter = 0;

    pthread_t t1, t2;

    // Create two threads
    if (pthread_create(&t1, NULL, thread_func, &shared) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&t2, NULL, thread_func, &shared) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Cleanup
    pthread_mutex_destroy(&shared.lock);

    return 0;
}
