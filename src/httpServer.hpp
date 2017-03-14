//
// #http server.hpp
//
#ifndef HTTP_SERVER_HPP
#define HTTP_SERVER_HPP

class httpServer {
public:
  httpServer();
  ~httpServer();

  static int createHttpServer(char *port);
};

#endif
