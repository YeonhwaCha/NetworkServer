//
// #httpServer.cpp
//
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include "httpServer.hpp"

int httpServer::createHttpServer(char *port) {

  printf("create HTTP Server\n");
  
  struct addrinfo hints, *res;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;       //choose a AF_INET(IPv4) /  AF_INET6(IPv6) / AF_UNSPEC
  hints.ai_socktype = SOCK_STREAM;   //choose a SOCK_STREAM or SOCK_DGRAM

  //[reference] https://www.joinc.co.kr/w/man/3/getaddrinfo
  //you can see getaddrinfo() when you type 'man getaddrinfo' on terminal
  //int getaddrinfo( const char *node,
  //                 const char * service,
  //                 const struct addrinfo *hints,
  //                 struct addrinfo **res)
  //return : success == 0 , fail != 0
  if (getaddrinfo(NULL, port, &hints, &res) != 0) {
    printf("getaddrinfo is failed..\n");
    return -1;
  }

  return 0;
}
