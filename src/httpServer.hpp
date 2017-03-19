//
// #http server.hpp
//
#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

class HttpServer {
public:
  HttpServer();
  ~HttpServer();
  //variable
  static const int CONNMAX = 1000;
  
  //method
  int  createHttpServer(char *port);
  void respond(int n);

private:
  int listenfd;
};

#endif
