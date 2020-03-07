/*
Name: Sami Alquraishi 
Name:Anurag Sake 
Assignment 4 Part 1
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Assume  that  a  system  has  a 32-bit  virtual  addresswith  a 4-KB  page  size. 
Write  a  C program  that  is  passed  a  virtual  address(in  decimal)
on  the  command  line  and  have  it output  the  page  number
and  offset  for  the  given  address.
*/


int main (int argc, char *argv[])
{
    unsigned long pNumber;
    unsigned long offset;
    unsigned long address;

/*
We declare the variable address unsigned long long int
to be able to store 4 bytes and initialize it to first argument in the command line argv1.
we assign the variable page type unsigned long long int to the variable address.
we assign the variable offset type unsigned long long int to the variable address */

    
    
    if(argc != 2)
    {
        printf(" execute prog followed by virtual address on one line\n");
        return -1;
    }
    
    address = atoll(argv[1]);
    
    pNumber = address >> 12; 
    offset = address & 0xfff;
    
    
    printf("The address %lu contains: \n", address);
    printf("Page Number = %lu\n", pNumber);
    printf("offset = %lu\n", offset);
    
    
    return 0;
}