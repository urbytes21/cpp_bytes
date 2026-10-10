#pragma once

#include <string>

#include "NotifierDecorator.hpp"

namespace dp::decorator {

/// Adds an SMS after forwarding
class SmsDecorator : public NotifierDecorator {
 public:
  using NotifierDecorator::NotifierDecorator;

  void send(const std::string& message) const override;
};

}  // namespace dp::decorator
