#include "SlackDecorator.hpp"

#include "lab/Logger.h"

namespace dp::decorator {

void SlackDecorator::send(const std::string& message) const {
  NotifierDecorator::send(message);
  LOG_S("    slack: " << message);
}

}  // namespace dp::decorator
