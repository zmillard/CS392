#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int status = 1;
int state;
pid_t pid;
void recieve(int sig){
	printf("%s\n", "signal recieved");
}
void exitC(int sig){
	printf("%s\n", "Child exiting...");
	exit(0);
}
void childZ(int sig){
	status = 1;
	kill(pid, SIGUSR1);
}
void childC(int sig){
	if(status == 0){
		printf("Gooodbye!\n");
		exit(0);
	}else{
		kill(pid, SIGUSR2);
		status = 0;
	}
}
void alarmo(int sig){
	exitC(pid);
	exit(0);
}
void nothing(int sig){}
int main(){
	if((pid = fork()) < 0){	//error, inspect errorno
	} else if (pid==0){//child creates a new child
		signal(SIGUSR1, recieve);
		signal(SIGUSR2, exitC);
		signal(SIGTSTP, nothing);
		signal(SIGINT, nothing);
		while(1){
			pause();
		}
	} else { //parent
		signal(SIGTSTP, childZ);
		signal(SIGINT, childC);
		signal(SIGALRM, alarmo);
		
		while(1){
			alarm(10);
			pause();
		}
	}
	return 0;
}