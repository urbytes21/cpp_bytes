#include "chain_of_responsibility/HandlerFactory.hpp"

#include <memory>
#include <utility>

#include "AuthenticationHandler.hpp"
#include "LoggingHandler.hpp"
#include "MethodHandler.hpp"

namespace dp::chain_of_responsibility {

std::unique_ptr<Handler> make_authentication_handler() {
  return std::make_unique<AuthenticationHandler>();
}

std::unique_ptr<Handler> make_logging_handler() {
  return std::make_unique<LoggingHandler>();
}

std::unique_ptr<Handler> make_method_handler(std::string method) {
  return std::make_unique<MethodHandler>(std::move(method));
}

}  // namespace dp::chain_of_responsibility
