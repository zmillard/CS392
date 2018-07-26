#include "my.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <ncurses.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){
    int sockfd, portno, n, ch, i;
    struct sockaddr_in serv_addr;
    struct hostent *server;
  	char bufferi[1024];
  	char buffero[1024];
    char* user;
  	fd_set readfds;
	FD_ZERO(&readfds);
	initscr();
	raw();
	
	/*i = 0;*/

    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    my_str("Username: ");
    n = read(0, bufferi, 1024);
    user = my_strdup(bufferi);


    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0); /*opens connection*/
    if (sockfd < 0){
      error("ERROR opening socket");
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    memset((char *) &serv_addr, 0, sizeof(serv_addr)); /*b0*/
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
        error("ERROR connecting");
	  }

    write(sockfd,user,n-1);
	FD_SET(0, &readfds);
	FD_SET(sockfd, &readfds);
	start_color();
	init_pair(1, COLOR_RED, 0);
	init_pair(2, COLOR_BLUE, 0);
	while(1){
		FD_ZERO(&readfds);
		FD_SET(0, &readfds);
		FD_SET(sockfd, &readfds);

		select( sockfd+1 , &readfds , NULL, NULL , NULL);

		if(FD_ISSET(sockfd, &readfds)){
			bzero(buffero, 1040);
			attron(COLOR_PAIR(2));
			if((n = read(sockfd,buffero,1040))<=0){
				error("Server closed. Exiting...");
			}

			if(my_strcmp(my_strdup(buffero), "/close") == 0){
				my_str("Exiting the server...\n");
				close(sockfd);
				break;
			}
			my_str(buffero);
			my_char('\n');
				
			
		}

		if(FD_ISSET(0,&readfds)){
			bzero(bufferi,1024);
			attron(COLOR_PAIR(1));
			
			for (;;){
				ch = getch();
				if(ch == 3){
					endwin();
					return 0;
				}
				if(ch == 10){
					break;
				}
				if(ch >= 32 && ch < 127){
					bufferi[i] = ch;
					i++;
				}
			}
			n = read(0,bufferi,1024);
			bufferi[n-1] = '\0';
			
			/*if(ch == 13){*/
				/*for (n = 0; n < my_strlen(bufferi); n++){
					i = " ";
					i = i-2;
				}*/
			/*}*/
			/*start_color();
			init_pair(1, COLOR_RED, 0);
			attron(COLOR_PAIR(1));*/
			n = write(sockfd,bufferi,my_strlen(bufferi)+1);
			/*attroff(COLOR_PAIR(1));	*/
			
		}
	}
	noraw();
	endwin();
	return 0;
} /*if it reads /close, then close and break*/
