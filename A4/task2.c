/*
Name: Sami Alquraishi 
Name:Anurag Sake 
Assignment 4 Part 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

 
/*to  generate nrandom  virtual  addresses  between  0  and  232-1
  and compute  the  page  number  and  offset  for  each  address 
  –do  not  output  anything onthe console.
  Run your program withn= 1,000,000 random addresses  and compute the total CPU time
*/


double random_double()
{
    
    return random() / ((double)RAND_MAX + 1);
}

int main(int argc, char *argv[])
{
    unsigned long pageNumber, offset, address;
    
    srandom((unsigned)time(NULL));
    clock_t begin = clock();
    
    /*
We define SIZE = 1000000 for virtual address 0 and 2 32-1
We also use the >> operator to offset like in the previous part1,
We print the cpu clock time to the screen as well.
    */
    
    for(address = 0; address < 1000000; address++)
    {
        
        address = random_double() * 1000000;
        pageNumber = (address & 0xFFFFF000) >> 12; 
        offset = address & 0x00000FFF;
        
    }
    
    clock_t end = clock();
    
    
    double time_taken;
    time_taken= (double) (end-begin) /CLOCKS_PER_SEC;
    printf("total CPU time(run again if you get zeros): %f\n", time_taken);
    
    
    return 0;
}