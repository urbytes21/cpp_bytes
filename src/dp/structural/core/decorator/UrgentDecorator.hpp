#pragma once

#include <string>

#include "NotifierDecorator.hpp"

namespace dp::decorator {

/// Changes the message itself before forwarding
class UrgentDecorator : public NotifierDecorator {
 public:
  using NotifierDecorator::NotifierDecorator;

  void send(const std::string& message) const override;
};

}  // namespace dp::decorator
