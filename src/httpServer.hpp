//
// #httpServer.hpp
//
#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

class HttpServer {
public:
  HttpServer();
  ~HttpServer();
  
  //variable
  static const int CONNMAX = 1000;
  int listenfd;
  
  //method
  int createHttpServer(char *port);

private:
  //int listenfd;
};

#endif
