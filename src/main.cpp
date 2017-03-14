#include <stdio.h>
#include <string.h>
#include "httpServer.hpp"


int main() {
  char PORT[6];
  strcpy(PORT, "8090");
  httpServer::createHttpServer(PORT);
  return 0;
}
