#include "EmailNotifier.hpp"

#include "lab/Logger.h"

namespace dp::decorator {

void EmailNotifier::send(const std::string& message) const {
  LOG_S("    email: " << message);
}

}  // namespace dp::decorator
