#include "procesy.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define PORT     8080 

void *
getmsg_1_svc(message *argp, struct svc_req *rqstp)
{
	static char * result;
	int sockfd; 
    char hexa [128];
    struct sockaddr_in servaddr; 
    
	int i=0;
	for(i=0; argp->value[i] != '\0' && i < 64; i++)
		sprintf(hexa+2*i, "%.2x", argp->value[i]);
    
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
    
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
    int n, len; 
      
    sendto(sockfd, (const char *)hexa, strlen(hexa), 
        MSG_CONFIRM, (const struct sockaddr *) &servaddr,  
            sizeof(servaddr)); 
  
    close(sockfd); 

	return (void *) &result;
}
