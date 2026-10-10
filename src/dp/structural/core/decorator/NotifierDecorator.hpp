#pragma once

#include <memory>
#include <string>

#include "decorator/Notifier.hpp"

namespace dp::decorator {

/// Base decorator: same interface, forwards to the wrapped object
class NotifierDecorator : public Notifier {
 public:
  explicit NotifierDecorator(std::unique_ptr<Notifier> wrapped);

  void send(const std::string& message) const override;

 private:
  std::unique_ptr<Notifier> wrapped_;
};

}  // namespace dp::decorator
