#include "LoggingHandler.hpp"

#include "lab/Logger.h"

namespace dp::chain_of_responsibility {

void LoggingHandler::handle(const Request& request) const {
  LOG_S("  [log]  " << request.method << ' ' << request.path);
  Handler::handle(request);
}

}  // namespace dp::chain_of_responsibility
