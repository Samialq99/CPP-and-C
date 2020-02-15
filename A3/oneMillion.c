#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

double random_double()
{
return random() / ((double)RAND_MAX + 1);
}

int main(int argc, const char *argv[])
{

    int total=0;
    for(int i=1;i<=1000000;i++){
    total+=i;
    printf("total is %d\n", total);
    }



/* Generates a double precision random number */
/* seed the random number generator */

    float hit_count=0;

    for(int i=1;i<=100000;i++){

    srandom((unsigned)time(NULL));
    /*generate random numbers between -1.0 and +1.0 (exclusive)*/
    /* to obtain a random (x, y) point*/
    x = random_double() * 2.0 - 1.0;
    y = random_double() * 2.0 - 1.0;
    /* is (x, y) point within the circle ? */
    if (sqrt(x*x + y*y) < 1.0 )
    ++hit_count; /* yes, (x, y) point is in circle */
    }

    float intPY=4*(hit_count/100000)

        printf("total is %d\n", intPY);


return 0;
}

