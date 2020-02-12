#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


// after you compile you will get numbers higher than 100000 which 
//shouldnt happen, but its because threads are all accessing var i
//simultanously
// use commands 
// gcc -o prog1 MutexwithRaceproblem.c -lpthread -lm
//./prog1 
//run it again to get max numbers with ./prog1 | wc -l
// you will get numbers higher than 100000 why ????
// compare this to the ThreadMutex.c program which is fixed.

#define COUNT_TO  100000
#define MAX_CORES 12  



static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long long i = 0;

void *start_counting(void *arg) {
    for (;;) {
        // acquire lock
       // pthread_mutex_lock(&mutex);

        // check if all COUNT_TO has been arrived at
        if (i >= COUNT_TO) {
            //pthread_mutex_unlock(&mutex);
            return NULL;
        }

        ++i;

        // release lock
        //pthread_mutex_unlock(&mutex);

        printf("i = %lld\n", i);
          }
}

int main(void) {
    int i = 0;

    // create a thread group the size of MAX_CORES
    pthread_t *thread_group = malloc(sizeof(pthread_t) * MAX_CORES);

    // start all threads to begin work
    for (i = 0; i < MAX_CORES; ++i) {
        pthread_create(&thread_group[i], NULL, start_counting, NULL);
    }

    // wait for all threads to finish
    for (i = 0; i < MAX_CORES; ++i) {
        pthread_join(thread_group[i], NULL);
    }

    return EXIT_SUCCESS;
}