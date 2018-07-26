#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <arpa/inet.h>
#include "my.h"
#include "list.h"


struct user{
	char* username;
	int fd;
};
typedef struct user* User;
void error(char* msg){
	my_str(msg);
	exit(1);
}
int main (int argc, char** argv){
	char bufferi[1024];
	int sockfd, clisockfd, portno, n, i, lis, maxFD, j, k, t;
	struct sockaddr_in serv_addr, cli_addr;
	struct user* newUser;
	struct s_node* head;
	User temp_user;
	socklen_t clilen;
	fd_set readfds;
	char *message;
	char *message1;
	clilen = sizeof(struct sockaddr_in);
	head = NULL;

	if (argc < 2){
		error("error: not enough args, provide a port.\n");
	}
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0){
		error("error: could not open the socket.\n");
	}
	/*bzero((char*)&serv_addr, sizeof(serv_addr));*/
	portno = atoi(argv[1]);
	if(portno < 1 || portno > 65535){
		error("error: port number was not valid.\n");
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	if(bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0){
		error("error: socket did not bind.\n");
	}
	lis = listen(sockfd, 5);
	if (lis < 0){
		error("error: was not able to listen.\n");
	}
	my_str("Congrats dude! Your server is now running...\n");
	maxFD = sockfd;
	while(1){
		maxFD = sockfd;
		FD_SET(sockfd, &readfds);
		for(i = 0; i < count_s_nodes(head); i++){
			newUser = elem_at(head, i);
			j = newUser -> fd;
			FD_SET(j, &readfds);
			if(j > maxFD){
				maxFD = j;
			}
		}
		if(select(maxFD+1, &readfds, NULL, NULL, NULL)==-1){/* this is the blocking line. execution will wait here*/
			error("error: did not receive a valid signal.\n");
		}
		if(FD_ISSET(sockfd, &readfds)){
			clisockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
			if(clisockfd < 0){
				error("error: client socket would not open.\n");
			}else {
				temp_user = (User)malloc(sizeof(struct user));
				temp_user -> fd = clisockfd;
				
				bzero(bufferi,1024);/*256 works*/
				n = read(clisockfd, bufferi, 1024);
				if (n < 0) {
					error("error: reading from the client file");
				}else{
					
					temp_user -> username = my_strdup(bufferi);
					add_node(new_node(temp_user), &head);
					message = my_strconcat((temp_user -> username), " has entered the chat!\n");
					my_str(message);
					for(i = 0; i < count_s_nodes(head); i++){
						newUser = (User)malloc(sizeof(struct user));
						newUser = elem_at(head, i);
						j = newUser -> fd;
						k = write (j, message, (my_strlen(message) - 1));
						if(k < 0){
							error("error:  there was an error writing to the file.");
						}
					}
				}
			}
		}
			
		for(i = 0; i < count_s_nodes(head); i++){
			temp_user = (User)malloc(sizeof(struct user));
			temp_user = elem_at(head, i);
			
			k = temp_user -> fd;
			
			if(FD_ISSET(k, &readfds) > 0){ 
				bzero(bufferi,1024);
				n = read(k, bufferi, 1024); 
				if(n <= 0){
					error("error: server was disconnected..");
				}else{
					message = my_strdup(bufferi);
				}
				if(my_strcmp(my_strdup(bufferi), "/exit") == 0){
					if((write(k, "/close", 6)) < 0){
						error("error: there was an issue writing this");
					}
					message = my_strconcat((temp_user -> username), " has left conversation. \n");
					my_str(message);
					remove_node_at(&head, k);
					message = "";
				}else if(my_strncmp(message, "/me ", 4) == 0){
					message1 = "";
					message = my_strconcat((temp_user -> username), "");
					message = my_strconcat(message, &bufferi[3]);
					message = my_strconcat(message, "\n");
					my_str(message);
				}else if(my_strncmp(message, "/nick ", 6) == 0){
					message1 = "";
					message1 = my_strconcat(message1, &bufferi[6]);
					message = my_strconcat(temp_user->username," is now known as ");
					message = my_strconcat(message, message1);
					message = my_strconcat(message, "\n");
					temp_user->username = message1;
					my_str(message);
				}else if(my_strncmp(message, "/", 1) == 0){
					message = my_strconcat((temp_user -> username), " entered an invalid command.\n");
					my_str(my_strconcat(message, "\n"));
				}else{
					message = my_strconcat((temp_user -> username), ": ");
					message = my_strconcat(message, bufferi);
					message1 = my_strconcat(message, "\n");
					my_str(my_strconcat(message, "\n"));
				}
				
				for(j = 0; j < count_s_nodes(head); j++){
					temp_user = elem_at(head, j);
					t = temp_user -> fd;
					k = write(t, message, (my_strlen(message)));
					if(k < 0){
						error("error: there was an issue writing.");
					}
				}
			}
		}
	}
	close(sockfd);
	return 0;
}