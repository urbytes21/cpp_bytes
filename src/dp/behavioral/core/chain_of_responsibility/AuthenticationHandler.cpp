#include "AuthenticationHandler.hpp"

#include "lab/Logger.h"

namespace dp::chain_of_responsibility {

void AuthenticationHandler::handle(const Request& request) const {
  if (request.token != "secret") {
    LOG_S("  [auth] rejected " << request.path << " (invalid token)");
    return;  // not forwarded
  }

  Handler::handle(request);
}

}  // namespace dp::chain_of_responsibility
