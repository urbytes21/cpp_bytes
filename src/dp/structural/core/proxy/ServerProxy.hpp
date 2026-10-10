#pragma once

#include <memory>
#include <string>

#include "Server.hpp"
#include "proxy/Service.hpp"

namespace dp::proxy {

/// Proxy: lazy creation + access control + logging
class ServerProxy : public Service {
 public:
  void request(const std::string& user) override;

 private:
  static bool has_access(const std::string& user);

  std::unique_ptr<Server> server_;  // created on demand
  int requests_{0};
};

}  // namespace dp::proxy
