//
// 2017.7.15 
// main.cpp
// use : server.out {ip} {port}

#include <stdio.h>
#include <string.h>
#include <sys/socket.h> //relate socklen_t
#include <netinet/in.h> //relate sockaddr_in
#include "httpServer.hpp"

int main(int argc, char* argv[]) {

	printf("use : ./server.out {ip address} {port}\n");

	HttpServer Server;

	if(Server.createHttpServer(argv[1], argv[2])!=-1) {
		printf("create server successfully.. \n");
	}

  return 0;
}
