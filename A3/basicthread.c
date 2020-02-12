#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

void *entry_point(void *value) {
    printf("Helllo from the 2nd thread \n");

}


int main(int argc, char **argv) {

    pthread_t thread;

    printf("Hello from the 1st thread \n")
    int num =123;

    pthread_create(&thread,NULL,entry_point,&num);

    pthread_join(thread,NULL);

return EXIT_SUCCESS;

}


// to run this code compile like this
//gcc -o prog basicthread.c -lpthread
// notice we include -lpthread library of threads. 