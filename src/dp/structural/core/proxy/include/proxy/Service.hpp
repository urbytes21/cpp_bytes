#pragma once

#include <string>

namespace dp::proxy {

/// Subject
class Service {
 public:
  virtual ~Service() = default;

  virtual void request(const std::string& user) = 0;
};

}  // namespace dp::proxy
