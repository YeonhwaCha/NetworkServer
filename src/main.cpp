#include <stdio.h>
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
 
  strcpy(PORT, "8090");

  if (Server.createHttpServer(PORT) != -1) {
    printf("create server success!!\n");
  }

  while(1) {
    addrlen = sizeof(clientaddr);
    
  }

  return 0;
}
