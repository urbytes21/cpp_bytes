#include "proxy/ServiceFactory.hpp"

#include <memory>

#include "Server.hpp"
#include "ServerProxy.hpp"

namespace dp::proxy {

std::unique_ptr<Service> make_server() {
  return std::make_unique<Server>();
}

std::unique_ptr<Service> make_server_proxy() {
  return std::make_unique<ServerProxy>();
}

}  // namespace dp::proxy
