#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc < 3) {
        std::cerr << "usage " << argv[0] << " hostname port" << std::endl;
        exit(0);
    }
    portno = atoi(argv[2]);
    while (true) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) 
            error("ERROR opening socket");
        server = gethostbyname(argv[1]);
        if (server == NULL) {
            std::cerr << "ERROR, no such host" << std::endl;
            exit(0);
        }
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, 
             (char *)&serv_addr.sin_addr.s_addr,
             server->h_length);
        serv_addr.sin_port = htons(portno);
        if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
            error("ERROR connecting");
        std::cout << "Please enter the message: ";
        bzero(buffer,256);
        std::cin.getline(buffer,255);
        n = write(sockfd,buffer,strlen(buffer));
        if (n < 0) 
             error("ERROR writing to socket");
        bzero(buffer,256);
        n = read(sockfd,buffer,255);
        if (n < 0) 
             error("ERROR reading from socket");
        std::cout << buffer << std::endl;
        close(sockfd);
    }
    return 0;
}

