#include <stdio.h>


int main(int argc, char *argv[])
{
	int pid;
	
	/*declare a pid. Then, create a fork process and if it is successful, create a child process.
	After the child process completes, execute the parent process*/
	
	/*fork a process*/
	pid=fork();
	
	if(pid < 0) { //error has occurred
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if(pid==0) { //child process
		execlp("ls",NULL);
		//sleep(10);
	}
	else { //parent process
		//parent waits for the child to complete
		wait(NULL);
		sleep(3);
		printf("child complete");
		exit(0);
	}
}