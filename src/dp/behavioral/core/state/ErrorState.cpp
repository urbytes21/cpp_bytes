#include "ErrorState.hpp"

#include "state/Device.hpp"
#include "state/DeviceStateFactory.hpp"
#include "lab/Logger.h"

namespace dp::state {

std::string ErrorState::name() const {
  return "Error";
}

void ErrorState::handle(Device& device) {
  LOG("  [Error] resetting the device");
  device.transitionTo(makeIdleState());
}

}  // namespace dp::state
