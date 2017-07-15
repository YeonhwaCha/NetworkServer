//
// #httpServer.hpp
//
#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

class HttpServer {
public:
	// HttpServer();
	// ~HttpServer();
  
  	//variable
  
  	//method
  	int createHttpServer(char *ip_addr, char *port);
	//void run();

private:
	//variable
	char buffer[256];
	int clients[1000];
	int listenfd;
	int numOfReadWrite;
	int slot;
	socklen_t addrlen;
	struct sockaddr_in clientaddr;

	//method
	void do_accept();
};

#endif
