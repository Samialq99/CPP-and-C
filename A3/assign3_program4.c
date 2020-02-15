


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <omp.h>
#define NUM_OF_POINTS 1000000




int circle_count = 0; 


double random_double()
{
    return (random() / ((double)RAND_MAX + 1)); 

}

int main(int argc, const char *argv[])
{

	int slave_value = 0;
	
	printf("Input number of slaves: ");
	scanf("%d", &slave_value);
	printf("OpenMP race condition simulation with slave = %d\n", slave_value);
	diff_num_of_slaves(slave_value);




return 0; 
}  


int diff_num_of_slaves(int NUM_OF_SLAVES)
{
    int i;
    
    double PI;

    
    
    srandom((unsigned)time(NULL));
    clock_t begin = clock();
   
#pragma omp parallel 
    {
        int hit_count = 0, i;
        double x,y;
        


            for(i = 0; i < NUM_OF_POINTS; i++)
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

#pragma omp critical
        {
            circle_count += hit_count;
        }
    
    }
  
    
    PI = (4.0 * circle_count / (NUM_OF_POINTS * omp_get_num_procs()));
    clock_t end = clock();
    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
    printf("The Number of Points = %d\n", NUM_OF_POINTS);
    printf("The Number of Slaves = %d\n", NUM_OF_SLAVES);
    printf("Value of PI = %f\n", PI);
    printf("run time= %f\n", time_spent /(1024 * NUM_OF_SLAVES));
    

   
}

