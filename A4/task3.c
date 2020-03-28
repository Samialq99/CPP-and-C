/*
Name: Sami Alquraishi 
Name:Anurag Sake 
Assignment 4 Part 3
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
Change your program, Program-1, such that it takes as input an address-space (eg, v= 32-bit),
a  page-size (eg, s= 4KB),and  an  address (eg, a= 19986),
and  returns  the  page number and the offset number of the
 input address (eg, p= 4 and d=3602). Both vand sshould be powers of 2, s< v,
 and v= 16 or 32 or 64, andsbetween 512 bytes and 1GBinclusively.
*/

int main(int argc, char *argv[])	
{
int page_no, offset; 
unsigned int address=0;
unsigned int addSpace=0;
unsigned int pageSize=0;
unsigned int offsetbit=0;

 
if(argc != 4)
{
printf("%s Place the arguments separated by space starting with address-space,page-szie,address\n");
return -1;
}

 
addSpace = (unsigned int)atoi(argv[1]);
pageSize = (unsigned int)atoi(argv[2]);
address = (unsigned int)atoi(argv[3]);


 
if ( addSpace <= 0 || pageSize <= 0 || address <= 0)
{
printf("Invalid first arguments\n");
return -1;
}

 
if ( !((addSpace != 0) && ((addSpace & (addSpace- 1)) == 0)) )
{
printf("second arg must be a power of two.\n");
return -1;
}

if ( !((pageSize != 0) && ((pageSize & (pageSize- 1)) == 0)) )
{
printf("third arg is Not a power of two.\n");
return -1;
}
 pageSize = pageSize * 1024;

 int track=1, counter=0;
while (track != pageSize)
{
    track=2*track;
    counter++;
}

printf("The address %d contains:\n", address);

 
for (int i=0; i<counter; i++)
{
int init = 1;
init = init << i;
offsetbit = offsetbit | init;
}

 page_no = address >> counter;
 offset = address & offsetbit;
     
printf("Page Number = %d\n", page_no);
printf("Offset = %d\n", offset);

return 0;

}


