#include "NotifierDecorator.hpp"

#include <utility>

namespace dp::decorator {

NotifierDecorator::NotifierDecorator(std::unique_ptr<Notifier> wrapped)
    : wrapped_{std::move(wrapped)} {}

void NotifierDecorator::send(const std::string& message) const {
  wrapped_->send(message);
}

}  // namespace dp::decorator
