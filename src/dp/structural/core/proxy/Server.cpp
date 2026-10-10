#include "Server.hpp"

#include "lab/Logger.h"

namespace dp::proxy {

Server::Server() {
  LOG("    Server: expensive construction (connect, load data...)");
}

void Server::request(const std::string& user) {
  LOG_S("    Server: handling request of " << user);
}

}  // namespace dp::proxy
