#pragma once

#include <memory>
#include <string>

#include "facade/Subsystem.hpp"

namespace dp::facade {

class RequestFacade {
 public:
  explicit RequestFacade(
      std::unique_ptr<Backend> backend = std::make_unique<Backend>());

  /// One call hides the whole workflow
  bool send(const std::string& user, const std::string& payload) const;

 private:
  Validator validator_;
  Authenticator authenticator_;
  AuditLog log_;
  std::unique_ptr<Backend> backend_;
};

}  // namespace dp::facade
