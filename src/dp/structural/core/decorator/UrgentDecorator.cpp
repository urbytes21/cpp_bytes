#include "UrgentDecorator.hpp"

namespace dp::decorator {

void UrgentDecorator::send(const std::string& message) const {
  NotifierDecorator::send("[URGENT] " + message);
}

}  // namespace dp::decorator
