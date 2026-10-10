#include "FakeBackend.hpp"

#include "lab/Logger.h"

namespace dp::facade {

void FakeBackend::send(const std::string& payload) const {
  LOG_S("    FakeBackend: pretended to send " << payload);
}

}  // namespace dp::facade
