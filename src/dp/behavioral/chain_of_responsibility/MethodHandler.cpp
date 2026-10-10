#include "MethodHandler.hpp"

#include <utility>

#include "lab/Logger.h"

namespace dp::chain_of_responsibility {

MethodHandler::MethodHandler(std::string method) : method_{std::move(method)} {}

void MethodHandler::handle(const Request& request) const {
  if (request.method == method_) {
    LOG_S("  [" << method_ << "]  handled " << request.path);
    return;
  }

  Handler::handle(request);
}

}  // namespace dp::chain_of_responsibility
