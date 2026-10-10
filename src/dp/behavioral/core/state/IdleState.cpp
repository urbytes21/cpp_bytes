#include "IdleState.hpp"

#include "state/Device.hpp"
#include "state/DeviceStateFactory.hpp"
#include "lab/Logger.h"

namespace dp::state {

std::string IdleState::name() const {
  return "Idle";
}

void IdleState::handle(Device& device) {
  LOG("  [Idle] new job arrived");
  device.transitionTo(makeProcessingState());
}

}  // namespace dp::state
