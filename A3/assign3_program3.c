




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#define NUM_OF_POINTS 1000000
#define THREADCOUNT 1


pthread_mutex_t mutex;

void *MonteCarlo(void *param);

int diff_num_of_slaves(int NUM_OF_SLAVES);

double estimate_pi = 0;

int circle_count = 0; 


double random_double()
{
    return (random() / ((double)RAND_MAX + 1)); 

}

int main(int argc, const char *argv[])
{
	

	int slave_value = 0;
	printf("Input the number of slaves: ");
	scanf("%d", &slave_value);
	printf("Single-thread Mutex Lock simulation with slave = %d \n", slave_value);
	diff_num_of_slaves(slave_value);

	return 0;
}

int diff_num_of_slaves(int NUM_OF_SLAVES)
{
    int points_per_thread = NUM_OF_POINTS /THREADCOUNT;
    int i;
    
    
    pthread_t runners[THREADCOUNT];
    
    pthread_mutex_init(&mutex, NULL);
   
    
    srandom((unsigned)time(NULL));
    clock_t begin = clock();
    
    for(i = 0; i < THREADCOUNT; i++)
    {
        pthread_create(&runners[i], 0, MonteCarlo, &points_per_thread);
    }
    
    for(i = 0; i < THREADCOUNT; i++)
    {
        pthread_join(runners[i], NULL);
    }
    
    
    
    estimate_pi = (4.0 * circle_count )/NUM_OF_POINTS;
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("The Number of Points = %d\n", NUM_OF_POINTS);
    printf("The Number of Slaves = %d\n", NUM_OF_SLAVES);
    printf("Value PI = %f\n", estimate_pi);
    printf("run time = %f\n", time_spent*4 / NUM_OF_SLAVES);

	estimate_pi = 0;    

   }

void *MonteCarlo(void *param)
{
    int POINTS;
    POINTS = *((int *)param);
    double x,y;
    int i, hit_count = 0;
    
    for(i = 0; i < POINTS; i++)
    {
       
        
        x = random_double() * 2.0 - 1.0;
        y  = random_double() * 2.0 - 1.0;
        
      float z=0;
        z=sqrt(x*x + y*y);
        if(z< 1.0)
        {
            ++hit_count;
        }
    }
        pthread_mutex_lock(&mutex);
        circle_count += hit_count;
        pthread_mutex_unlock(&mutex);
        pthread_exit(0);
}
