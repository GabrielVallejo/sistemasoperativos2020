#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
extern int h_errno;
#include <strings.h>
#include <string.h>
#include <unistd.h>

void bzero(void *s, size_t n);

int main(int argc, char **argv){
    char *ip = argv[1];
	char *puerto = argv[2];
	char *nickname = argv[3];
    char *c;
	printf("%s \n", puerto);
    struct sockaddr_in serverAddress;
    struct hostent *serverInfo = gethostbyname(ip);

    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(atoi(puerto));
    bcopy((char *)serverInfo->h_addr, 
    (char *)&serverAddress.sin_addr.s_addr, serverInfo->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(connect(sockfd,&serverAddress,sizeof(serverAddress)) < 0){
       printf("Error \n"); 
    };
    char *message = "GET / HTTP/1.0\r\n\r\n";
    write(sockfd, nickname, strlen(nickname));
    while(read(sockfd,&c,250)){
        printf("%s \n",c);
    }
    close(sockfd);
    printf("\n");
    return 0;
}