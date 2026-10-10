#include "SmsDecorator.hpp"

#include "lab/Logger.h"

namespace dp::decorator {

void SmsDecorator::send(const std::string& message) const {
  NotifierDecorator::send(message);
  LOG_S("    sms  : " << message);
}

}  // namespace dp::decorator
