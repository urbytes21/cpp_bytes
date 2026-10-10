#include <string>

#include "proxy/Service.hpp"
#include "proxy/ServiceFactory.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::proxy;

namespace {

void client_code(Service& service, const std::string& user) {
  LOG_S("  client: request as " << user);
  service.request(user);
}

void problem() {
  LOG_SECTION("Problem: the real object is created up front");

  auto server = make_server();  // paid for even if nobody uses it
  client_code(*server, "admin");
  client_code(*server, "guest");  // no access control, no logging
}

void with_proxy() {
  LOG_SECTION("Proxy: same interface, controlled access");

  auto proxy = make_server_proxy();
  LOG("  proxy constructed - no Server exists yet");
  client_code(*proxy, "guest");  // denied, the Server is still not created
  client_code(*proxy, "admin");  // creates the Server lazily
  client_code(*proxy, "admin");  // reuses it
}

}  // namespace

LAB_EXAMPLE("Proxy",
            "a stand-in that adds lazy creation, access control and logging") {
  problem();
  with_proxy();
}
