#pragma once

#include <string>

#include "decorator/Notifier.hpp"

namespace dp::decorator {

/// Concrete component
class EmailNotifier : public Notifier {
 public:
  void send(const std::string& message) const override;
};

}  // namespace dp::decorator
