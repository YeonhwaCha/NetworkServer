#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h> //relate socklen_t
#include <netinet/in.h> //relate sockaddr_in
#include "httpServer.hpp"

int main() {
  char PORT[6];
  HttpServer Server;
  int clients[Server.CONNMAX];
  struct sockaddr_in clientaddr;
  socklen_t addrlen;
  char buffer[256]; //I wonder if fixed array size is good??
  int numOfReadWrite;

  strcpy(PORT, "8090");

  if (Server.createHttpServer(PORT) != -1) {
    printf("create server success!!\n");
  }

  while(1) {
    addrlen = sizeof(clientaddr);
    //[step3] accept()
    clients[slot] = accept(Server.listenfd, (struct sockaddr *) &clientaddr, &addrlen);

    if (clients[slot] < 0) {
      printf("There is no client\n");
    } else {
      bzero(buffer, 256);
      //read()
      numOfReadWrite = read(clients[slot], buffer, 255);

      if (numOfReadWrite < 0) {
	printf("read error : reading from socket\n");
      } else {
	printf("[read] :: %s\n", buffer);
      }
      //read() end

      //write()
      numOfReadWrite = write(clients[slot], "I got your message", 18);

      if (numOfReadWrite < 0) {
	printf("write error : writing from socket\n");
      } else {
	close(clients[slot]);
	close(Server.listenfd);
      }
      //write() end
      
    }

    while (clients[slot] != -1) {
      slot = (slot+1)%Server.CONNMAX;
    }
  }

  return 0;
}
