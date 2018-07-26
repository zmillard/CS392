#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
void main(){
	int fd, fd2, num = 0;
	char *buffer = (char *) malloc(3);
	int sizetoread = 3;
	int sizetowrite = 3;
	int count = 0;
	int key = 5;
	int i;
	int rc;
	
	fd=open("encrypted.txt", S_IRWXU); 
	fd2 =open("solutions.txt", S_IRWXU);
	num = read(fd, buffer, sizetoread); //sizetoread is num of bytes 2 read
	printf("hello");
	while(num != 0){
		for(i = 0; i < num; i++){
			int temp = count / 3;
			if((buffer[i] - (key + (temp * 2))) > 65 && (buffer[i] - (key + (temp * 2))) < 90){
				
				buffer[i] = buffer[i] - (key + (temp * 2));
			}
			if((buffer[i] - (key + (temp * 2))) > 97 && (buffer[i] - (key + (temp * 2))) < 122){
				buffer[i] = buffer[i] - (key + (temp * 2));
			}
			if((buffer[i] - (key + (temp * 2)) < 65)){
				buffer[i] = buffer[i] + 60 - (key + (temp * 2));
			}
			if((buffer[i] - (key + (temp * 2))) > 90 && (buffer[i] - (key + (temp * 2))) < 97){
				buffer[i] = buffer[i] - (key + (temp * 2) + 6);
			}
			count++;
			printf("%c", buffer[i]);
		}
			num = write(fd2, buffer, num);
		num = read(fd, buffer, sizetoread);
	}
	rc=close(fd);
}