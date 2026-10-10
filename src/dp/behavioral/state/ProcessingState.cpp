#include "ProcessingState.hpp"

#include "state/Device.hpp"
#include "state/DeviceStateFactory.hpp"
#include "lab/Logger.h"

namespace dp::state {

std::string ProcessingState::name() const {
  return "Processing";
}

void ProcessingState::handle(Device& device) {
  const int job = device.startJob();
  const bool failed = job % 3 == 0;  // every third job fails in this simulation
  LOG_S("  [Processing] job " << job << (failed ? " failed" : " done"));
  if (failed) {
    device.transitionTo(makeErrorState());
  } else {
    device.transitionTo(makeIdleState());
  }
}

}  // namespace dp::state
