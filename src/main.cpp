#include <stdio.h>
#include <string.h>
#include "httpServer.hpp"

int main() {
  struct sockaddr_in clientaddr;
  char PORT[6];
  strcpy(PORT, "8090");

  if (httpServer::createHttpServer(PORT) != -1) {
    printf("create server success!!\n");
  }

  while(1) {
    
  }

  return 0;
}
