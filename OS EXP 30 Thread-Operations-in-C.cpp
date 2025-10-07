#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Thread function
void* thread_function(void* arg) {
    int id = *((int*)arg);
    printf("Thread %d is running...\n", id);

    // Demonstrate pthread_exit
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;
    int ret;

    // (i) CREATE threads
    printf("Creating threads...\n");
    ret = pthread_create(&t1, NULL, thread_function, &id1);
    if (ret) {
        printf("Error creating thread 1\n");
        exit(1);
    }

    ret = pthread_create(&t2, NULL, thread_function, &id2);
    if (ret) {
        printf("Error creating thread 2\n");
        exit(1);
    }

    // (iii) EQUAL — check if two thread IDs are the same
    if (pthread_equal(t1, t2))
        printf("Threads are equal (same thread ID)\n");
    else
        printf("Threads are not equal (different thread IDs)\n");

    // (ii) JOIN threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads have finished execution.\n");

    // (iv) EXIT the main thread
    pthread_exit(NULL);

    return 0;
}

