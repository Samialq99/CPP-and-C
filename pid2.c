#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

 int main () 
{
	char* args1[]={"/bin/ps", "-l",NULL};
	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		printf("This is the Parent process\n");
		sleep(30);
		
	}
	else if (pid==0)
	{
		printf(" This is the child Process\n");
		exit(0);
	}
	
	//execv(args1[0],args1);	
	//execl("ls", NULL);
	//execlp("/bin/ps", "-l");

	//Fire up a terminal and type the following command
	// – ps aux | grep Z You will now get details of all zombie processes in the processes table.
	//kill -s SIGCHLD pid ​Replace the pid with the id of the parent process
	// so that the parent process will remove all the child
	//ps aux | grep defunct     this finds all defuncts or zombies 
	//
	//system("ps aux | grep defunct");
	//int pid2 =fork();
	//if(pid2==0) {
	//execlp("ps","ps","-o","ppid,cmd,cpu,state", NULL);

	//execv(args1[0],args1);
	//wait();
	//printf("\n");
	//system("ps aux | grep defunct");

	
	//system("kill -9 $(ps -l|grep -w Z|tr -s' '|cut -d '' -f 5)");
	//system("kill -9 $(ps -A -ostat,ppid | awk '/[zZ]/ && !a[$2]++ {print $2}')");
	//wait(5);
	//system("ps -l");
system("ps -l");
system("kill -9 $(ps -A -ostat,ppid | awk '/[zZ]/ && !a[$2]++ {print $2}')");
	//execv(args1[0],args1);
printf("Hello im alive\n");
	return 0;
	
}
