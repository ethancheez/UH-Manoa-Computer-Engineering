/*
** client.c -- a stream socket client demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <arpa/inet.h>

#define PORT "3503" // the port client will be connecting to 

#define MAXDATASIZE 100 // max number of bytes we can get at once 

#define FLUSH while(getchar() != '\n');

// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
	if (sa->sa_family == AF_INET) {
		return &(((struct sockaddr_in*)sa)->sin_addr);
	}

	return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[])
{
	int sockfd, numbytes;  
	char buf[MAXDATASIZE];
	struct addrinfo hints, *servinfo, *p;
	int rv;
	char s[INET6_ADDRSTRLEN];

	if (argc < 2) {
	    fprintf(stderr,"usage: client hostname\n");
	    exit(1);
	}

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;

	if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
		return 1;
	}

	while(1) {

		// loop through all the results and connect to the first we can
		for(p = servinfo; p != NULL; p = p->ai_next) {
			if ((sockfd = socket(p->ai_family, p->ai_socktype,
					p->ai_protocol)) == -1) {
				perror("client: socket");
				continue;
			}

			if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
				perror("client: connect");
				close(sockfd);
				continue;
			}

			break;
		}

		if (p == NULL) {
			fprintf(stderr, "client: failed to connect\n");
			return 2;
		}

		inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
				s, sizeof s);
		//printf("client: connecting to %s\n", s);

		/* -------------------------------------------------- Aloha Exercise
		char *msg = argv[2];

		if (send(sockfd, msg, sizeof(msg), 0) == -1) {
			perror("send");
			exit(1);
		}
			
		printf("Client Sent: '%s'\n", msg);

		if ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
			perror("recv");
			exit(1);
		}

		printf("Client Received: '%s'\n", buf);

		----------------------------------------------------------------- */

		char input;
		char fileName[MAXDATASIZE];
		memset(buf, '\0', sizeof(buf));

		printf("Enter Command (type 'h' for help): ");
		fgets(buf, MAXDATASIZE, stdin);
		sscanf(buf, "%c %s", &input, fileName);

		if (send(sockfd, buf, MAXDATASIZE-1, 0) == -1) {
			perror("send");
			//printf("DEBUG test");
		}

		system("clear");

		switch(input) {
			case 'l':
				printf("Directory Contents:\n");
			case 'c':
			case 'p':
				while ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) > 0) {
					buf[numbytes] = '\0';
	    			printf("%s",buf);
				}
				printf("\n");
				close(sockfd);
				break;
			case 'd':
				;FILE *file = NULL;
				if(file = fopen(fileName, "r")) {
					printf("File '%s' already exists in this directory. Would you like to overwrite it? (y/n)\n", fileName);
					fgets(buf, MAXDATASIZE, stdin);
					sscanf(buf, "%c", &input);

					while(input != 'y' && input != 'n') {
						printf("Please enter a valid option. (y/n) \n");
						fgets(buf, MAXDATASIZE, stdin);
						sscanf(buf, "%c", &input);
					}
					if(input == 'y') {
						printf("File '%s' overwritten.\n", fileName);
						file = fopen(fileName, "w+");
						while ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) > 0) {
							buf[numbytes] = '\0';
	    					fputs(buf, file);
						}
						fclose(file);
					}
				} else {
					numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0);
					buf[numbytes] = '\0';
					//printf("DEBUG: %s\n", buf);
					if(strstr(buf, "' not found") != NULL) {
						printf("%s\n", buf);
					} else {
						printf("File '%s' downloaded.\n", fileName);
						file = fopen(fileName, "w+");
						fputs(buf, file);
						while ((numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0)) > 0) {
							buf[numbytes] = '\0';
							fputs(buf, file);
						}
						fclose(file);
					}
				}
				close(sockfd);
				break;
			case 'q':
				close(sockfd);
				freeaddrinfo(servinfo);
				return 0;
			default:
				printf("List of Commands:\n");
				printf("\tl: List\n");
				printf("\tc: Check <file name>\n");
				printf("\tp: Display <file name>\n");
				printf("\td: Download <file name>\n");
				printf("\tq: Quit\n");
				printf("\th: Help\n");
		}
	}

	close(sockfd);
	freeaddrinfo(servinfo); // all done with this structure

	return 0;
}

