#pragma once

#include <string>

#include "proxy/Service.hpp"

namespace dp::proxy {

/// Real subject: expensive to create
class Server : public Service {
 public:
  Server();

  void request(const std::string& user) override;
};

}  // namespace dp::proxy
