#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h
#include <my.h>

int main(int argc, char* argv[]){
	int maxBufferSize = 150;
	pid_t pid;
	int p[2];
	if(pipe(p)<0){
		perror("Failed on creating pipe"), exit(1);
	}
	if((pid=fork())<0){
		perror("error creating fork"), exit(1);
	}else if(pid == 0){
		/*child*/
		printf("hello from child\n");
		char buffer[maxBufferSize];
		int numbytes;
		close(p[1]);
		if((numbytes = read(p[0], buffer, maxBufferSize))<0){
			perror("Error reading from pipe"). exit(1);
		}
		printf("Child: %s\n", buffer);
		close(p[0]);
		exit(5);
	}else{
		/*adult*/
		int status;
		char* str=agrv[1];
		printf("parent: %s\n", str);
		close(p[0]);
		if(write(p[1], str, strlen(str+1)<0)){
			perror("Error writing on pipe"), exit(1);
		}
		close(p[1]);
		wait(&status);
		printf("hello from parent. Childe exited with code %i\n", WEXITSTATUS(status)); /*child prints before parent*/
	}
	return 0;
}

/*grandparents, parents and children.
 fork in child to create grandparents*/