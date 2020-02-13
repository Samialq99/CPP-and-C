#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// you need a function for the thread to handle
void *entry_point(void *value) {
    printf("Helllo from the 2nd thread \n");

    int *num =(int*) value;
    printf("the value of value is %d", *num);
    return NULL;

}


int main(int argc, char **argv) {

    pthread_t thread; // first you must create a thread

    printf("Hello from the 1st thread \n");
    int num =123;

    pthread_create(&thread,NULL,entry_point,&num); //takes 4 arguments

    pthread_join(thread,NULL);  //pthread join is like wait, it makes main waits for a thread to finish

return EXIT_SUCCESS;

}


// to run this code compile like this
//gcc -o prog basicthread.c -lpthread
// notice we include -lpthread library of threads. 