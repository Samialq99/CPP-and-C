
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>
#include <omp.h>





int circle_count = 0; 


double random_double()
{
    return (random() / ((double)RAND_MAX + 1)); 

}

int main(int argc, const char *argv[])
{
    
	int num_points = 0;    
 
    printf("Input the number of points: ");
    scanf("%d", &num_points);
    printf("OpenMP separate thread simulation for num points %d\n", num_points);
    num_of_point_calc(num_points);
    
    

    return 0;
}


int  num_of_point_calc(int NUM_OF_POINTS)
{
    
  
    double PI;
    srandom((unsigned)time(NULL));
    clock_t begin = clock();
    #pragma omp parallel
    {
         int hit_count = 0;
        double x,y;
       
        for(int i = 0; i < NUM_OF_POINTS; i++)
        {
           
            
            x = random_double() * 2.0 - 1.0;
            y = random_double() * 2.0 - 1.0;
            float z=0;
        z=sqrt(x*x + y*y);
        if(z< 1.0)
        {
            ++hit_count;
        }
            
        }
        
        circle_count += hit_count;
        
        
    }
    
    
    PI = (4.0 * circle_count )/(NUM_OF_POINTS * omp_get_num_procs());
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("The Number of Points = %d\n", NUM_OF_POINTS);
    printf("Value of PI = %f\n", PI);
    printf("run time = %f\n", time_spent/256 );

}

