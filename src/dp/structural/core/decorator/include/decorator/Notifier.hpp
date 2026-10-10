#pragma once

#include <string>

namespace dp::decorator {

/// Component
class Notifier {
 public:
  virtual ~Notifier() = default;

  virtual void send(const std::string& message) const = 0;
};

}  // namespace dp::decorator
