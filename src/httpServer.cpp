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

HttpServer::HttpServer() {
}

HttpServer::~HttpServer() {
}

int HttpServer::createHttpServer(char *port) {

  printf("start create HTTP Server >>>>>>>>>>>>\n");

  struct addrinfo hints, *result, *rp;

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
  if (getaddrinfo(NULL, port, &hints, &result) != 0) {
    printf("getaddrinfo is failed..\n");
    return -1;
  }

  for (rp = result ; rp != NULL; rp = rp->ai_next) {
    //[step1] socket()
    listenfd = socket(rp->ai_family, rp->ai_socktype, 0);
    if (listenfd == -1)
      continue;
    //[step2] bind()
    if (bind(listenfd, rp->ai_addr, rp->ai_addrlen) == 0)
      break;
  }

  if (rp == NULL) {
    return -1;
  }

  freeaddrinfo(result);

  //[reference] http://man7.org/linux/man-pages/man2/listen.2.html
  //int listen(int sockfd, int backlog)
  //The sockfd argument is a file descriptor that refers to a socket of type SOCK_STREAM or SOCK_SEQPACKET
  //The backlog argument defines the maximum length to which the queue of pending connections for sockfd may grow.
  //[step3] listen()
  if (listen(listenfd, 10) != 0) {
    printf("listen error : maximum backlog length is 10\n");
    return -1;
  }
 
  return 0;
}
