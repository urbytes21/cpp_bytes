#include "facade/Subsystem.hpp"

#include "lab/Logger.h"

namespace dp::facade {

bool Validator::check(const std::string& payload) const {
  const bool ok = !payload.empty();
  LOG_S("    Validator: payload " << (ok ? "is valid" : "is empty"));
  return ok;
}

bool Authenticator::login(const std::string& user) const {
  LOG_S("    Authenticator: login " << user);
  return user != "guest";
}

void AuditLog::write(const std::string& entry) const {
  LOG_S("    AuditLog: " << entry);
}

void Backend::send(const std::string& payload) const {
  LOG_S("    Backend: POST " << payload);
}

}  // namespace dp::facade
