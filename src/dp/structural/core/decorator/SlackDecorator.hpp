#pragma once

#include <string>

#include "NotifierDecorator.hpp"

namespace dp::decorator {

/// Adds a Slack message after forwarding
class SlackDecorator : public NotifierDecorator {
 public:
  using NotifierDecorator::NotifierDecorator;

  void send(const std::string& message) const override;
};

}  // namespace dp::decorator
