#include "Adaptee.hpp"

#include "lab/Logger.h"

namespace dp::adapter {

void Adaptee::specific_request(int code) const {
  LOG_S("    Adaptee::specific_request(" << code << ")");
}

}  // namespace dp::adapter
