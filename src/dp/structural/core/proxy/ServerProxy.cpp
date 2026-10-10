#include "ServerProxy.hpp"

#include "lab/Logger.h"

namespace dp::proxy {

void ServerProxy::request(const std::string& user) {
  if (!has_access(user)) {
    LOG_S("    Proxy: access denied for " << user);
    return;
  }

  if (!server_) {
    LOG("    Proxy: first authorized request, creating the Server now");
    server_ = std::make_unique<Server>();
  }

  server_->request(user);
  ++requests_;
  LOG_S("    Proxy: logged request #" << requests_);
}

bool ServerProxy::has_access(const std::string& user) {
  return user == "admin";
}

}  // namespace dp::proxy
