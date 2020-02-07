#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

 int main () {
system("./prog &");
system("ps -l");
sleep(3);
system("kill -9 $(ps -l|grep -w Z|tr -s ' '|cut -d ' ' -f 5)");
sleep(2);
printf("\n\nNew List Zombies removed\n\n");
system("ps -l");
return(0);
}
