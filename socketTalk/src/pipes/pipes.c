#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include "my.h"

int main(int argc, char* argv[]){
	int maxBufferSize = 150;
	pid_t pid;
	int p[2];
	int p2[2];
	if(pipe(p)<0){
		perror("Failed on creating pipe"), exit(1);
	}
	if(pipe(p2)<0){
		perror("Failed on creating pipe"), exit(1);
	}
	if(argc == 1){
		perror("Need inpit"), exit(0);
	}
	if((pid=fork())<0){
		perror("error creating fork"), exit(1);
	}else if(pid == 0){
		if((pid=fork())<0){
			perror("error creating fork"), exit(1);
		}else if(pid == 0){
			/*child*/
			/*my_str("Child:");*/
			char buffer[maxBufferSize];
			int numbytes;
			close(p[1]);
			if((numbytes = read(p[0], buffer, maxBufferSize))<0){
				perror("Error reading from pipe"), exit(1);
			}
			my_str("Child: ");
			my_str(buffer);
			my_str("\n");
			close(p[0]);
			exit(5);
		}else{
			/*adult*/
			int status;
			int numbytes;
			char buffer[maxBufferSize];
			/*argv++;*/
			/*char* str = my_vect2str(argv);*/
			/*printf("Parent: %s\n", str);*/
			close(p[0]);
			close(p2[1]);
			my_str("hi");
			if((numbytes = read(p2[0], buffer, maxBufferSize))<0){
				perror("Error reading from pipe"), exit(1);
			}
			my_str("Parent: ");
			my_str(buffer);
			my_str("\n");
			if(write(p[1], buffer, strlen(buffer)<0)){
				perror("Error writing on pipe"), exit(1);
			}
			close(p[1]);
			close(p2[1]);
			wait(&status);
			
			/*printf("hello from parent. Childe exited with code %i\n", WEXITSTATUS(status));*/ /*child prints before parent*/
		}
		return 0;
	}else{
		/*adult*/
		int status; /*from c*/
		/*argv++;*/
		char* str = my_vect2str(argv + 1);
		close(p2[0]);
		my_str("Grandparent: ");
		my_str(str);
		my_str("\n");
		if(write(p2[1], str, strlen(str+1)<0)){
			perror("Error writing on pipe"), exit(1);
		}else{
			my_str("yay");
		}
		
		
		wait(&status);
		close(p2[1]);
		
		/*printf("hello from parent. Childe exited with code %i\n", WEXITSTATUS(status));*/ /*child prints before parent*/
	}
	return 0;
}

/*grandparents, parents and children.
 fork in child to create grandparents*/