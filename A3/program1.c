

// Names : Sami Alquraishi 102248298 /Anurag Sake 105124351
// compile with this gcc assign3_program4.c -o assignp1 -lpthread -lm -fopenmp

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>


#define THREADCOUNT 2

void *MonteCarlo(void *param);

int num_of_points_calc(int NUM_OF_POINTS);

int circle_count = 0; 

// WE ARE USING THE PROVIDED ALGORITHM IN THE ASSIGNMENT TEXT
double random_double()
{
    return (random() / ((double)RAND_MAX + 1)); 

}

int main(int argc, const char *argv[])
{

	int points = 0;
	printf("Input the number of points: ");
	scanf("%d", &points);
	printf("Multi-threading simulation for point %d\n", points);
	num_of_points_calc(points);
	return 0;

}
    



int num_of_points_calc(int NUM_OF_POINTS)
{
	int points_per_thread = NUM_OF_POINTS /THREADCOUNT;
    int i;
    
    double PI;
    
    pthread_t workers[THREADCOUNT];
    
    // WE SEED SRANDOM FN TO GET A DIFFERENT RANDOM POINT INSTEAD OF THE SAME
    
    srandom((unsigned)time(NULL));
    clock_t begin = clock();
    for(i = 0; i < THREADCOUNT; i++)
    {
        pthread_create(&workers[i], 0, MonteCarlo, &points_per_thread);
    }
    
    for(i = 0; i < THREADCOUNT; i++)
    {
        pthread_join(workers[i], NULL);
    }
    
    // USING THE FORUMLAE PROVIDED 
    
    PI = (4.0 * circle_count )/NUM_OF_POINTS;
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("The Number of Points = %d\n", NUM_OF_POINTS);
    printf("Value of PI = %f\n", PI);
    printf("run time = %f\n", time_spent );
    

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
    
    
    circle_count = circle_count+hit_count;
    
}
